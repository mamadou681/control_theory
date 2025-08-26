#ifndef SENSORDATA_H
#define SENSORDATA_H

#include <QObject>

#include "IMUReader.h"

class SensorData : public QObject
{
    Q_OBJECT
public:
    explicit SensorData(QObject *parent = nullptr);
    // Function to generate voltage with random noise
    double getVolt();
    // get sonar alt data
    double getSonarAltData();

    // load alt data from file
    bool loadAltData(const QString& filePath);
    int currentIndex = 0;

    // load gyro and accel data from file
    IMUReader m_imuReader;





private:
    std::vector<double> sonarAltData;
signals:

};

#endif // SENSORDATA_H
