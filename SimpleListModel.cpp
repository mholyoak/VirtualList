#include "SimpleListModel.h"

#include <QHash>
#include <QDebug>

Container::Container(QQuickItem *parent) :
    QQuickItem(parent)
{
    m_name = "Test";
}

Container::~Container()
{
    qDebug("Container destroyed");
}

QString Container::name() const
{
    return m_name;
}

// You can define custom data roles starting with Qt::UserRole
const int SimpleListModel::FirstNameRole = Qt::UserRole + 1;
const int SimpleListModel::LastNameRole = Qt::UserRole + 2;
const int SimpleListModel::ActiveRole = Qt::UserRole + 3;
const int SimpleListModel::ContainerRole = Qt::UserRole + 4;
const int maxItems = 1000000;

SimpleListModel::SimpleListModel(QQuickItem *parent) :
        QAbstractListModel(parent),
        mContainer(std::make_shared<Container>(parent))
{
}

QHash<int, QByteArray> SimpleListModel::roleNames() const
{
    auto roles = QAbstractItemModel::roleNames();
    roles.insert(FirstNameRole, QByteArray("firstName"));
    roles.insert(LastNameRole, QByteArray("lastName"));
    roles.insert(ActiveRole, QByteArray("active"));
    roles.insert(ContainerRole, QByteArray("container"));
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
    case ActiveRole:
    {
        bool active;
        active = index.row() % 2;
        qDebug("Active %d %s", index.row(), active ? "True" : "False");
        return QVariant::fromValue(active);
    }
    case ContainerRole:
    {
        return QVariant::fromValue(mContainer.get());
    }
    default:
        return QVariant();
    }
}

