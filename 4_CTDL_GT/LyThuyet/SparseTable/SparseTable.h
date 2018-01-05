#ifndef _SPARSETABLE_H
#define _SPARSETABLE_H

typedef struct Node *pNode;
struct Node {
	int val;
	int i_row;
	int i_col;
	pNode hNext; // chieu ngang
	pNode vNext; // chieu doc
};

pNode getNode(int v, int i_r, int i_c);

class SparseTable
{
      private:
	int m_row;
	int m_col;
	pNode *m_lrow;
	pNode *m_lcol;

      public:
	SparseTable(int row, int col);
	void add(int val, int i_row, int i_col);
	void del(int i_row, int i_col);
	void print();
	~SparseTable();
};

#endif