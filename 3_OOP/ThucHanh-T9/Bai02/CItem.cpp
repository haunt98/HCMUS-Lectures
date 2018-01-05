#include "CItem.h"
#include <iostream>

CItem::CItem(const string &name, int size) : m_name(name)
{
	m_size = size;
	m_ReadOnly = false;
	m_Hidden = false;
}

void CItem::addSize(CItem *item)
{
	m_size += item->m_size;
}

void CItem::removeSize(CItem *item)
{
	m_size -= item->m_size;
}

bool CItem::sameName(const string &name)
{
	return m_name == name;
}

void CItem::printName()
{
	cout << m_name;
}

void CItem::setHiddenThis(bool thisItem)
{
	m_Hidden = thisItem;
}