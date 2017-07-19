#ifndef _GDatabaseAccess_
#define _GDatabaseAccess_

#include <QObject>

class GDatabaseAccess : public QObject {
    Q_OBJECT

private:
    GDatabaseAccess();

public:
    ~GDatabaseAccess();

public:
    static GDatabaseAccess* Instance();
    
private:
    void createObjects();
    void createConnexions();
    
public:
    QStringList getDrivers() const;
    void run();

private:
    static GDatabaseAccess* m_instance;
};

#endif
