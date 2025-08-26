#ifndef IMUREADER_H
#define IMUREADER_H

#include <QObject>

#include <Eigen/Dense>

class IMUReader : public QObject
{
    Q_OBJECT
public:
    explicit IMUReader(QObject *parent = nullptr);

    // Load gyro data from CSV file with header wx,wy,wz
    bool loadGyroData(const QString& filePath);

    // Load accel data from CSV file with header ax,ay,az
    bool loadAccelData(const QString& filePath);

    // Get the next sample of gyro [p, q, r] and accel [ax, ay, az]
    Eigen::Vector3d getGyro();
    Eigen::Vector3d getAccel();

    // Returns true if both gyro and accel are loaded and have more data
    bool isDataAvailable() const;

    // increment index
    void incrementIndex();
    // initiAlize index
    void initIndex();

signals:

private:
    QVector<double> wx, wy, wz; // Gyro data
    QVector<double> ax, ay, az; // Accel data

    int index = 0;              // Current sample index
    int size = 0;               // Minimum length of both datasets

    bool gyroLoaded = false;
    bool accelLoaded = false;
};

#endif // IMUREADER_H
