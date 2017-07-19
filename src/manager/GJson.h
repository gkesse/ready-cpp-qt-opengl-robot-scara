#ifndef _GJson_
#define _GJson_

#include "GTypeDef.h"
#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>

class GJson : public QObject {
    Q_OBJECT

public:
    GJson(QObject* parent = 0);
    ~GJson();

public:
    static GJson* Instance();

private:
    void createObjects();
    void createConnexions();

public:
    void run();

public:
    void load(const QString& file);
    void save(const QString& file, const QJsonDocument::JsonFormat& format = QJsonDocument::Indented);
    GArrayMap getArray(const QString& key);

private:
    static GJson* m_instance;
    QJsonObject m_jsonObj;
};

#endif
