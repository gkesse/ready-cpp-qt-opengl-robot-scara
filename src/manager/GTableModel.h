#ifndef _GTableModel_
#define _GTableModel_

#include <QAbstractTableModel>

class GTableModel : public QAbstractTableModel {
    Q_OBJECT

public:
    GTableModel(QObject* parent = 0);
    ~GTableModel();
    
private:
    void createObjects();
    void createConnexions();

protected:
    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    int columnCount(const QModelIndex& parent = QModelIndex()) const;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
};

#endif
