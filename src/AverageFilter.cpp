#include "AverageFilter.h"

#include <QDebug>

// Initialize static members to invalid values (can be updated later)
//double AverageFilter::prevAvg = 0;
//int AverageFilter::k = 1;

AverageFilter::AverageFilter(QObject *parent)
    : QObject{parent}
{
}

double AverageFilter::apply(double x)
{
    qDebug() << "before prevAvg: " <<prevAvg<< "k: "<<k;

    double alpha = (k-1.0) / k;
    double avg = alpha * prevAvg + (1.0 - alpha) * x;

    prevAvg = avg; // Update state
    k += 1; // Increment counter

    qDebug() << "after prevAvg: " <<prevAvg<< "k: "<<k<<" avg: "<<avg;

    return avg;

}

void AverageFilter::initialize()
{
    prevAvg = 0.0;
    k = 1;
}
