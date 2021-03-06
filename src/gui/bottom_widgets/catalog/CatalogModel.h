#ifndef CATALOGMODEL_H
#define CATALOGMODEL_H

#include "../BottomModel.h"

class CatalogModel : public BottomModel
{
    enum CatalogColumns
    {
        colName = 0,
        colAuthor = 1,
        colGenres = 2,
        colPublishing = 3,
        colCurrCount = 4,
        colAllCount = 5,
        colCount = 6
    };

    Q_OBJECT

    QList<std::shared_ptr<BaseDataInfo>> books;

public:
    explicit CatalogModel(QObject *parent = nullptr);

    void setData(BaseDataInfos &books);

private:
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
};

#endif // CATALOGMODEL_H
