#include "QmlObjectListModel.h"

#include <QDebug>
const int QmlObjectListModel::objectRole = Qt::UserRole;

QmlObjectListModel::QmlObjectListModel(QObject *parent)
    : QAbstractListModel{parent}
{

}

// Returns the number of rows in the model
int QmlObjectListModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return _objectList.size();
}

// Returns the data at a specific index
QVariant QmlObjectListModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || index.row() < 0 || index.row() >= _objectList.size())
        return QVariant();

    QObject *object = _objectList.at(index.row());
    if (!object)
        return QVariant();

    // Return the QObject itself for the objectRole
    if (role == objectRole) {
        return QVariant::fromValue(object);
    }

    return QVariant();
}


// Defines role names for QML
QHash<int, QByteArray> QmlObjectListModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[objectRole] = "object"; // Expose the object itself
    return roles;
}

// Adds an object to the model
void QmlObjectListModel::addObject(QObject *object) {
    if (!object)
        return;

    beginInsertRows(QModelIndex(), _objectList.size(), _objectList.size());
    _objectList.append(object);
    endInsertRows();
}

// Removes an object at the given index
void QmlObjectListModel::removeObject(int index) {
    if (index < 0 || index >= _objectList.size())
        return;

    beginRemoveRows(QModelIndex(), index, index);
    delete _objectList.takeAt(index); // Delete the object to avoid memory leaks
    endRemoveRows();
}

// Gets the object at a specific index
QObject *QmlObjectListModel::getObject(int index) const {
    if (index < 0 || index >= _objectList.size())
        return nullptr;

    return _objectList.at(index);
}

// Returns the underlying object list
QList<QObject*> QmlObjectListModel::objectList() const {
    return _objectList;
}
