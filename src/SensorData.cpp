#include "SensorData.h"

#include <random>   // For std::random
#include <cmath>    // For math functions
#include <QFile>
#include <QTextStream>
#include <QDebug>

SensorData::SensorData(QObject *parent)
    : QObject{parent}
{
    loadAltData(":/src/data/SonarAlt_data.csv");

}

double SensorData::getVolt()
{
    // Create a random number generator
    static std::random_device rd;  // Random device to seed the generator
    static std::mt19937 gen(rd()); // Mersenne Twister generator
    static std::normal_distribution<> dis(0, 4); // Normal distribution with mean=0, std_dev=4

    // Generate a random noise value and add it to the base voltage (14.4V)
    double w = dis(gen);
    return 14.4 + w;
}

double SensorData::getSonarAltData()
{
    if (sonarAltData.empty()) return 0; // Handle empty data case
    double value = sonarAltData[currentIndex];
    currentIndex = (currentIndex + 1) % sonarAltData.size(); // Loop back at the end
    return value;
}

bool SensorData::loadAltData(const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Failed to open file:" << filePath;
        return false;
    }

    QTextStream in(&file);
    // Read header line
    QString header = in.readLine();
    if (header.isEmpty() || !header.startsWith("sonarAlt")) {
        qWarning() << "Invalid file format!";
        return false;
    }

    // Read data line
    QString dataLine = in.readLine();
    if (dataLine.isEmpty()) {
        qWarning() << "No data found!";
        return false;
    }

    QStringList values = dataLine.split(',', Qt::SkipEmptyParts);
    for ( QString& valueStr : values) {
        bool ok;
        double value = valueStr.toDouble(&ok);
        if (ok) {
            sonarAltData.push_back(value);
        } else {
            qWarning() << "Invalid value in data:" << valueStr;
        }
    }

    file.close();
    return !sonarAltData.empty();
}
