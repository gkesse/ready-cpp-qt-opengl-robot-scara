#include "GJson.h"
#include "GSplashScreen.h"
#include "GMessageView.h"
#include <QFile>
#include <initializer_list>

using namespace std;

GJson* GJson::m_instance = 0;

GJson::GJson(QObject* parent) : QObject(parent) {
    createObjects();
    createConnexions();
    GSplashScreen::Instance()->showMessage("GJson : loading GJson module...");
}

GJson::~GJson() {
    
}

GJson* GJson::Instance() {
    if(m_instance == 0) {
        m_instance = new GJson;
    }
    
    return m_instance;
}

void GJson::createObjects() {
    
}

void GJson::createConnexions() {
    
}

void GJson::load(const QString& file) {
    QFile m_file(file);
    m_file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString m_data = m_file.readAll();
    m_file.close();
    m_jsonObj = QJsonDocument::fromJson(m_data.toUtf8()).object();
}

void GJson::save(const QString& file, const QJsonDocument::JsonFormat& format) {
    QFile m_file(file);
    m_file.open(QIODevice::WriteOnly | QIODevice::Text);
    m_file.write(QJsonDocument(m_jsonObj).toJson(format));
    m_file.close();
}

QStringList GJson::getArray(const QString& key, const QString& key2) {
    QJsonArray m_array = m_jsonObj.value(key).toArray();
    int m_size = m_array.size();
    QStringList m_datas;

    for(int i = 0; i < m_size; i++) {
        QJsonObject m_object = m_array.at(i).toObject();
        QString m_data = m_object.value(key2).toString();
        m_datas.append(m_data);
    }

    return m_datas;
}
