#include "QCustomplotWrapper.h"

QCustomPlotWrapper::QCustomPlotWrapper(QQuickItem *parent):
    QQuickPaintedItem(parent)
{
    // get memory for customplot
    m_customPlot = new QCustomPlot();
    //    m_customPlot->setMinimumSize(800, 600);


}

QCustomPlotWrapper::~QCustomPlotWrapper()
{
    delete m_customPlot;
}

void QCustomPlotWrapper::paint(QPainter *painter)
{
    // create QPixmap and set the size
    QPixmap picture(m_customPlot->size());
    // create QCPPainter
    QCPPainter qcpPainter(&picture);
    m_customPlot->toPainter(&qcpPainter);
    // draw
    painter->drawPixmap(0, 0, picture);

}


void QCustomPlotWrapper::addPoint(double time, double value1, double value2)
{

    m_customPlot->graph(0)->addData(time, value1);
    m_customPlot->xAxis->setRange(time, 10, Qt::AlignRight);


    m_customPlot->graph(1)->addData(time, value2);
    m_customPlot->graph(1)->setPen(QPen(Qt::red)); // Set color to red
    m_customPlot->replot();
    update();
    m_customPlot->rescaleAxes();

}

void QCustomPlotWrapper::resetGraph()
{

  m_customPlot->clearGraphs();
  m_customPlot->replot();
}

void QCustomPlotWrapper::setupGraph(QString secondPlot, QString xLabel, QString yLabel, QString firstPlot)
{
      m_customPlot->addGraph();
    // Set the graph names
       m_customPlot->graph(0)->setName(firstPlot);
       m_customPlot->xAxis->setLabel(xLabel);
       m_customPlot->yAxis->setLabel(yLabel);

       m_customPlot->addGraph();
       m_customPlot->graph(1)->setName(secondPlot);

       // Enable the legend
       m_customPlot->legend->setVisible(true);

       // Customize the legend appearance
       QFont legendFont;
       legendFont.setPointSize(10); // Adjust font size
       m_customPlot->legend->setFont(legendFont);
       m_customPlot->legend->setBrush(QBrush(Qt::yellow)); // Background color
       m_customPlot->legend->setBorderPen(QPen(Qt::black)); // Border color

//       update();

}

void QCustomPlotWrapper::updatePlotSize(int width, int height)
{
    if (m_customPlot) {
        m_customPlot->setGeometry(0, 0, width, height);
        m_customPlot->replot(); // Redraw the plot to adjust to the new size
    }
}

