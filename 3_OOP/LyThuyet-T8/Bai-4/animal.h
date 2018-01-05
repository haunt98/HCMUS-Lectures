#ifndef ANIMAL_H
#define ANIMAL_H

#include "an.h"
#include "dichuyen.h"
#include "sinhsan.h"

class LopCa : public ThuBoi
{
      public:
	LopCa deTrung();
};

class LopBoSat : public ThuBo, public ThuAnTap
{
      public:
	LopBoSat deTrung();
};

class ConCaMap : public LopCa
{
};

class ConCaChep : public LopCa
{
};

class ConSuTu : public ThuAnTap, public ThuDeCon
{
};

class ConBo : public ThuDeCon
{
};

class ConCaVoi : public ThuBoi, public ThuDeTrung
{
};

class ConChimSe : public ThuBay, public ThuDeCon
{
};

class ConDaiBang : public ThuBoi, public ThuDeCon
{
};

class ConCaSau : public LopBoSat
{
};

class ConTacKe : public LopBoSat
{
};

class Doi : public ThuBay, public ThuDeCon
{
};

#endif
