#ifndef SIMPLELISTMODEL_H
#define SIMPLELISTMODEL_H

#include <QAbstractListModel>

class SimpleListModel : public QAbstractListModel {
    Q_OBJECT
public:
    SimpleListModel(QObject *parent=nullptr);
    QHash<int, QByteArray> roleNames() const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

private:
    Q_DISABLE_COPY(SimpleListModel)
    static const int FirstNameRole;
    static const int LastNameRole;
    static const int ActiveRole;
};

#endif // SIMPLELISTMODEL_H
