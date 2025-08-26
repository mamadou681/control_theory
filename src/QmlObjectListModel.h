#ifndef QMLOBJECTLISTMODEL_H
#define QMLOBJECTLISTMODEL_H

#include <QAbstractListModel>
#include <QObject>
#include <QMetaType>


class QmlObjectListModel : public QAbstractListModel
{
public:

    explicit QmlObjectListModel(QObject *parent = nullptr);

    // Overrides for QAbstractListModel
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Role names for accessing data in QML
    QHash<int, QByteArray> roleNames() const override;

    // Methods to manipulate the object list
    Q_INVOKABLE void addObject(QObject *object);
    Q_INVOKABLE void removeObject(int index);
    Q_INVOKABLE QObject *getObject(int index) const;

    // Getters for the object list
    QList<QObject*> objectList() const;

private:
    QList<QObject*> _objectList; // List of QObject pointers
    // Role for the object itself
    static const int objectRole;
};

Q_DECLARE_METATYPE(QmlObjectListModel*)  // Add this line to register QmlObjectListModel

#endif // QMLOBJECTLISTMODEL_H
