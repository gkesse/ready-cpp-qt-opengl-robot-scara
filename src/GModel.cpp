//===============================================
#include "GModel.h"
//===============================================
static void replace(std::string& _str, const char _from, const char _to);
//===============================================
GModel::GModel(QObject* _parent)
: QObject(_parent) {

}
//===============================================
GModel::~GModel() {

}
//===============================================
void GModel::load(const std::string& _filename) {
    m_materials.clear();
    m_vertex.clear();
    m_faces.clear();
    m_normals.clear();

    std::ifstream file(_filename.c_str());

    if(!file) {
        qDebug() << "Le fichier n'a pas été trouvé.";
        exit(-1);
    }

    std::string s;
    int current_material = -1;

    while(getline(file, s)) {
        replace(s, '/', ' ');

        std::stringstream sstr;
        sstr << s;

        std::string cmd;
        sstr >> cmd;

        if(cmd == "mtllib") {
            std::string matfile;
            sstr >> matfile;
            loadMaterials(matfile);
        }

        if(cmd == "v") {
            sGVertex vtx;
            sstr >> vtx.x[0] >> vtx.x[1] >> vtx.x[2];
            m_vertex.push_back(vtx);
        }

        if(cmd == "vn") {
            sGVertex nrm;
            sstr >> nrm.x[0] >> nrm.x[1] >> nrm.x[2];

            for(int i = 0; i < 3; nrm.x[i++] *= -1);

            nrm.x[0] *= -1;
            nrm.x[1] *= -1;
            nrm.x[2] *= -1;

            m_normals.push_back(nrm);
        }

        if(cmd == "f") {
            sGFace face;

            for(int i = 0; i < 3; ++i) {
                sstr >> face.vertex[i] >> face.normal;
            }

            face.material = current_material;
            m_faces.push_back(face);
        }

        if(cmd == "usemtl") {
            std::string matname;
            sstr >> matname;

            int i = 0;
            for(; i < (int)m_materials.size(); ++i) {
                if(matname == m_materials[i].name) break;
            }

            current_material = i;
        }
    }

    file.close();
}
//===============================================
void GModel::loadMaterials(const std::string& _filename) {
    std::string lFilename = "data/obj/" + _filename;

    std::ifstream file(lFilename.c_str());

    if(!file) {
        qDebug() << "Le fichier n'a pas été trouvé.";
        exit(-1);
    }

    std::string line;
    sGMaterial nmat;

    while(getline(file, line)) {
        std::stringstream sstr;
        sstr << line;

        std::string cmd;
        sstr >> cmd;

        if(cmd == "newmtl") {
            sstr >> nmat.name;
        }

        if(cmd == "Ns") {
            sstr >> nmat.shininess;
        }

        if(cmd == "Ka") {
            sstr >> nmat.ambient[0] >> nmat.ambient[1] >> nmat.ambient[2];
        }

        if(cmd == "Kd") {
            sstr >> nmat.diffuse[0] >> nmat.diffuse[1] >> nmat.diffuse[2];
        }

        if(cmd == "Ks") {
            sstr >> nmat.specular[0] >> nmat.specular[1] >> nmat.specular[2];
        }

        if(cmd == "d") {
            float alpha;
            sstr >> alpha;
            nmat.ambient[3] = alpha;
            nmat.diffuse[3] = alpha;
            nmat.specular[3] = alpha;
        }

        if(cmd == "illum") {
            m_materials.push_back(nmat);
        }
    }

    file.close();
}
//===============================================
void GModel::display() {
    GLfloat emiss[4] = { 0.0, 0.0, 0.0, 0.0 };

    glBegin(GL_TRIANGLES);

    int current_material = -1;

    std::vector<sGFace>::iterator i;
    for(i = m_faces.begin(); i < m_faces.end(); ++i) {
        int mat = (*i).material;

        if(current_material != mat) {
            sGMaterial m = m_materials[mat];

            glEnd();
            glMaterialfv(GL_FRONT, GL_AMBIENT, m.diffuse);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, m.diffuse);
            glMaterialfv(GL_FRONT, GL_SPECULAR, m.specular);
            glMaterialfv(GL_FRONT, GL_EMISSION, emiss);
            glMaterialfv(GL_FRONT, GL_SHININESS, &m.shininess);

            current_material = mat;
            glBegin(GL_TRIANGLES);
        }

        int n_normal = (*i).normal - 1;

        glNormal3fv(m_normals[n_normal].x);

        for(int j = 0; j < 3; ++j) {
            int n_vtx = (*i).vertex[j] - 1;
            glVertex3fv(m_vertex[n_vtx].x);
        }
    }

    glEnd();
}
//===============================================
void replace(std::string& _str, const char _from, const char _to) {
    std::string::iterator i;
    for(i = _str.begin(); i < _str.end(); ++i)
        if(*i == _from) *i = _to;
}
//===============================================
