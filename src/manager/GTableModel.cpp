#include "GTableModel.h"
#include "GPicto.h"

GTableModel::GTableModel(QObject *parent) :
    QAbstractTableModel(parent){
    createObjects();
    createConnexions();
}

GTableModel::~GTableModel() {
    
}

void GTableModel::createObjects() {

}

void GTableModel::createConnexions() {
    
}

int GTableModel::rowCount(const QModelIndex& parent) const {
    Q_UNUSED(parent);
    return 2;
}

int GTableModel::columnCount(const QModelIndex& parent) const {
    Q_UNUSED(parent);
    return 3;
}

QVariant GTableModel::data(const QModelIndex& index, int role) const {
    if (role == Qt::DisplayRole) {
        return QString("Row%1, Column%2")
                .arg(index.row() + 1)
                .arg(index.column() +1);
    }
    else if (role == Qt::DecorationRole) {
        return GPicto::Instance()->getPicto(fa::file);
    }
    return QVariant();
}

QVariant GTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole) {
        if (orientation == Qt::Horizontal) {
            switch (section) {
            case 0:
                return QString("first");
            case 1:
                return QString("second");
            case 2:
                return QString("third");
            }
        }
        else if (orientation == Qt::Vertical) {
            switch (section) {
            case 0:
                return QString("first");
            case 1:
                return QString("second");
            }
        }
    }
    return QVariant();
}
