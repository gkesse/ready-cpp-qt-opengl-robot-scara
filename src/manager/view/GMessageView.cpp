#include "GMessageView.h"
#include "ui_GMessageView.h"
#include "GSplashScreen.h"
#include "GPicto.h"
#include <QApplication>
#include <QDesktopWidget>

GMessageView* GMessageView::m_instance = 0;

GMessageView::GMessageView() :
    ui(new Ui::GMessageView) {
    ui->setupUi(this);
    createObjects();
    createConnexions();
    setPosition();
}

GMessageView::~GMessageView() {
    delete ui;
}

GMessageView* GMessageView::Instance() {
    if(m_instance == 0) {
        m_instance =  new GMessageView;
    }

    return m_instance;
}

void GMessageView::createObjects() {
    ui->m_title->setIcon(GPicto::Instance()->getPicto(fa::comments));
    ui->m_clear->setIcon(GPicto::Instance()->getPicto(fa::trash));
}

void GMessageView::createConnexions() {
    connect(ui->m_clear, SIGNAL(clicked()), this, SLOT(slotClearClicked()));
}

void GMessageView::setPosition() {
    int m_viewW = 400;
    int m_viewH = 300;

    QSize m_desktopS = QApplication::desktop()->screenGeometry().size();
    int m_desktopW = m_desktopS.width();
    int m_desktopH = m_desktopS.height();

    int m_viewX = m_desktopW - m_viewW - 10;
    int m_viewY = m_desktopH - m_viewH - 50;

    setGeometry(m_viewX, m_viewY, m_viewW, m_viewH);
}

void GMessageView::separate() {
    ui->m_message->append("--------------------------------------------------");
}

void GMessageView::showData(const QString& data, const QString& name) {
    QString m_data = data;
    if(name != "") m_data = name + " : " + data;
    ui->m_message->append(m_data);
}

void GMessageView::showData(const char* data, const QString& name) {
    QString m_data = QString("%1").arg(data);
    showData(m_data, name);
}

void GMessageView::showData(const bool& data, const QString& name) {
    QString m_data = QString("%1").arg(data);
    showData(m_data, name);
}

void GMessageView::showData(const int& data, const QString& name) {
    QString m_data = QString("%1").arg(data);
    showData(m_data, name);
}

void GMessageView::showData(const double& data, const QString& name) {
    QString m_data = QString("%1").arg(data);
    showData(m_data, name);
}

void GMessageView::showData(const QStringList& data, const QString& name) {
    QString m_data = data.join(" ; ");
    showData(m_data, name);
}

void GMessageView::slotClearClicked() {
    ui->m_message->clear();
}
