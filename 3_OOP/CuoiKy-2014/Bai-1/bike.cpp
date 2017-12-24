#define _CRT_SECURE_NO_WARNINGS
#include "bike.h"
#include <iostream>

using namespace std;

// Bike
Bike::Bike(char *brand)
{
    m_brand = new char[strlen(brand) + 1];
    strcpy(m_brand, brand);
}

Bike::~Bike()
{
    delete m_brand;
}

void Bike::move(int t1)
{
    cout << m_brand << ":" << t1 * 12 << " ";
}

// EBike
void EBike::move(int t2)
{
    Bike::move(t2 * 2);
}

void display(Bike &a, EBike &b)
{
    a.move(2);
    b.move(2);
}