#ifndef _CFOLDER_H
#define _CFOLDER_H

#include "CItem.h"
#include <vector>

class CFolder : public CItem
{
protected:
    vector<CItem *> m_ds;

public:
    CFolder(const string &name);
    CFolder *getFolder() { return this; }
    void printName();

    // main func
    void add(CItem *);
    CItem *removeByName(string const &);
    CItem *findByName(string const &);
    void setHidden(bool thisItem, bool subItem);
    void print(bool onlySubFiles);
};

#endif