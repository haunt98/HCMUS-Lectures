#ifndef DONTHUC_H
#define DONTHUC_H

#include <iostream>

using namespace std;

class DonThuc
{
private:
    double m_heso;
    int m_mu;

public:
    DonThuc();
    DonThuc(double heso, int mu);
    // so hoc
    DonThuc operator+(const DonThuc &dt);
    DonThuc operator*(const DonThuc &dt);
    // so sanh tra ve bool
    bool operator>(const DonThuc &dt);
    bool operator<(const DonThuc &dt);
    bool operator==(const DonThuc &dt);
    bool operator>=(const DonThuc &dt);
    bool operator<=(const DonThuc &dt);
    bool operator!=(const DonThuc &dt);
    // gan
    DonThuc &operator=(const DonThuc &dt);
    DonThuc &operator+=(const DonThuc &dt);
    DonThuc &operator*=(const DonThuc &dt);
    // mot ngoi
    DonThuc &operator++();   // prefix
    DonThuc operator++(int); // posfix
    DonThuc &operator--();
    DonThuc operator--(int);
    DonThuc operator!(); // dao ham
    // nhap xuat
    friend istream &operator>>(istream &in, DonThuc &dt);
    friend ostream &operator<<(ostream &out, const DonThuc &dt);
};

#endif
