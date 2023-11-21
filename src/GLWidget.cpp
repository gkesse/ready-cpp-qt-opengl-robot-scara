//===============================================
#include "GLWidget.h"
#include "GScara.h"
//===============================================
GLWidget::GLWidget(QWidget* _parent)
: QOpenGLWidget(_parent)
, m_robot(0)
, m_width(0)
, m_height(0)
, m_pitch(30.0)
, m_yaw(0.0)
, m_distance(7.0) {

}
//===============================================
GLWidget::~GLWidget() {

}
//===============================================
void GLWidget::setRobot(GScara* _robot) {
    m_robot = _robot;
}
//===============================================
void GLWidget::setPitch(double _pitch) {
    m_pitch = _pitch;
}
//===============================================
void GLWidget::setYaw(double _yaw) {
    m_yaw = _yaw;
}
//===============================================
void GLWidget::setDistance(double _distance) {
    m_distance = _distance;
}
//===============================================
void GLWidget::initializeGL() {
    glEnable(GL_DEPTH_TEST);
    glClearDepth(1.0);

    glEnable(GL_CULL_FACE);

    glEnable(GL_POINT_SMOOTH);
    glPointSize(10.0);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    glClearColor(0.0, 0.0, 0.0, 0.0);
}
//===============================================
void GLWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    setView();
    setLight();

    glEnable(GL_COLOR_MATERIAL);
    glDisable(GL_LIGHTING);

    glColor4f(0.0, 0.5, 0.0, 0.5);

    for(int i = 0; i <= 20; ++i) {
        glBegin(GL_LINES);
        glVertex3f(-5.0+0.5*i, -5.0, 0.0); glVertex3f(-5.0+0.5*i, 5.0, 0.0);
        glVertex3f(-5.0, -5.0+0.5*i, 0.0); glVertex3f(5.0, -5.0+0.5*i, 0.0);
        glEnd();
    }

    glColor4f(0.5, 0.5, 0.0, 0.5);
    glBegin(GL_LINES);
    glVertex3f(m_robot->getY(), -m_robot->getX(), 0.0); glVertex3f(m_robot->getY(), -m_robot->getX(), m_robot->getZ()+0.5);
    glEnd();

    glColor4f(0.9, 0.0, 0.0, 0.5);
    m_robot->displayPath();

    glDisable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    m_robot->display();

    glFlush();
}
//===============================================
void GLWidget::resizeGL(int _width, int _height) {
    m_width = _width;
    m_height = _height;
    glViewport(0.0, 0.0, _width, _height);
    setView();
}
//===============================================
void GLWidget::setView() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1.0*m_width/m_height, 0.1, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(-m_distance, 0.0, 0.0,
              0.0, 0.0, 0.0,
              0.0, 0.0, 1.0);
    glRotatef(m_pitch, 0.0, -1.0, 0.0);
    glRotatef(m_yaw, 0.0, 0.0, -1.0);
}
//===============================================
void GLWidget::perspective(GLdouble _fovY, GLdouble _aspect, GLdouble _zNear, GLdouble _zFar) {
    GLdouble xmin, xmax, ymin, ymax;

    ymax = _zNear * tan( _fovY * M_PI / 360.0 );
    ymin = -ymax;
    xmin = ymin * _aspect;
    xmax = ymax * _aspect;

    glFrustum( xmin, xmax, ymin, ymax, _zNear, _zFar );
}
//===============================================
void GLWidget::setLight() {
    GLfloat lamb[] = { 0.1, 0.1, 0.1, 1.0 };
    GLfloat ldif[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat lpos[] = { -10.0, -10.0, 10.0, 1.0 };

    glEnable(GL_COLOR_MATERIAL);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glColor4fv(ldif);
    glBegin(GL_POINTS);
    glVertex4fv(lpos);
    glEnd();

    glDisable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glLightfv(GL_LIGHT0, GL_POSITION, lpos);
    glLightfv(GL_LIGHT0, GL_AMBIENT, lamb);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, ldif);
}
//===============================================
