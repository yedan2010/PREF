#ifndef STRINGOFFSETMODEL_H
#define STRINGOFFSETMODEL_H

#define STRING_MAX_LENGTH 50

#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include "qhexedit/qhexeditdata.h"

class StringOffsetModel : public QAbstractItemModel
{
    Q_OBJECT

    public:
        explicit StringOffsetModel(QHexEditData* hexeditdata, QObject *parent = 0);

    public: /* Overriden Methods */
        virtual int columnCount(const QModelIndex& = QModelIndex()) const;
        virtual QVariant headerData(int section, Qt::Orientation orientation, int role) const;
        virtual QVariant data(const QModelIndex &index, int role) const;
        virtual QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
        virtual QModelIndex parent(const QModelIndex&) const;
        virtual int rowCount(const QModelIndex& = QModelIndex()) const;
        virtual Qt::ItemFlags flags(const QModelIndex &index) const;
    
    private:
        QHexEditData* _hexeditdata;
};

#endif // STRINGOFFSETMODEL_H
