#ifndef AVERAGEFILTER_H
#define AVERAGEFILTER_H

#include <QObject>

class AverageFilter : public QObject
{
    Q_OBJECT
public:
    explicit AverageFilter(QObject *parent = nullptr);
    // Method to apply the filter on a new value
    double apply(double x);
    //  initialization method
     void initialize();


signals:

private:
    // stores the previous average
    double prevAvg = 0.0;
    // counter for the number of samples
    int k = 1;
};

#endif // AVERAGEFILTER_H
