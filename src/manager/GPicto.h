#ifndef _GPicto_
#define _GPicto_

#include <QtAwesome.h>
#include <QObject>

class GPicto : public QObject { 
    Q_OBJECT

private:
    GPicto();

public:
    ~GPicto();

public:
    static GPicto* Instance();
    
private:
    void createObjects();
    void createConnexions();
    
public:
    QIcon getPicto(const int& picto, const QColor& color = QColor("white")) const;
    QIcon getPicto(const QString& picto, const QColor& color = QColor("white")) const;

private:
    static GPicto* m_instance;
    QtAwesome* m_picto;
};

#endif
