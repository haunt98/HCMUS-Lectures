#include "Animal.h"

int Bao::speed()
{
    return 100;
}

int LinhDuong::speed()
{
    return 80;
}

int SuTu::speed()
{
    return 70;
}

int Cho::speed()
{
    return 60;
}

int Nguoi::speed()
{
    return 30;
}

int Ngua::speed()
{
    return 60;
}

int soSanh(Animal *a1, Animal *a2)
{
    if (a1->speed() < a2->speed())
        return -1;
    if (a1->speed() == a2->speed())
        return 0;
    return 1;
}
