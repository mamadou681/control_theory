#ifndef EKF_H
#define EKF_H

#include <QObject>

#include <Eigen/Dense>

class EKF : public QObject
{
    Q_OBJECT
public:
    explicit EKF(QObject *parent = nullptr);

    void initialize(const double dt);
    // Converts Euler angles (yaw-pitch-roll, 3-2-1 order) to Euler parameters (quaternion, scalar-first)
    Eigen::Vector4d Euler321_to_quaternion(const Eigen::Vector3d& euler);

    void setDeltaT(double deltaT);
    Eigen::Matrix4d getOmegaMatrix(const Eigen::Vector3d& omega);
    void normalizeQuaternion();
    Eigen::Matrix3d quaterionToRotationMatrix(Eigen::Vector4d& q);
    void predict(const Eigen::Vector3d& gyro);
    void update(const Eigen::Vector3d& accel);
    // Converts scalar-first quaternion to 321 Euler angles [yaw; pitch; roll] in radians
    Eigen::Vector3d Quaternion_to_Euler321(const Eigen::Vector4d& q);

    Eigen::Vector3d apply(Eigen::Vector3d& gyro, Eigen::Vector3d& accel );

private:
    Eigen::Matrix<double, 7, 7> computeFJacobian(const Eigen::Vector3d& gyro);
    Eigen::Matrix<double, 3, 7> computeHJacobian() const;

    // Gravity constant
    const double GRAVITY = 9.80665;

    // Time step
    double dt;

    // State: [q0, q1, q2, q3, bx, by, bz]^T
    Eigen::Matrix<double, 7, 1> x;

    // Covariance
    Eigen::Matrix<double, 7, 7> P;

    // Process noise
    Eigen::Matrix<double, 7, 7> Q;

    // Measurement noise
    Eigen::Matrix3d R;
signals:

};

#endif // EKF_H
