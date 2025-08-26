#ifndef FILTERMANAGER_H
#define FILTERMANAGER_H

#include <QObject>
#include <QVariantMap>

#include "AverageFilter.h"
#include "QmlObjectListModel.h"
#include "FilterInfo.h"
#include "MovingAverageFilter.h"
#include "SensorData.h"
#include "LowPassFilter.h"
#include "KalmanFilter.h"
#include "EKF.h"

class FilterManager : public QObject
{
    Q_OBJECT


    struct FilterSettings {
        QString filterName;
        int filterType = -1;  // Initialize with invalid value
        QString xAxisLabel;
        QString yAxisLabel;
        QString firstPlot;
        QString secondPlot;
        QString note;

        bool isValid() const {
            return !filterName.isEmpty() && filterType >= 0;
        }
    };

public:
    explicit FilterManager(QObject *parent = nullptr);

    void parseFiltersInfoJson(const QString& filePath);

    Q_PROPERTY(QmlObjectListModel* filterModel READ filterModel NOTIFY filterModelChanged)


    // Generalized method to apply a filter
    Q_INVOKABLE double applyFilter(double value, int type);
    // Function to generate voltage with random noise
    Q_INVOKABLE double getSensorData(int const &type);
    // reset filter parameters
    Q_INVOKABLE void resetFilter(const int &type, const double &param, const double &deltaT);

    // apply EKF
    Q_INVOKABLE QVariantMap applyEKF();


    QmlObjectListModel *filterModel() const;
    Q_INVOKABLE void addFilterInfo(const QString &name, const int &type, const QString &note,
                                   const QString &xAxisLabel, const QString &yAxisLabel,
                                   const QString &firstPlot, const QString &secondPlot);

    enum filterType {
        AverageFilterType = 0,
        MovingAverageFilterType,
        LowPassFilterType,
        KalmanFilterType,
        EKFType,

    };

    Q_ENUM(filterType)

signals:

    void filterModelChanged();

private:
    AverageFilter m_averageFilter;
    QmlObjectListModel *m_filterModel;
    MovingAverageFilter m_movingAverageFilter;
    SensorData m_sensorData;
    LowPassFilter m_lowPassFilter;
    KalmanFilter m_kalmanFilter;
    EKF m_ekf;
};

#endif // FILTERMANAGER_H
