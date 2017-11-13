#ifndef GOICUOC_H
#define GOICUOC_H

// Clone pattern
class Cloneable
{
public:
    virtual Cloneable *clone() const = 0;
};

class GoiCuocBasic : public Cloneable
{
protected:
    // Dien thoai
    int m_callTime; // Thoi gian goi (phut)

    // Internet
    int m_useNet; // Luu luong truy cap (MB)

public:
    static float MONEY_PER_MINUTE; // Don gia goi (1000 dong/phut)
    static float MONEY_PER_MB;     // Don gia truy cap (200 dong/MB)

    // Khoi tao
    GoiCuocBasic();
    GoiCuocBasic(int callTime, int useNet);
    GoiCuocBasic(const GoiCuocBasic &);

    // Tinh cuoc
    virtual float cuocDienThoai();
    virtual float cuocInternet();
    virtual float cuocTong();

    // Xu ly copy class con
    virtual GoiCuocBasic *clone() const;
};

class GoiCuocDataFree : public GoiCuocBasic
{
private:
    int m_freeNet;        // Nguong luu luong mien phi
    float m_moneyFreeNet; // Cuoc thue bao
public:
    GoiCuocDataFree();
    GoiCuocDataFree(int callTime, int useNet, int freeNet, float moneyFreeNet);
    GoiCuocDataFree(const GoiCuocDataFree &);
    float cuocInternet();

    // Xu ly copy
    virtual GoiCuocDataFree *clone() const;
};

class GoiCuocDataFix : public GoiCuocBasic
{
public:
    GoiCuocDataFix();
    GoiCuocDataFix(int callTime, int useNet);
    GoiCuocDataFix(const GoiCuocDataFix &);
    float cuocDienThoai();
    float cuocInternet();

    // Xu ly copy
    virtual GoiCuocDataFix *clone() const;
};

#endif