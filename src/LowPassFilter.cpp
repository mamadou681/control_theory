#include "LowPassFilter.h"
#include <QDebug>
LowPassFilter::LowPassFilter(QObject *parent)
    : QObject{parent}
{

}

double LowPassFilter::apply(double x)
{
    if(firstRun) {
        firstRun = false;
        // Initialize prevX with the first input
        m_prevX = x;
    }
    qDebug() <<"LowPassFilter::apply m_alpha: "<<m_alpha;

     // Apply low-pass filter formula
    double xlpf = m_alpha * m_prevX + (1 - m_alpha) * x;

    // Update prevX for the next iteration
    m_prevX = xlpf;

    return xlpf;
}

void LowPassFilter::initialize(double alpha)
{
    m_alpha = alpha;
    qDebug() <<"LowPassFilter::initialize m_alpha: "<<m_alpha;
    firstRun = true;

}
