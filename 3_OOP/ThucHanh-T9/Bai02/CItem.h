#ifndef _CITEM_H
#define _CITEM_H

#include <string>

using namespace std;

class CFolder;

class CItem
{
      private:
	string m_name;
	int m_size;
	bool m_ReadOnly;
	bool m_Hidden;

      protected:
	CItem(const string &, int size);

      public:
	virtual void addSize(CItem *);
	virtual void removeSize(CItem *);
	virtual bool sameName(const string &);
	virtual void printName();
	virtual CFolder *getFolder()
	{
		return NULL;
	}
	virtual void setHiddenThis(bool thisItem);
	virtual bool isHidden()
	{
		return m_Hidden;
	}

	// main func
	virtual void add(CItem *){};
	virtual CItem *removeByName(string const &)
	{
		return NULL;
	};
	virtual CItem *findByName(string const &)
	{
		return NULL;
	};
	virtual void setHidden(bool thisItem, bool subItem){};
	virtual void print(bool onlySubFiles){};
};

#endif