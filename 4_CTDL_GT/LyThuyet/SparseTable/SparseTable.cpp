#include "SparseTable.h"
#include <iostream>

using namespace std;

pNode getNode(int v, int i_r, int i_c)
{
	pNode temp = new Node;
	if (!temp) {
		cout << "Cant make node" << endl;
	}
	temp->val = v;
	temp->i_row = i_r;
	temp->i_col = i_c;
	temp->hNext = NULL;
	temp->vNext = NULL;
	return temp;
}

SparseTable::SparseTable(int row, int col)
{
	m_row = row;
	m_col = col;

	m_lrow = new pNode[m_row];
	m_lcol = new pNode[m_col];

	for (int i = 0; i < m_row; ++i) {
		m_lrow[i] = getNode(-1, i, -1);
		if (i > 0) {
			m_lrow[i - 1]->vNext = m_lrow[i];
		}
	}
	for (int i = 0; i < m_col; i++) {
		m_lcol[i] = getNode(-1, -1, i);
		if (i > 0) {
			m_lcol[i - 1]->hNext = m_lcol[i];
		}
	}
}

void SparseTable::add(int val, int i_row, int i_col)
{
	if (i_row < 0 || i_row >= m_row || i_col < 0 || i_col >= m_col) {
		return;
	}
	pNode newNode = getNode(val, i_row, i_col);
	// Them theo hang
	pNode r_prev = m_lrow[i_row];
	pNode r_cur = m_lrow[i_row]->hNext;
	while (r_cur && r_cur->i_col < newNode->i_col) {
		r_prev = r_cur;
		r_cur = r_cur->hNext;
	}
	r_prev->hNext = newNode;
	newNode->hNext = r_cur;
	// Them theo cot
	pNode c_prev = m_lcol[i_col];
	pNode c_cur = m_lcol[i_col]->vNext;
	while (c_cur && c_cur->i_row < newNode->i_row) {
		c_prev = c_cur;
		c_cur = c_cur->vNext;
	}
	c_prev->vNext = newNode;
	newNode->vNext = c_cur;
}

void SparseTable::del(int i_row, int i_col)
{
	if (i_row < 0 || i_row >= m_row || i_col < 0 || i_col >= m_col) {
		return;
	}
	// Xoa theo hang
	pNode r_prev = m_lrow[i_row];
	pNode r_cur = m_lrow[i_row]->hNext;
	while (r_cur && r_cur->i_col != i_col) {
		r_prev = r_cur;
		r_cur = r_cur->hNext;
	}
	if (r_cur) {
		r_prev->hNext = r_cur->hNext;
	}
	// Xoa theo cot
	pNode c_prev = m_lcol[i_col];
	pNode c_cur = m_lcol[i_col]->vNext;
	while (c_cur && c_cur->i_row != i_row) {
		c_prev = c_cur;
		c_cur = c_cur->vNext;
	}
	if (c_cur) {
		c_prev->vNext = c_cur->vNext;
		delete c_cur; // Bay gio moi xoa, tranh delete 2 lan
	}
}

void SparseTable::print()
{
	for (int i = 0; i < m_row; ++i) {
		cout << "[" << i << "]: ";
		pNode p = m_lrow[i]->hNext;
		while (p) {
			cout << p->val << " ";
			p = p->hNext;
		}
		cout << endl;
	}
}

SparseTable::~SparseTable()
{
	// Xu ly theo chieu ngang toan bo gia tri
	for (int i = 0; i < m_row; ++i) {
		pNode p = m_lrow[i];
		while (p) {
			pNode temp = p;
			p = p->hNext;
			delete temp;
		}
	}
	// Con lai la gia tri temp chieu doc
	// tao luc ban dau
	for (int i = 0; i < m_col; ++i) {
		delete m_lcol[i];
	}
	delete[] m_lrow;
	delete[] m_lcol;
}