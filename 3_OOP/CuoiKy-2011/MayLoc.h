#ifndef _MAY_LOC_H
#define _MAY_LOC_H

class MayLoc
{
private:
    float m_tgian;

protected:
    virtual float congSuat() { return 0; }
    void setTgian(float t) { m_tgian = t; }

public:
    MayLoc() { m_tgian = 0; }
    float getTgian() { return m_tgian; }
    float tinhLuongNuoc() { return congSuat() * m_tgian; }
    virtual ~MayLoc() {}
};

class MayLyTam : public MayLoc
{
private:
    float m_cs;

protected:
    float congSuat() { return m_cs; }

public:
    MayLyTam(float cs, float t)
    {
        m_cs = cs;
        setTgian(t);
    }
    ~MayLyTam() {}
};

class MayXucTac : public MayLoc
{
private:
    float m_cs;
    float m_hoaChat;

protected:
    float congSuat(); // cong suat thuc te;
    float chiPhiThue();

public:
    static float DON_GIA_THUE;
    static float DON_GIA_HOA_CHAT;
    MayXucTac() {}
    ~MayXucTac() {}
    void nhap();
    float tinhChiPhi(); // chi phi su dung
};

#endif
