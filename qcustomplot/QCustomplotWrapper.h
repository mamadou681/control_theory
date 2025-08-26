#ifndef QCUSTOMPLOTWRAPPER_H
#define QCUSTOMPLOTWRAPPER_H

#include <QQuickPaintedItem>

#include "qcustomplot.h"

class QCustomPlotWrapper : public QQuickPaintedItem
{
    Q_OBJECT
public:
    explicit QCustomPlotWrapper(QQuickItem* parent = nullptr);
    ~QCustomPlotWrapper();
    void paint(QPainter* painter) override;

    Q_INVOKABLE void addPoint(double time, double value1, double value2);
    Q_INVOKABLE void resetGraph();
    Q_INVOKABLE void setupGraph(QString secondPlot, QString xLabel, QString yLabel, QString firstPlot);

public slots:
    void updatePlotSize(int width, int height);
private:
    QCustomPlot* m_customPlot;
};

#endif // QCUSTOMPLOTWRAPPER_H
