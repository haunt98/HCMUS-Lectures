#ifndef ANIMAL_H
#define ANIMAL_H

#include "an.h"
#include "dichuyen.h"

class Animal
{
};

class CaMap : public Animal, public AnTap, public Boi
{
};

class CaChep : public Animal, public AnPhieuSinh, public Boi
{
};

class SuTu : public Animal, public AnTap, public Chay
{
};

class ConBo : public Animal, public AnCo, public Chay
{
};

class CaVoi : public Animal, public AnPhieuSinh, public Boi
{
};

class ChimSe : public Animal, public AnSaubo, public Bay
{
};

class DaiBang : public Animal, public AnTap, public Bay
{
};

class CaSau : public Animal, public AnTap, public Bo, public Boi
{
};

class TacKe : public Animal, public AnTap, public Bo
{
};

class Doi : public Animal, public AnTap, public Bay
{
};

void thiBoi(Boi *dv1, Boi *dv2);
void thiBay(Bay *dv1, Bay *dv2);

#endif
