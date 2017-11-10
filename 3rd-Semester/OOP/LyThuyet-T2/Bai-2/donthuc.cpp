#include "donthuc.h"
#include <iostream>

using namespace std;

void DonThuc::nhap() {
    cout << "Nhap he so : ";
    cin >> this->m_heso;
    cout << "Nhap so mu : ";
    cin >> this->m_mu;
}

void DonThuc::xuat() { cout << this->m_heso << "x^" << this->m_mu; }

float DonThuc::layHeso() { return this->m_heso; }

int DonThuc::layMu() { return this->m_mu; }

void DonThuc::ganHeso(float heso) { this->m_heso = heso; }

void DonThuc::ganMu(int mu) { this->m_mu = mu; }

DonThuc DonThuc::daoham() {
    DonThuc temp;
    temp.m_heso = this->m_heso * this->m_mu;
    temp.m_mu = this->m_mu - 1;
    return temp;
}

DonThuc DonThuc::cong(DonThuc p) {
    DonThuc tong;
    tong.m_heso = this->m_heso + p.m_heso;
    tong.m_mu = this->m_mu;
    return tong;
}

DonThuc DonThuc::nhan(DonThuc p) {
    DonThuc tich;
    tich.m_heso = this->m_heso * p.m_heso;
    tich.m_mu = this->m_mu + p.m_mu;
    return tich;
}

int DonThuc::sosanh(DonThuc p) {
    if (this->m_mu < p.m_mu)
        return -1;
    else if (this->m_mu > p.m_mu)
        return 1;
    return 0;
}
