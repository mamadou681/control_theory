#include "MovingAverageFilter.h"
#include <QDebug>
MovingAverageFilter::MovingAverageFilter(QObject *parent)
    : QObject{parent}
{

}

double MovingAverageFilter::apply(double x)
{

    // init for first run
    if(firstRun) {
        firstRun = false;
        prevAvg = 0;
        qDebug() << "set init prevAvg: "<<prevAvg;
    }


    // formula
    //  New Average = Previous Average + (New Value - Oldest Value in Window)/n
    /*
  Where:
    Previous Average is the moving average calculated for the previous window.
    New Value is the most recent value added to the sequence.
    Oldest Value in Window is the value that is dropped from the window as new data comes in.
    n is the window size (number of data points used in the average).
  */
    // shift the values in the window (buffer)
    for (int k = 0; k < windowSize; ++k) {
        xBuffer[k] = xBuffer[k+1];
    }
    // replace the last element by the current value (x)
    xBuffer[windowSize] = x;

    // new moving average value computation
    double avg = prevAvg + (x - xBuffer[0])/ windowSize;
    // store the prev avg
    prevAvg = avg;
    qDebug() <<" Avg: "<< avg;
    return avg;
}

void MovingAverageFilter::initialize(int n)
{
    qDebug() <<"initialize:  " <<n;
    windowSize = n;
    // A buffer (vector) to store the last n+1 input values.
    // The extra slot ensures smooth calculations when shifting values
    // Clear the buffer and resize with default values
    //    xBuffer.clear();
    //    xBuffer.resize(windowSize + 1, 0);
    xBuffer.assign(windowSize +1, 0);

    firstRun = true;
    qDebug() << "Filter initialized with window size:" << n;

}
