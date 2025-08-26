#include "FilterInfo.h"

FilterInfo::FilterInfo(QObject *parent)
    : QObject{parent}
{

}

FilterInfo::FilterInfo(const QString &name, const int &type, const QString &note, const QString &xAxisLabel,
                       const QString &yAxisLabel, const QString &firstPlot,const QString &secondPlot, QObject *parent):
    m_name(name), m_xAxisLabel(xAxisLabel), m_yAxisLabel(yAxisLabel), m_type(type), m_note(note),
    m_firstPlot (firstPlot), m_secondPlot(secondPlot)
{

}

const QString &FilterInfo::name() const
{
    return m_name;
}

void FilterInfo::setName(const QString &newName)
{
    if (m_name == newName)
        return;
    m_name = newName;
    emit nameChanged();
}

const QString &FilterInfo::xAxisLabel() const
{
    return m_xAxisLabel;
}

void FilterInfo::setXAxisLabel(const QString &newXAxisLabel)
{
    if (m_xAxisLabel == newXAxisLabel)
        return;
    m_xAxisLabel = newXAxisLabel;
    emit xAxisLabelChanged();
}

const QString &FilterInfo::yAxisLabel() const
{
    return m_yAxisLabel;
}

void FilterInfo::setYAxisLabel(const QString &newYAxisLabel)
{
    if (m_yAxisLabel == newYAxisLabel)
        return;
    m_yAxisLabel = newYAxisLabel;
    emit yAxisLabelChanged();
}

int FilterInfo::type() const
{
    return m_type;
}

void FilterInfo::setType(int newType)
{
    if (m_type == newType)
        return;
    m_type = newType;
    emit typeChanged();
}

const QString &FilterInfo::note() const
{
    return m_note;
}

void FilterInfo::setNote(const QString &newNote)
{
    if (m_note == newNote)
        return;
    m_note = newNote;
    emit noteChanged();
}

const QString &FilterInfo::firstPlot() const
{
    return m_firstPlot;
}

void FilterInfo::setFirstPlot(const QString &newFirstPlot)
{
    if (m_firstPlot == newFirstPlot)
        return;
    m_firstPlot = newFirstPlot;
    emit firstPlotChanged();
}

const QString &FilterInfo::secondPlot() const
{
    return m_secondPlot;
}

void FilterInfo::setSecondPlot(const QString &newSecondPlot)
{
    if (m_secondPlot == newSecondPlot)
        return;
    m_secondPlot = newSecondPlot;
    emit secondPlotChanged();
}
