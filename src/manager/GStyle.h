#ifndef _GStyle_
#define _GStyle_

class GStyle {
private:
    GStyle();

public:
    ~GStyle();

public:
    static GStyle* Instance();

public:
    void load();

private:
    static GStyle* m_instance;
};

#endif
