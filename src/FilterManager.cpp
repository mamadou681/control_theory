#include "FilterManager.h"

#include <QDebug>
#include <QFile>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include <QtMath>

FilterManager::FilterManager(QObject *parent)
    : QObject{parent}
{
    m_ekf.initialize(0.01);
    m_kalmanFilter.initialize(0.02);

    m_filterModel = new QmlObjectListModel(this);

    parseFiltersInfoJson(":/src/data/FiltersInfo.json");
}

void FilterManager::parseFiltersInfoJson(const QString &filePath)
{
    // Open the file
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Couldn't open file:" << filePath;
        return ;
    }

    // Read and parse JSON
    QByteArray jsonData = file.readAll();
    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(jsonData, &parseError);

    if (parseError.error != QJsonParseError::NoError) {
        qWarning() << "JSON parse error:" << parseError.errorString() << "at offset" << parseError.offset;
        return ;
    }

    if (doc.isNull()) {
        qWarning() << "Failed to parse JSON";
        return ;
    }

    // Get the root object
    QJsonObject rootObj = doc.object();
    if (!rootObj.contains("filters") || !rootObj["filters"].isArray()) {
        qWarning() << "Invalid JSON format - missing 'filters' array";
        return ;
    }

    // Process each filter
    QJsonArray filtersArray = rootObj["filters"].toArray();
    for (const QJsonValue& filterValue : filtersArray) {
        if (!filterValue.isObject()) {
            qWarning() << "Skipping non-object filter entry";
            continue;
        }

        QJsonObject filterObj = filterValue.toObject();
        FilterSettings filterSettings;
        // Extract filter information with validation
        filterSettings.filterName = filterObj.value("filterName").toString();
        filterSettings.filterType = filterObj.value("filterType").toInt(-1); // Default to -1 if missing or invalid
        filterSettings.xAxisLabel = filterObj.value("xAxisLabel").toString();
        filterSettings.yAxisLabel = filterObj.value("yAxisLabel").toString();
        filterSettings.firstPlot = filterObj.value("firstPlot").toString();
        filterSettings.secondPlot = filterObj.value("secondPlot").toString();
        filterSettings.note = filterObj.value("note").toString();

        if (!filterSettings.isValid()) {
            qWarning() << "Skipping invalid filter entry:" << filterSettings.filterName;
            continue;
        }

        // add all filter to the model
        addFilterInfo(filterSettings.filterName, filterSettings.filterType,
                      filterSettings.note, filterSettings.xAxisLabel,
                      filterSettings.yAxisLabel, filterSettings.firstPlot, filterSettings.secondPlot);


    }
}

double FilterManager::applyFilter(double value, int type)
{
    switch (type) {
    case FilterManager::filterType::AverageFilterType:
        return m_averageFilter.apply(value);
        break;
    case FilterManager::filterType::MovingAverageFilterType:
        return m_movingAverageFilter.apply(value);
        break;
    case FilterManager::filterType::LowPassFilterType:
        return m_lowPassFilter.apply(value);
        break;
    case FilterManager::filterType::KalmanFilterType:
        return m_kalmanFilter.apply(value);
        break;
    default:
        break;
    }

    return 0;
}

double FilterManager::getSensorData(int const &type)
{
    switch (type) {
    case FilterManager::filterType::AverageFilterType:
        return m_sensorData.getVolt();
        break;
    case FilterManager::filterType::MovingAverageFilterType:
        return m_sensorData.getSonarAltData();
        break;
    case FilterManager::filterType::LowPassFilterType:
        return m_sensorData.getSonarAltData();
        break;
    case FilterManager::filterType::KalmanFilterType:
        return m_sensorData.getSonarAltData();
    default:
        break;
    }

    return 0.0;

}

void FilterManager::resetFilter(const int &type, const double &param, const double &deltaT)
{
    switch (type) {
    case FilterManager::filterType::AverageFilterType:
        m_averageFilter.initialize();
        break;
    case FilterManager::filterType::MovingAverageFilterType:
        m_movingAverageFilter.initialize(param);
        m_sensorData.currentIndex = 0;
        break;
    case FilterManager::filterType::LowPassFilterType:
        qDebug() <<" FilterManager::filterType::lowPassFilter: "<<param;
        m_lowPassFilter.initialize(param);
        m_sensorData.currentIndex = 0;
        break;
    case FilterManager::filterType::KalmanFilterType:
        qDebug() <<" Kalman filter ";
        m_kalmanFilter.initialize(deltaT);
        m_sensorData.currentIndex = 0;
    case FilterManager::filterType::EKFType:
        m_ekf.initialize(deltaT);
        m_sensorData.m_imuReader.initIndex();
    default:
        break;
    }

}

QVariantMap FilterManager::applyEKF()
{
    Eigen::Vector3d gyro = m_sensorData.m_imuReader.getGyro();
    Eigen::Vector3d accel = m_sensorData.m_imuReader.getAccel();

    // increment
    m_sensorData.m_imuReader.incrementIndex();

    // get euler angles
    Eigen::Vector3d eulerAngle = m_ekf.apply(gyro, accel);
    qDebug() <<"PI value: "<<M_PI;

    return {
        {"yaw", eulerAngle[0] * 180/M_PI},
        {"pitch", eulerAngle[1] * 180/M_PI},
        {"roll", eulerAngle[2] * 180/M_PI},
    }; // return yaw-pitch-roll
}

QmlObjectListModel *FilterManager::filterModel() const
{
    return m_filterModel;
}

void FilterManager::addFilterInfo(const QString &name,  const int &type , const QString &note,
                                  const QString &xAxisLabel, const QString &yAxisLabel, const QString &firstPlot,
                                  const QString &secondPlot)
{
    FilterInfo *filterInfo = new FilterInfo(name, type, note, xAxisLabel, yAxisLabel,firstPlot,secondPlot , this);
    m_filterModel->addObject(filterInfo);
}
