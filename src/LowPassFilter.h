#ifndef LOWPASSFILTER_H
#define LOWPASSFILTER_H

#include <QObject>

class LowPassFilter : public QObject
{
    Q_OBJECT
public:
    explicit LowPassFilter(QObject *parent = nullptr);

    double apply(double x);
    void  initialize(double alpha);
private:
    bool firstRun = true;
    double m_prevX = 0.0;
    double m_alpha;
signals:

};

#endif // LOWPASSFILTER_H
