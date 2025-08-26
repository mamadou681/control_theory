#include "KalmanFilter.h"

KalmanFilter::KalmanFilter(QObject *parent)
    : QObject{parent}
{
//  initialize(0.02);
}

void KalmanFilter::initialize(const double deltaT)
{
    // Time step (sampling period in seconds)
    dt = deltaT;//0.02; // sec, for sonar

    // State transition matrix (A)
    // Models the physics of the system - how state evolves from step to step
    // This implements a constant velocity model:
    //   position_new = position_old + velocity_old*dt
    //   velocity_new = velocity_old
    A << 1, dt,  // Position depends on previous position and velocity
            0, 1;   // Velocity remains constant (no acceleration term)

    // Observation matrix (H)
    // Maps state to measurements - we only measure position directly
    H << 1, 0;  // We observe position (1st state) but not velocity (2nd state)

    // Process noise covariance (Q)
    // Represents uncertainty in our process model
    // Diagonal matrix where:
    //   Q(1,1) - position process noise (how much we trust position prediction)
    //   Q(2,2) - velocity process noise (how much we trust velocity prediction)
    // Larger values mean we trust measurements more than predictions
    Q << 1, 0,  // Position process noise variance
            0, 3;  // Velocity process noise variance (higher = more uncertainty)

    // Measurement noise covariance (R)
    // Represents uncertainty in our measurements (sonar accuracy)
    // Scalar since we have one measurement (position)
    R << 10;  // Measurement noise variance (higher = less trust in measurements)

    // Initial state vector [position; velocity]
    x << 0, 20;  // Starting at position 0 with velocity 20 units/sec

    // Initial state covariance matrix (P)
    // Represents our uncertainty about the initial state
    // Diagonal matrix where:
    //   P(1,1) - initial position uncertainty
    //   P(2,2) - initial velocity uncertainty
    P = 5 * Eigen::Matrix2d::Identity();  // Equal uncertainty for both states
}

double KalmanFilter::apply(double measurement)
{
    // Prediction step
    Eigen::Vector2d xp = A * x; // Predicted state
    Eigen::Matrix2d Pp = A * P * A.transpose() + Q; // Predicted covariance

    // Update step
    Eigen::Matrix<double, 1, 1> S = H * Pp * H.transpose() + R; //innovation covariance
    Eigen::Vector2d K = Pp * H.transpose() * S.inverse(); // Compute Kalman gain

    Eigen::Vector<double, 1> z;
    z << measurement;

    x = xp + K * (z - H * xp); // Update state
    P = Pp - K * H * Pp; // Update error covariance

    // results
    double position = x(0);
//    double velocity = x(1);
//    Eigen::Matrix2d covariance = P;

    return position;
}
