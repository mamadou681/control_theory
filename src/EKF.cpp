#include "EKF.h"

#include <cmath>

EKF::EKF(QObject *parent)
    : QObject{parent}
{
//    initialize(dt);
}

void EKF::initialize(const double dt)
{
    // seconds of time-step .....................
    setDeltaT(dt);

    // Initialize process matrix ................
    Q.setZero();
    for (int i=0; i<7; ++i){
        if(i <=3) {
            Q(i, i) = 0.05; //quaternion noise q0, q1, q2, q3
        } else {
            Q(i, i) = 0.01; // bias noise bx, by, bz
        }
    }

    // Initialize measurement matrix ..................
    R.setZero();
    for(int i=0;  i< 3; ++i){
        R(i,i) = 0.02; //accelerometer measurement noise ax, ay, az
    }

    // Initialize the state .....................
    double psi = 0.0;   // yaw
    double theta = 0.0; // pitch
    double phi = 0.0;   // roll

    Eigen::Vector3d euler(psi, theta, phi);
    Eigen::Vector4d q = Euler321_to_quaternion(euler);

    x(0) = q(0); // q0
    x(1) = q(1); // q1
    x(2) = q(2); // q2
    x(3) = q(3); // q3

    x(4) = 0.0; // bx
    x(5) = 0.0; // by
    x(6) = 0.0; // bz

    //Initialize the state Covariance..............
    P = 0.0001*P.setIdentity();

}

Eigen::Vector4d EKF::Euler321_to_quaternion(const Eigen::Vector3d &euler)
{
    double c1 = std::cos(euler(0) / 2.0); // psi (yaw)
    double s1 = std::sin(euler(0) / 2.0);

    double c2 = std::cos(euler(1) / 2.0); // theta (pitch)
    double s2 = std::sin(euler(1) / 2.0);

    double c3 = std::cos(euler(2) / 2.0); // phi (roll)
    double s3 = std::sin(euler(2) / 2.0);

    Eigen::Vector4d q;
    q(0) = c1 * c2 * c3 + s1 * s2 * s3; // q0 (scalar part)
    q(1) = c1 * c2 * s3 - s1 * s2 * c3; // q1
    q(2) = c1 * s2 * c3 + s1 * c2 * s3; // q2
    q(3) = s1 * c2 * c3 - c1 * s2 * s3; // q3

    return q;
}

void EKF::setDeltaT(double deltaT)
{
    dt = deltaT;
}

Eigen::Matrix4d EKF::getOmegaMatrix(const Eigen::Vector3d &omega)
{
    Eigen::Matrix4d omega_matrix;
    omega_matrix << 0.0, -omega[0], -omega[1], -omega[2],
            omega[0], 0.0, omega[2], -omega[1],
            omega[1], -omega[2], 0.0, omega[0],
            omega[2], omega[1], -omega[0], 0.0;

    return omega_matrix;
}

void EKF::normalizeQuaternion()
{
    x.segment<4>(0).normalize();
}

Eigen::Matrix3d EKF::quaterionToRotationMatrix(Eigen::Vector4d &q)
{
    Eigen::Matrix3d rotationMatrix;
    rotationMatrix << 1.0 - 2*(q[2]*q[2] + q[3]*q[3]), 2*(q[1]*q[2] - q[0]*q[2]), 2*(q[1]*q[3] + q[0]*q[2]),
            2*(q[1]*q[2] - q[0]*q[3]), 1 - 2*(q[1]*q[1] + q[3]*q[3]), 2*(q[2]*q[3] - q[0]*q[1]),
            2*(q[1]*q[3] - q[0]*q[2]), 2*(q[2]*q[3] + q[0]*q[1]), 1 - 2*(q[1]*q[1] + q[2]*q[2]);

    return rotationMatrix;
}

void EKF::predict(const Eigen::Vector3d &gyro)
{
    // Compute bias-compensated angular velocity (rad/s)
    Eigen::Vector3d bias = x.segment<3>(4);
    Eigen::Vector3d omega = gyro - bias;

    // Quaternion derivative: dq = 0.5 * Omega * q
    Eigen::Vector4d q = x.segment<4>(0);
    Eigen::Vector4d dq = 0.5 * getOmegaMatrix(omega) * q;

    // Euler integration: advance quaternion by dt (Update state with new quaternion)
    x.segment<4>(0) += dq * dt;

    // Normalize quaternion to maintain unit-norm
    normalizeQuaternion();

    // Compute the state transition Jacobian matrix F analytically
    Eigen::Matrix<double, 7, 7> F = computeFJacobian(gyro);

    // Propagate covariance: P = F * P * Fᵀ + Q
    P = F * P * F.transpose() + Q;
}

