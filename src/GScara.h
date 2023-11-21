//===============================================
#ifndef _GScara_
#define _GScara_
//===============================================
#include "GInclude.h"
#include "GModel.h"
//===============================================
class GScara : public QObject {
    Q_OBJECT

public:
    enum eGSteeringMode {
        SIMPLE,
        TARGET
    };
    struct sGPathPoint {
        double x, y, z;
    };

public:
    explicit GScara(QObject* _parent = nullptr);
    ~GScara();

    double getTh1();
    double getTh2();

    double getX();
    double getY();
    double getZ();

    void setTh1(double _th1);
    void setTh2(double _th2);
    void setZ(double _z);
    void setMode(eGSteeringMode _mode);
    void setTarget(double _tx, double _ty, double _tz);

    void kinPr();
    void onUpdate(double dt);
    bool calcSpeed(double vx, double vy, double vz);
    void display();
    void displayPath();

private:
    double th1, th2, z;
    double dth1, dth2, dz;
    double posx, posy, posz;
    double tx, ty, tz;
    double r1, r2;

    GModel m_baseModel;
    GModel m_arm1Model;
    GModel m_arm2Model;
    GModel m_arm3Model;

    eGSteeringMode m_mode;
    std::vector<sGPathPoint> m_path;
};
//===============================================
#endif
//===============================================
