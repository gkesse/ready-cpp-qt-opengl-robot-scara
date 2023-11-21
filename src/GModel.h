//===============================================
#ifndef _GModel_
#define _GModel_
//===============================================
#include "GInclude.h"
//===============================================
class GModel : public QObject {
    Q_OBJECT

public:
    struct sGMaterial {
        std::string name;
        GLfloat ambient[4];
        GLfloat diffuse[4];
        GLfloat specular[4];
        GLfloat shininess;
    };

    struct sGVertex {
        GLfloat x[3];
    };

    struct sGFace {
        int normal;
        int vertex[3];
        int material;
    };

public:
    explicit GModel(QObject* _parent = nullptr);
    ~GModel();
    void load(const std::string& _filename);
    void loadMaterials(const std::string& _filename);
    void display();

private:
    std::vector<sGMaterial> m_materials;
    std::vector<sGVertex> m_vertex;
    std::vector<sGVertex> m_normals;
    std::vector<sGFace> m_faces;
};
//===============================================
#endif
//===============================================