void EKF::update(const Eigen::Vector3d &accel)
{
    // Define gravity in the Earth frame (NED), positive down
    Eigen::Vector3d gravity(0.0, 0.0, -GRAVITY);

    Eigen::Vector4d q = x.segment<4>(0);

    // Compute expected accelerometer measurement: h(x) = R(q)ᵀ*g
    // (Rᵀ rotates gravity from Earth to body frame)
    auto& expected_accel = quaterionToRotationMatrix(q).transpose() * gravity;


    // Actual measurement vector from accelerometer
    Eigen::Vector3d z(accel[0], accel[1], accel[2]);
    // Innovation (residual): difference between measured and expected accel
    //yk = z - h(x)
    auto innovation = z - expected_accel;

    // Compute Jacobian H = ∂h/∂x (3×7), describes how accel measurement changes w.r.t. state
    Eigen::Matrix<double, 3, 7> H = computeHJacobian();

    // Innovation covariance: S = H*P*Hᵀ + R
    Eigen::Matrix3d S = H*P*H.transpose() + R;

    //Kalman gain: K = P*Hᵀ*S⁻¹
    Eigen::Matrix<double, 7, 3> K = P*H.transpose()*S.inverse();

    //State update: X = X + K(z-h(x))
    x+= K*innovation;

    //Covariance update: P = (I - K*H)*P
    P = (Eigen::Matrix<double, 7,7>::Identity() - K*H)*P;


}

Eigen::Vector3d EKF::Quaternion_to_Euler321(const Eigen::Vector4d &q)
{
    double q0 = q(0);
    double q1 = q(1);
    double q2 = q(2);
    double q3 = q(3);

    Eigen::Vector3d e;
    // yaw (psi)
    e(0) = std::atan2(2.0 * (q1 * q2 + q0 * q3),
                      q0 * q0 + q1 * q1 - q2 * q2 - q3 * q3);

    // pitch (theta)
    e(1) = std::asin(-2.0 * (q1 * q3 - q0 * q2));

    // roll (phi)
    e(2) = std::atan2(2.0 * (q2 * q3 + q0 * q1),
                      q0 * q0 - q1 * q1 - q2 * q2 + q3 * q3);

    return e; // [yaw, pitch, roll] in radians
}

Eigen::Vector3d EKF::apply(Eigen::Vector3d &gyro, Eigen::Vector3d &accel)
{
    // prediction
    predict(gyro);

    // correction
    update(accel);

    // return euler angles
    return Quaternion_to_Euler321(x.segment<4>(0));
}

Eigen::Matrix<double, 7, 7> EKF::computeFJacobian(const Eigen::Vector3d &gyro)
{
    Eigen::Matrix<double, 7, 7> F = Eigen::Matrix<double, 7, 7>::Identity();

    Eigen::Vector3d bias = x.segment<3>(4);
    double p = gyro(0) - bias[0],
            q = gyro(1) - bias[1],
            r = gyro(2) - bias[2];

    // the top-left 4×4 block of F
    Eigen::Vector3d omega(p, q, r);
    F.topLeftCorner<4,4>() += 0.5 * dt * getOmegaMatrix(omega);

    // the top-right 4×3 block of F:
    Eigen::Matrix<double, 4, 3> G;
    Eigen::Vector4d qv = x.segment<4>(0);
    G << -qv(1), -qv(2), -qv(3),
            qv(0), -qv(3),  qv(2),
            qv(3),  qv(0), -qv(1),
            -qv(2),  qv(1),  qv(0);
    F.topRightCorner<4,3>() = -0.5 * dt * G;
    return F;
}

Eigen::Matrix<double, 3, 7> EKF::computeHJacobian() const
{
    Eigen::Vector4d q = x.segment<4>(0);
    double  q0 = q(0),
            q1 = q(1),
            q2 = q(2),
            q3 = q(3);

    Eigen::Matrix<double, 3, 7> H = Eigen::Matrix<double, 3, 7>::Zero();

    H(0, 0) = -2*GRAVITY*q2;
    H(0, 1) =  2*GRAVITY*q3;
    H(0, 2) = -2*GRAVITY*q0;
    H(0, 3) =  2*GRAVITY*q1;

    H(1, 0) = 2*GRAVITY*q1;
    H(1, 1) = 2*GRAVITY*q0;
    H(1, 2) = 2*GRAVITY*q3;
    H(1, 3) = 2*GRAVITY*q2;

    H(2, 0) =  2*GRAVITY*q0;
    H(2, 1) = -2*GRAVITY*q1;
    H(2, 2) = -2*GRAVITY*q2;
    H(2, 3) =  2*GRAVITY*q3;

    return H;
}
