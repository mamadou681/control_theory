#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QApplication>
#include "qcustomplot.h"
#include "qcustomplot/QCustomplotWrapper.h"
#include "FilterManager.h"
//#include "QmlObjectListModel.h"

#include <Eigen/Dense>
#include <iostream>
#include <QDebug>

#include <cmath>  // for std::sin and std::cos

Eigen::Matrix<double, 7, 1> x;


// Converts Euler angles (yaw-pitch-roll, 3-2-1 order) to Euler parameters (quaternion, scalar-first)
Eigen::Vector4d Euler3212EP(const Eigen::Vector3d& euler)
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

Eigen::Matrix4d omegaMatrix(const Eigen::Vector3d& omega) {
    Eigen::Matrix4d omega_matrix;
    omega_matrix << 0.0, -omega[0], -omega[1], -omega[2],
            omega[0], 0.0, omega[2], -omega[1],
            omega[1], -omega[2], 0.0, omega[0],
            omega[2], omega[1], -omega[0], 0.0;

    return omega_matrix;
}

Eigen::Matrix<double, 7, 7> computeFJacobian(const Eigen::Vector3d& gyro) {
    Eigen::Matrix<double, 7, 7> F = Eigen::Matrix<double, 7, 7>::Identity();
    double dt = 0.01;

    Eigen::Vector3d bias = x.segment<3>(4);

    double p = gyro(0) - bias[0], q = gyro(1) - bias[1], r = gyro(2) - bias[2];

    // the top-left 4×4 block of F
    Eigen::Vector3d omega(p, q, r);
    F.topLeftCorner<4,4>() += 0.5 * dt * omegaMatrix(omega);

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


Eigen::Matrix3d quaterionToRotationMatrix(Eigen::Vector4d& q){

    Eigen::Matrix3d rotationMatrix;
    rotationMatrix << 1.0 - 2*(q[2]*q[2] + q[3]*q[3]), 2*(q[1]*q[2] - q[0]*q[2]), 2*(q[1]*q[3] + q[0]*q[2]),
            2*(q[1]*q[2] - q[0]*q[3]), 1 - 2*(q[1]*q[1] + q[3]*q[3]), 2*(q[2]*q[3] - q[0]*q[1]),
            2*(q[1]*q[3] - q[0]*q[2]), 2*(q[2]*q[3] + q[0]*q[1]), 1 - 2*(q[1]*q[1] + q[2]*q[2]);

    return rotationMatrix;

}

Eigen::Matrix<double, 3, 7> computeHJacobian() {
    const double gravity = 9.80665;

    Eigen::Vector4d q = x.segment<4>(0);
    double q0 = q(0),
            q1 = q(1),
            q2 = q(2),
            q3 = q(3);

    Eigen::Matrix<double, 3, 7> H = Eigen::Matrix<double, 3, 7>::Zero();

    H(0, 0) = -2*gravity*q2;
    H(0, 1) = 2*gravity*q3;
    H(0, 2) = -2*gravity*q0;
    H(0, 3) = 2*gravity*q1;

    H(1, 0) = 2*gravity*q1;
    H(1, 1) = 2*gravity*q0;
    H(1, 2) = 2*gravity*q3;
    H(1, 3) = 2*gravity*q2;

    H(2, 0) = 2*gravity*q0;
    H(2, 1) = -2*gravity*q1;
    H(2, 2) = -2*gravity*q2;
    H(2, 3) = 2*gravity*q3;

    return H;
}
int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    //    QGuiApplication app(argc, argv);
    QApplication app(argc, argv);

    // Register FilterManager with QML
    qmlRegisterType<FilterManager>("Filters", 1, 0, "FilterManager");
    qmlRegisterType<QCustomPlotWrapper>("CustomPlot", 1, 0, "QCustomPlotWrapper");
    // Register custom model type with QML
    //    qmlRegisterUncreatableType<QmlObjectListModel>  ("ControlTheory", 1, 0, "QmlObjectListModel", "Reference only");


    Eigen::Matrix<double, 7, 7> Q ;
    Q.setZero();/*
    Q(0, 0) = 0.05; // q0
    Q(1, 1) = 0.05; // q1
    Q(2, 2) = 0.05; // q2
    Q(3, 3) = 0.05; // q3
    Q(4, 4) = 0.01; // bx
    Q(5, 5) = 0.01; // by
    Q(6, 6) = 0.01; // bz*/

    for (int i=0; i<7; ++i){
        if(i <=3) {
            Q(i, i) = 0.05; //quaternion noise q0, q1, q2, q3
        } else {
            Q(i, i) = 0.01; // bias noise bx, by, bz
        }
    }


    double psi = 0.0;   // yaw
    double theta = 0.0; // pitch
    double phi = 0.0;   // roll

    Eigen::Vector3d euler(psi, theta, phi);
    Eigen::Vector4d q = Euler3212EP(euler);

    x(0) = q(0);
    x(1) = q(1);
    x(2) = q(2);
    x(3) = q(3);
    x(4) = 0.5; // bx
    x(5) = 0.0; // by
    x(6) = 0.0; // bz

    Eigen::Matrix<double, 7, 7> P;
    P = 0.0001*P.setIdentity();
    //    Eigen::Vector4d qu = x.segment<4>(0);
    Eigen::Vector3d bias = x.segment<3>(4);
    Eigen::Vector3d gyro (1.0, 0.2, 0.25);
    Eigen::Vector3d omega = gyro - bias;


    std::cout <<" gyro: "<<std::endl<<gyro<< std::endl;
    std::cout <<" omega: "<<omega << std::endl;
    std::cout <<" omegaMatrix: "<<std::endl<<omegaMatrix(omega)<< std::endl;

    std::cout <<" computeFJacobian: "<<std::endl<<computeFJacobian(gyro) << std::endl;

    std::cout <<" x before: "<< x << std::endl;
    Eigen::Vector4d dq = 0.5 * omegaMatrix(omega) * q;
    double dt = 0.01;
    x.segment<4>(0) += dq * dt;
    std::cout <<" X after: "<< x << std::endl;
    std::cout <<" dq * dt: "<< dq * dt << std::endl;
    //   x.segment<4>(0).normalize();
    //   std::cout <<" X normalized: "<< x << std::endl;
    std::cout <<" X normalized: "<< x.segment<4>(0)/x.segment<4>(0).norm() << std::endl;
    std::cout <<" quaterionToRotationMatrix: "<<std::endl<< quaterionToRotationMatrix(q) << std::endl;

    std::cout <<" computeHJacobian: "<<std::endl<< computeHJacobian() << std::endl;








    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
