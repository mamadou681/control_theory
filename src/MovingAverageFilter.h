#ifndef MOVINGAVERAGEFILTER_H
#define MOVINGAVERAGEFILTER_H

#include <QObject>

class MovingAverageFilter : public QObject
{
    Q_OBJECT
public:
    explicit MovingAverageFilter(QObject *parent = nullptr);

    double apply(double x);
    void  initialize(int n);

private:
    bool firstRun = true;
    double prevAvg = 0.0;
    int windowSize;
    std::vector<double> xBuffer;
signals:

};

#endif // MOVINGAVERAGEFILTER_H
