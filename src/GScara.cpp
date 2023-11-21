//===============================================
#include "GScara.h"
//===============================================
GScara::GScara(QObject* _parent)
: QObject(_parent)
, th1(0.0), th2(90.0), z(0.0)
, dth1(0.0), dth2(0.0), dz(0.0)
, posx(0.0), posy(0.0), posz(0.0)
, tx(1.0), ty(1.0), tz(0.0)
, r1(1.5), r2(1.5)
, m_mode(SIMPLE) {
    m_baseModel.load("data/obj/base.obj");
    m_arm1Model.load("data/obj/arm1.obj");
    m_arm2Model.load("data/obj/arm2.obj");
    m_arm3Model.load("data/obj/arm3.obj");
    kinPr();
}
//===============================================
GScara::~GScara() {

}
//===============================================
double GScara::getTh1() {
    return th1;
}
//===============================================
double GScara::getTh2() {
    return th2;
}
//===============================================
double GScara::getX() {
    return posx;
}
//===============================================
double GScara::getY() {
    return posy;
}
//===============================================
double GScara::getZ() {
    return posz;
}
//===============================================
void GScara::setTh1(double _th1) {
    th1 = _th1;
    kinPr();
}
//===============================================
void GScara::setTh2(double _th2) {
    th2 = _th2;
    kinPr();
}
//===============================================
void GScara::setZ(double _z) {
    z = _z;
    kinPr();
}
//===============================================
void GScara::setMode(eGSteeringMode _mode) {
    m_mode = _mode;
}
//===============================================
void GScara::setTarget(double _tx, double _ty, double _tz) {
    tx = _tx;
    ty = _ty;
    tz = _tz;
}
//===============================================
void GScara::kinPr() {
    posx = r1 * cos(M_PI*th1/180.0) + r2 * cos(M_PI*(th1+th2)/180.0);
    posy = r1 * sin(M_PI*th1/180.0) + r2 * sin(M_PI*(th1+th2)/180.0);
    posz = z;
}
//===============================================
void GScara::onUpdate(double dt) {
    if(m_mode == TARGET) {
        double rx = tx - posx;
        double ry = ty - posy;
        double rz = tz - posz;

        double vmax = 0.5;

        double v = sqrt(rx*rx + ry*ry + rz*rz);

        rx *= vmax/v;
        ry *= vmax/v;
        rz *= vmax/v;

        calcSpeed(rx, ry, rz);
    }
    else {
        dth1 = 0.0;
        dth2 = 0.0;
        dz = 0.0;
    }

    th1 += dt * dth1;
    th2 += dt * dth2;
    z += dt * dz;

    if(th1 > 180.0) th1 -= 360.0;
    if(th1 < -180.0) th1 += 360.0;
    if(th2 > 180.0) th2 -= 360.0;
    if(th2 < -180.0) th2 += 360.0;

    if(z < 0.0) z = 0.0;
    if(z > 0.5) z = 0.5;

    kinPr();

    sGPathPoint p = { posx, posy, posz };
    m_path.push_back(p);

    if(m_path.size() > 10000) m_path.erase(m_path.begin());
}
//===============================================
bool GScara::calcSpeed(double vx, double vy, double vz) {
    double sth1 = sin(M_PI*th1/180.0);
    double cth1 = cos(M_PI*th1/180.0);
    double sth12 = sin(M_PI*(th1+th2)/180.0);
    double cth12 = cos(M_PI*(th1+th2)/180.0);

    double det = (-r1*sth1-r2*sth12) * (r2*cth12) + (r2*sth12) * (r1*cth1+r2*cth12);

    if(!det) {
        dth1 = 0.0;
        dth2 = 0.0;
        dz = 0.0;
        return false;
    }

    double t11 = r2*cth12/det;
    double t12 = r2*sth12/det;
    double t21 = -(r1*cth1+r2*cth12)/det;
    double t22 = -(r1*sth1+r2*sth12)/det;

    dth1 = t11*vx + t12*vy;
    dth2 = t21*vx + t22*vy;
    dz = vz;

    dth1 *= 180.0/M_PI;
    dth2 *= 180.0/M_PI;

    return true;
}
//===============================================
void GScara::display() {
    m_baseModel.display();

    glTranslatef(0.0, 0.0, 0.9);
    glRotatef(th1, 0.0, 0.0, 1.0);
    m_arm1Model.display();

    glTranslatef(0.0, -r1, 0.1);
    glRotatef(th2, 0.0, 0.0, 1.0);
    m_arm2Model.display();

    glTranslatef(0.0, -r2, -0.5 + z);
    m_arm3Model.display();
}
//===============================================
void GScara::displayPath() {
    std::vector<sGPathPoint>::iterator i;
    glBegin(GL_LINE_STRIP);
    for(i = m_path.begin(); i < m_path.end(); ++i) {
        glVertex3f(i->y, -i->x, i->z+0.5);
    }
    glEnd();
}
//===============================================
