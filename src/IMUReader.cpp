#include "IMUReader.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>

IMUReader::IMUReader(QObject *parent)
    : QObject{parent}
{
    //  load data
    loadGyroData(":/src/data/ArsGyro_data.csv");
    loadAccelData(":/src/data/ArsAccel_data.csv");
}

bool IMUReader::loadGyroData(const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    wx.clear(); wy.clear(); wz.clear();
    QTextStream in(&file);
    in.readLine(); // Skip header: wx,wy,wz

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;
        QStringList tokens = line.split(',', Qt::SkipEmptyParts);
        if (tokens.size() != 3) continue;

        bool ok1, ok2, ok3;
        double gx = tokens[0].toDouble(&ok1);
        double gy = tokens[1].toDouble(&ok2);
        double gz = tokens[2].toDouble(&ok3);

        if (ok1 && ok2 && ok3) {
            wx.append(gx);
            wy.append(gy);
            wz.append(gz);
        }
    }

    gyroLoaded = true;
    size = std::min({wx.size(), wy.size(), wz.size(), size});
    index = 0;
    return true;
}

bool IMUReader::loadAccelData(const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    ax.clear(); ay.clear(); az.clear();
    QTextStream in(&file);
    in.readLine(); // Skip header: ax,ay,az

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;
        QStringList tokens = line.split(',', Qt::SkipEmptyParts);
        if (tokens.size() != 3) continue;

        bool ok1, ok2, ok3;
        double fx = tokens[0].toDouble(&ok1);
        double fy = tokens[1].toDouble(&ok2);
        double fz = tokens[2].toDouble(&ok3);

        if (ok1 && ok2 && ok3) {
            ax.append(fx);
            ay.append(fy);
            az.append(fz);
        }
    }

    accelLoaded = true;
    size = std::min({ax.size(), ay.size(), az.size(), size > 0 ? size : INT_MAX});
    index = 0;
    return true;
}

Eigen::Vector3d IMUReader::getGyro()
{
    //    if (!gyroLoaded || index >= size)
    //        return Eigen::Vector3d::Zero();
    return Eigen::Vector3d(wx[index], wy[index], wz[index]);
}

Eigen::Vector3d IMUReader::getAccel()
{
    //    if (!accelLoaded || index >= size)
    //        return Eigen::Vector3d::Zero();
    return Eigen::Vector3d(ax[index], ay[index], az[index]);
}

bool IMUReader::isDataAvailable() const
{
    return gyroLoaded && accelLoaded && index < size;

}

void IMUReader::incrementIndex()
{
  ++index;
    qDebug() <<"Index "<<index;
}

void IMUReader::initIndex()
{
  index = 0;
}
