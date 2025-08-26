#ifndef KALMANFILTER_H
#define KALMANFILTER_H

#include <QObject>

#include <Eigen/Dense>

class KalmanFilter : public QObject
{
    Q_OBJECT
    /*
     linear state model:
     State: Xk+1 = AXk + Wk
     Measurement: Zk+1 = HXk + Vk

     Xk = state variable (n x 1 column vector)
       n is the number of state variables
     Zk = measurement (m x 1 column vector)
        m is the number of measurement inputs
     A = state transition matrix (n x n matrix)
     H = state-to-measurement matrix (m x n)
     Wk = state transition noise (n X 1 column vector)
     Vk = measurement noise (m x 1 column vector)

     Covariance of the noise
     Q = Covariance matrix of Wk (n x n diagonal matrix)
     R = Covariance matrix of Vk (m x m diagonal matrix)

   */
public:
    explicit KalmanFilter(QObject *parent = nullptr);
    void initialize(const double deltaT);
    double apply(double measurement);

signals:
private:
    // Parameters
    double dt;  // Time step

    // System matrices
    Eigen::Matrix2d A;  // State transition matrix
    Eigen::Matrix<double, 1, 2> H;  // Measurement matrix
    Eigen::Matrix2d Q;  // Process noise covariance
    Eigen::Matrix<double, 1, 1> R;  // Measurement noise covariance

    // State variables
    Eigen::Vector2d x;  // State vector [position; velocity]
    Eigen::Matrix2d P;  // State covariance matrix

};

#endif // KALMANFILTER_H
