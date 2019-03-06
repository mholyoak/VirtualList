#ifndef SIMPLELISTMODEL_H
#define SIMPLELISTMODEL_H

#include <QAbstractListModel>
#include <QQuickItem>

#include <memory>

class Container : public QQuickItem
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name CONSTANT)

    QString m_name;

public:

    Container(QQuickItem *parent = nullptr);
    virtual ~Container();

    QString name() const;

};


class SimpleListModel : public QAbstractListModel {
    Q_OBJECT
public:
    SimpleListModel(QQuickItem *parent=nullptr);

    QHash<int, QByteArray> roleNames() const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

private:
    Q_DISABLE_COPY(SimpleListModel)
    static const int FirstNameRole;
    static const int LastNameRole;
    static const int ActiveRole;
    static const int ContainerRole;

    std::shared_ptr<Container> mContainer;
};

#endif // SIMPLELISTMODEL_H
