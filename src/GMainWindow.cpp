//===============================================
#include "GMainWindow.h"
#include "ui_GMainWindow.h"
#include "GScara.h"
//===============================================
GMainWindow::GMainWindow(QWidget* _parent)
: QMainWindow(_parent)
, ui(new Ui::GMainWindow)
, t(0.0), dt(0.0) {
    ui->setupUi(this);

    connect(&m_timer, &QTimer::timeout, this, &GMainWindow::onUpdate);
    m_timer.setInterval(0);
    m_timer.start();

    m_robot = new GScara(this);
    ui->view->setRobot(m_robot);
    m_clock = clock();
}
//===============================================
GMainWindow::~GMainWindow() {
    delete ui;
}
//===============================================
void GMainWindow::onUpdate() {
    dt = 1.0 * (clock() - m_clock) / CLOCKS_PER_SEC;
    m_clock = clock();
    t += dt;

    m_robot->onUpdate(dt);

    bool mode = ui->radioButtonTarget->isChecked();

    QString text;

    text = QString::number(m_robot->getTh1(), 'f', 3);
    ui->labelTh1->setText(text);

    text = QString::number(m_robot->getTh2(), 'f', 3);
    ui->labelTh2->setText(text);

    text = QString::number(m_robot->getZ(), 'f', 3);
    ui->labelThZ->setText(text);

    text = QString::number(m_robot->getY(), 'f', 3);
    ui->labelY->setText(text);

    text = QString::number(m_robot->getX(), 'f', 3);
    ui->labelX->setText(text);

    text = QString::number(m_robot->getZ(), 'f', 3);
    ui->labelZ->setText(text);

    if(mode) {
        ui->horizontalSliderTh1->setValue(m_robot->getTh1());
        ui->horizontalSliderTh2->setValue(m_robot->getTh2());
        ui->horizontalSliderZ->setValue(100.0 * m_robot->getZ());
    }

    ui->view->update();
}
//===============================================
void GMainWindow::on_verticalSliderPitch_valueChanged(int value) {
    ui->view->setPitch(value);
}
//===============================================
void GMainWindow::on_horizontalSliderYaw_valueChanged(int value) {
    ui->view->setYaw(value);
}
//===============================================
void GMainWindow::on_horizontalSliderTh1_valueChanged(int value) {
    bool mode = ui->radioButtonTarget->isChecked();
    if(!mode) m_robot->setTh1(value);
}
//===============================================
void GMainWindow::on_horizontalSliderTh2_valueChanged(int value) {
    bool mode = ui->radioButtonTarget->isChecked();
    if(!mode) m_robot->setTh2(value);
}
//===============================================
void GMainWindow::on_horizontalSliderZ_valueChanged(int value) {
    bool mode = ui->radioButtonTarget->isChecked();
    if(!mode) m_robot->setZ(0.01 * value);
}
//===============================================
void GMainWindow::on_commandLinkButtonGo_clicked() {
    m_robot->setTarget(ui->lineEditTx->text().toDouble(), ui->lineEditTy->text().toDouble(), ui->lineEditTz->text().toDouble());
}
//===============================================
void GMainWindow::on_radioButtonSimple_clicked() {
    m_robot->setMode(GScara::SIMPLE);

    ui->groupBoxSimple->setEnabled(true);
    ui->groupBoxTarget->setDisabled(true);
}
//===============================================
void GMainWindow::on_radioButtonTarget_clicked() {
    m_robot->setMode(GScara::TARGET);
    ui->groupBoxSimple->setDisabled(true);
    ui->groupBoxTarget->setEnabled(true);
}
//===============================================
