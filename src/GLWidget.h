//===============================================
#ifndef _GLWidget_
#define _GLWidget_
//===============================================
#include "GInclude.h"
//===============================================
class GScara;
//===============================================
class GLWidget : public QOpenGLWidget {
    Q_OBJECT

public:
    explicit GLWidget(QWidget* _parent = nullptr);
    ~GLWidget();
    void setRobot(GScara* _robot);
    void setPitch(double _pitch);
    void setYaw(double _yaw);
    void setDistance(double _distance);

private:
    void setView();
    void perspective(GLdouble _fovY, GLdouble _aspect, GLdouble _zNear, GLdouble _zFar);
    void setLight();

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int _width, int _height);

private:
    GScara* m_robot;
    int m_width;
    int m_height;
    double m_pitch;
    double m_yaw;
    double m_distance;
};
//===============================================
#endif
//===============================================
