#include "CFolder.h"
#include <iostream>

using namespace std;

CFolder::CFolder(const string &name) : CItem(name, 0)
{
}

void CFolder::printName()
{
	CItem::printName();
	cout << " /";
}

// main func
void CFolder::add(CItem *item)
{
	m_ds.push_back(item);
	addSize(item);
}

CItem *CFolder::removeByName(string const &name)
{
	for (size_t i = 0; i < m_ds.size(); ++i) {
		if (m_ds[i]->sameName(name)) {
			CItem *temp = m_ds[i];
			m_ds.erase(m_ds.begin() + i);
			removeSize(temp);
			return temp;
		} else {
			// Tim trong cac thu muc con
			if (m_ds[i] == m_ds[i]->getFolder()) {
				CItem *temp = m_ds[i]->removeByName(name);
				if (temp) {
					return temp;
				}
			}
		}
	}
	return NULL;
}

CItem *CFolder::findByName(const string &name)
{
	for (size_t i = 0; i < m_ds.size(); ++i) {
		if (m_ds[i]->sameName(name)) {
			return m_ds[i];
		} else {
			// Tim trong cac thu muc con
			if (m_ds[i] == m_ds[i]->getFolder()) {
				CItem *temp = m_ds[i]->findByName(name);
				if (temp) {
					return temp;
				}
			}
		}
	}
	return NULL;
}

void CFolder::setHidden(bool thisItem, bool subItem)
{
	setHiddenThis(thisItem);
	if (subItem) {
		for (size_t i = 0; i < m_ds.size(); ++i) {
			// sub File
			if (!m_ds[i]->getFolder()) {
				setHiddenThis(thisItem);
			} else if (m_ds[i] == m_ds[i]->getFolder()) {
				m_ds[i]->setHidden(thisItem, subItem);
			}
		}
	}
}

void CFolder::print(bool onlySubFiles)
{
	if (isHidden()) {
		return;
	}

	for (size_t i = 0; i < m_ds.size(); ++i) {
		if (onlySubFiles) {
			// Chi in ra file
			if (!m_ds[i]->getFolder() && !m_ds[i]->isHidden()) {
				m_ds[i]->printName();
				cout << endl;
			}
		} else {
			// In ra file va folder ben trong
			if (!m_ds[i]->isHidden()) {
				m_ds[i]->printName();
			}
			cout << endl;
			if (m_ds[i] == m_ds[i]->getFolder()) {
				m_ds[i]->print(onlySubFiles);
			}
		}
	}
}