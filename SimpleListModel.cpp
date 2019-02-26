#include "SimpleListModel.h"

#include <QHash>
#include <QDebug>

// You can define custom data roles starting with Qt::UserRole
const int SimpleListModel::FirstNameRole = Qt::UserRole + 1;
const int SimpleListModel::LastNameRole = Qt::UserRole + 2;
const int maxItems = 1000000;

SimpleListModel::SimpleListModel(QObject *parent) :
        QAbstractListModel(parent)
{
}

QHash<int, QByteArray> SimpleListModel::roleNames() const
{
    auto roles = QAbstractItemModel::roleNames();
    roles.insert(FirstNameRole, QByteArray("firstName"));
    roles.insert(LastNameRole, QByteArray("lastName"));
    return roles;
}

int SimpleListModel::rowCount(const QModelIndex &) const
{
    return maxItems;
}

QVariant SimpleListModel::data(const QModelIndex &index,
                               int role) const {
    if (!index.isValid())
    {
        return QVariant(); // Return Null variant if index is invalid
    }

    if (index.row() > (maxItems-1) )
    {
        return QVariant();
    }

    switch (role) {
    case Qt::DisplayRole: // The default display role now displays the first name as well
    case FirstNameRole:
    {
        QString firstName;
        firstName.sprintf("First_%d", index.row());
        qDebug("GetName %s", qPrintable(firstName));
        return QVariant::fromValue(firstName);
    }
    case LastNameRole:
    {
        QString lastName;
        lastName.sprintf("Last_%d", index.row());
        return QVariant::fromValue(lastName);
    }
    default:
        return QVariant();
    }
}

