#ifndef _CFILE_H
#define _CFILE_H

#include "CItem.h"

class CFile : public CItem
{
      public:
	CFile(const string &name, int size);
	void addSize(CItem *){};
	void removeSize(CItem *){};
};

#endif