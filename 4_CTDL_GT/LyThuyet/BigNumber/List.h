#ifndef _list_h
#define _list_h

// Node
typedef struct Node *pNode;
struct Node {
	int d;
	pNode pPrev;
	pNode pNext;
};

pNode getNode(int d);

// List
struct List {
	// element
	pNode pHead;
	pNode pTail;
	int count;
	// func
	List();
	~List();
	void addHead(int d);
	void addTail(int d);
	void print();
	bool isEmpty();
	void del();
	void delHead();

	// So sanh
	bool operator==(const List &);
	bool operator<(const List &);

	// Operator
	List &operator=(const List &);
	List &operator+=(const List &);
	List &operator-=(const List &);
};

#endif