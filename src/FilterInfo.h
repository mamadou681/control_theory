#ifndef FILTERINFO_H
#define FILTERINFO_H

#include <QObject>

class FilterInfo : public QObject
{
    Q_OBJECT

    explicit FilterInfo(QObject *parent = nullptr);

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString xAxisLabel READ xAxisLabel WRITE setXAxisLabel NOTIFY xAxisLabelChanged)
    Q_PROPERTY(QString yAxisLabel READ yAxisLabel WRITE setYAxisLabel NOTIFY yAxisLabelChanged)
    Q_PROPERTY(int type READ type WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(QString note READ note WRITE setNote NOTIFY noteChanged)
    Q_PROPERTY(QString firstPlot READ firstPlot WRITE setFirstPlot NOTIFY firstPlotChanged)
    Q_PROPERTY(QString secondPlot READ secondPlot WRITE setSecondPlot NOTIFY secondPlotChanged)






public:
    explicit FilterInfo(const QString &name = "", const int &type = 0,
                        const QString &note = "", const QString &xAxisLabel = "" ,
                        const QString &yAxisLabel = "", const QString &firstPlot = "",const QString &secondPlot = "" , QObject *parent = nullptr);

    const QString &name() const;
    void setName(const QString &newName);
    const QString &xAxisLabel() const;
    void setXAxisLabel(const QString &newXAxisLabel);

    const QString &yAxisLabel() const;
    void setYAxisLabel(const QString &newYAxisLabel);

    int type() const;
    void setType(int newType);

    const QString &note() const;
    void setNote(const QString &newNote);

    const QString &firstPlot() const;
    void setFirstPlot(const QString &newFirstPlot);

    const QString &secondPlot() const;
    void setSecondPlot(const QString &newSecondPlot);

signals:
    void nameChanged();
    void xAxisLabelChanged();

    void yAxisLabelChanged();

    void typeChanged();

    void noteChanged();

    void firstPlotChanged();

    void secondPlotChanged();

private:
    QString m_name;
    QString m_xAxisLabel;
    QString m_yAxisLabel;
    int m_type;
    QString m_note;
    QString m_firstPlot;
    QString m_secondPlot;
};

#endif // FILTERINFO_H
