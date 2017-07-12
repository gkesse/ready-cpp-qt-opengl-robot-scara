#include "GStyle.h"
#include <QFile>
#include <QApplication>

GStyle* GStyle::m_instance = 0;

GStyle::GStyle() {

}

GStyle::~GStyle() {

}

GStyle* GStyle::Instance() {
    if(m_instance == 0) {
        m_instance = new GStyle;
    }

    return m_instance;
}

void GStyle::load() {
    QFile m_file(":/css/style.css");
    m_file.open(QFile::ReadOnly);
    QString m_styleSheet = QLatin1String(m_file.readAll());
    qApp->setStyleSheet(m_styleSheet);
}

