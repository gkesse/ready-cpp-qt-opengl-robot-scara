//===============================================
#ifndef _GMainWindow_
#define _GMainWindow_
//===============================================
#include "GInclude.h"
//===============================================
namespace Ui {
class GMainWindow;
}
//===============================================
class GScara;
//===============================================
class GMainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit GMainWindow(QWidget* _parent = nullptr);
    ~GMainWindow();

public slots:
	void onUpdate();
	void on_verticalSliderPitch_valueChanged(int value);
	void on_horizontalSliderYaw_valueChanged(int value);
	void on_horizontalSliderTh1_valueChanged(int value);
	void on_horizontalSliderTh2_valueChanged(int value);
	void on_horizontalSliderZ_valueChanged(int value);
	void on_commandLinkButtonGo_clicked();
	void on_radioButtonSimple_clicked();
	void on_radioButtonTarget_clicked();

private:
    Ui::GMainWindow *ui;
    QTimer m_timer;
    GScara* m_robot;
    clock_t m_clock;
    double t, dt;
};
//===============================================
#endif
//===============================================
