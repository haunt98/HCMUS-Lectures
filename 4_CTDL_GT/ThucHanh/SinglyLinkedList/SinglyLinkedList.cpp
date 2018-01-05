#include "SinglyLinkedList.h"
#include <iostream>
using namespace std;

// 01. Hàm so sánh 2 biến kiểu cấu trúc cho trước
// Đầu vào: biến cấu trúc (info1) và biến cấu trúc (info2)
// Đầu ra:	0 (bằng nhau), -1 (info1 nhỏ hơn info2), 1 (info1 lớn hơn info2)
int CompareData(Data info1, Data info2)
{
	if (info1.x < info2.x) {
		return -1;
	} else if (info1.x == info2.x) {
		return 0;
	}
	return 1;
}

// 02. Hàm khởi tạo DSLK (rỗng)
// Đầu vào:	tham chiếu đến DSLK cần khởi tạo (l)
// Đầu ra:	Không có
void InitList(List &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

// 03. Hàm kiểm tra DSLK cho trước có phải là DSLK rỗng hay không?
// Đầu vào:	DSLK cần kiểm tra (l)
// Đầu ra:	DSLK rỗng hay không (true/false)
bool IsEmptyList(List l)
{
	return l.pHead == NULL && l.pTail == NULL;
}

// 04. Hàm in DSLK cho trước
// Đầu vào: DSLK cần in (l) kèm theo chuỗi thông báo (str)
// Đầu ra:	Không có
void PrintList(List l, char *str)
{
	cout << str;
	Node *temp = l.pHead;
	while (temp && temp->pNext) {
		cout << temp->info.x << "->";
		temp = temp->pNext;
	}
	if (temp)
		cout << temp->info.x << endl;
}

// 05. Hàm tạo một nút mới với dữ liệu cho trước
// Đầu vào:	Dữ liệu của nút (info)
// Đầu ra:	Con trỏ đến nút đó (trả về NULL nếu không tạo được)
Node *CreateNode(Data info)
{
	Node *temp = new Node;
	if (!temp) // Khong tao duoc
	{
		return NULL;
	}
	temp->info = info;
	temp->pNext = NULL;
	return temp;
}

// 06. Hàm tìm nút đầu tiên trong DSLK cho trước có dữ liệu cho trước
// Đầu vào:	DSLK (l), dữ liệu của nút cần tìm (info)
// Đầu ra:	Con trỏ đến nút tìm được (trả về NULL nếu không tìm được)
Node *GetNodePointer(List l, Data info)
{
	Node *temp = l.pHead;
	while (temp) {
		if (temp->info.x == info.x) {
			return temp;
		}
		temp = temp->pNext;
	}
	return NULL;
}

// 07. Hàm tìm nút có chỉ số (bắt đầu từ 0) cho trước
// Đầu vào:	DSLK (l), chỉ số của nút cần lấy (index)
// Đầu ra:	Con trỏ đến nút tìm được (trả về NULL nếu không tìm được)
Node *GetNodePointer(List l, int index)
{
	Node *temp = l.pHead;
	int count = 0;
	while (temp) {
		temp = temp->pNext;
		++count;
		if (count == index) {
			return temp;
		}
	}
	return NULL;
}

// 08. Hàm xác định vị trí của một nút cho trước trong DSLK cho trước
// Đầu vào:	DSLK (l), con trỏ đến nút cần xác định vị trí (pNode)
// Đầu ra:	Thứ tự của nút cho trước (trả về -1 nếu nút này không có trong
// DSLK)
int GetNodeIndex(List l, Node *pNode)
{
	Node *temp = l.pHead;
	int index = 0;
	while (temp) {
		if (temp == pNode) {
			return index;
		}
		temp = temp->pNext;
		index++;
	}
	return -1;
}

// 09. Hàm xác định con trỏ đến nút đứng trước của một nút cho trước trong DSLK
// Đầu vào:	DSLK (l), con trỏ đến nút cho trước (pNode)
// Đầu ra:	Con trỏ đến nút tìm được (trả về NULL nếu không tìm được)
Node *GetPreviousNodePointer(List l, Node *pNode)
{
	Node *temp = l.pHead;
	while (temp) {
		if (temp->pNext == pNode) {
			return temp;
		}
		temp = temp->pNext;
	}
	return NULL;
}

// 10. Hàm chèn một nút cho trước vào đầu DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cần chèn (pNewNode)
// Đầu ra:	Không có
void AddHead(List &l, Node *pNewNode)
{
	if (!pNewNode) {
		return;
	}
	if (IsEmptyList(l)) {
		l.pHead = pNewNode;
		l.pTail = pNewNode;
	} else {
		pNewNode->pNext = l.pHead;
		l.pHead = pNewNode;
	}
}

// 11. Hàm chèn một nút có dữ liệu cho trước vào đầu DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), dữ liệu của nút cần chèn (info)
// Đầu ra:	Con trỏ đến nút được chèn (trả về NULL nếu không chèn được)
Node *AddHead(List &l, Data info)
{
	Node *pNewNode = CreateNode(info);
	if (!pNewNode) {
		return NULL;
	}
	AddHead(l, pNewNode);
	return pNewNode;
}

// 12. Hàm chèn một nút cho trước vào cuối DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cần chèn (pNewNode)
// Đầu ra:	Không có
void AddTail(List &l, Node *pNewNode)
{
	if (!pNewNode) {
		return;
	}
	if (IsEmptyList(l)) {
		l.pHead = pNewNode;
		l.pTail = pNewNode;
	} else {
		l.pTail->pNext = pNewNode;
		l.pTail = pNewNode;
	}
}

// 13. Hàm chèn một nút có dữ liệu cho trước vào cuối DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), dữ liệu của nút cần chèn (info)
// Đầu ra:	Con trỏ đến nút được chèn (trả về NULL nếu không chèn được)
Node *AddTail(List &l, Data info)
{
	Node *pNewNode = CreateNode(info);
	if (!pNewNode) {
		return NULL;
	}
	AddTail(l, pNewNode);
	return pNewNode;
}

// 14. Hàm chèn một nút cho trước vào sau một nút khác cho trước
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cho trước (q), con trỏ
// đến nút cần chèn (pNewNode) Đầu ra:	Không có
void AddAfter(List &l, Node *q, Node *pNewNode)
{
	if (IsEmptyList(l) || !pNewNode || !q) {
		return;
	}
	pNewNode->pNext = q->pNext;
	q->pNext = pNewNode;
	if (!pNewNode->pNext) {
		l.pTail = pNewNode;
	}
}

// 15. Hàm chèn một nút có dữ liệu cho trước vào sau một nút khác cho trước
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cho trước (q), dữ liệu
// của nút cần chèn (info) Đầu ra:	Con trỏ đến nút được chèn (trả về NULL
// nếu không chèn được)
Node *AddAfter(List &l, Node *q, Data info)
{
	Node *pNewNode = CreateNode(info);
	if (IsEmptyList(l) || !pNewNode || !q) {
		return NULL;
	}
	AddAfter(l, q, pNewNode);
	return pNewNode;
}

// 16. Hàm chèn một nút cho trước vào trước một nút khác cho trước
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cho trước (q), con trỏ
// đến nút cần chèn (pNewNode) Đầu ra:	Không có
void AddBefore(List &l, Node *q, Node *pNewNode)
{
	if (IsEmptyList(l) || !pNewNode || !q) {
		return;
	}
	if (q == l.pHead) {
		AddHead(l, pNewNode);
	} else {
		Node *temp = l.pHead;
		while (temp->pNext) {
			if (temp->pNext == q) {
				break;
			}
			temp = temp->pNext;
		}
		pNewNode->pNext = temp->pNext;
		temp->pNext = pNewNode;
	}
}

// 17. Hàm chèn một nút có dữ liệu cho trước vào trước một nút khác cho trước
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cho trước (q), dữ liệu
// của nút cần chèn (info) Đầu ra:	Con trỏ đến nút được chèn (trả về NULL
// nếu không chèn được)
Node *AddBefore(List &l, Node *q, Data info)
{
	Node *pNewNode = CreateNode(info);
	if (IsEmptyList(l) || !pNewNode || !q) {
		return NULL;
	}
	AddBefore(l, q, pNewNode);
	return pNewNode;
}

// 18. Hàm chèn một nút cho trước sao cho DSLK cho trước vẫn tăng dần
// Đầu vào: Tham chiếu đến DSLK (l), con trỏ đến nút cần chèn (pNewNode)
// Đầu ra:	Không có
void AddAscendingList(List &l, Node *pNewNode)
{
	if (!pNewNode) {
		return;
	}
	if (IsEmptyList(l)) {
		AddHead(l, pNewNode);
		return;
	}

	// Temp tro vao head
	Node *temp = CreateNode(Data{-1});
	temp->pNext = l.pHead;

	// Linh canh o vi tri cuoi
	Node *sentinel = CreateNode(Data(pNewNode->info));
	l.pTail->pNext = sentinel;

	Node *prev = temp;
	Node *cur = temp->pNext;
	while (CompareData(cur->info, pNewNode->info) == -1) // be hon
	{
		prev = cur;
		cur = cur->pNext;
	}
	// Dung khi prev < pNewNode < cur
	prev->pNext = pNewNode;
	pNewNode->pNext = cur;

	// Cac truong hop dac bie
	if (pNewNode->pNext == l.pHead) {
		l.pHead = pNewNode;
	}
	if (pNewNode->pNext == sentinel) // neu chen vao tail
	{
		l.pTail = pNewNode;
	}
	l.pTail->pNext = NULL;

	delete sentinel;
	delete temp;
}

// 19. Hàm chèn một nút có dữ liệu cho trước sao cho DSLK cho trước vẫn tăng dần
// Đầu vào: Tham chiếu đến DSLK (l), dữ liệu của nút cần chèn (info)
// Đầu ra:	Con trỏ đến nút được chèn (trả về NULL nếu không chèn được)
Node *AddAscendingList(List &l, Data info)
{
	Node *pNewNode = CreateNode(info);
	if (!pNewNode) {
		return NULL;
	}
	AddAscendingList(l, pNewNode);
	return pNewNode;
}

// 20. Hàm hủy một nút đầu DSLK
// Đầu vào:	Tham chiếu đến DSLK (l)
// Đầu ra:	Con trỏ đến nút bị hủy (nếu có)
Node *RemoveHead(List &l)
{
	if (IsEmptyList(l)) {
		return NULL;
	}
	Node *temp = l.pHead;
	if (l.pHead == l.pTail) // 1 elem
	{
		l.pHead = l.pTail = NULL;
	} else {
		l.pHead = l.pHead->pNext;
	}
	return temp;
}

// 21. Hàm hủy một nút cuối DSLK
// Đầu vào:	Tham chiếu đến DSLK (l)
// Đầu ra:	Con trỏ đến nút bị hủy (nếu có)
Node *RemoveTail(List &l)
{
	if (l.pHead == l.pTail) // empty and 1 elem
	{
		return RemoveHead(l);
	}
	Node *temp = l.pHead;
	while (temp->pNext != l.pTail) {
		temp = temp->pNext;
	}
	Node *tail = l.pTail;
	l.pTail = temp;
	temp->pNext = NULL;
	return tail;
}

// 22. Hàm hủy một nút đứng sau một nút cho trước trong DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cho trước (q)
// Đầu ra:	Con trỏ đến nút bị hủy (nếu có)
Node *RemoveAfter(List &l, Node *q)
{
	if (IsEmptyList(l) || !q->pNext) {
		return NULL;
	}
	if (q->pNext == l.pTail) {
		return RemoveTail(l);
	}
	Node *temp = q->pNext;
	q->pNext = temp->pNext;
	return temp;
}

// 23. Hàm hủy một nút có dữ liệu cho trước trong DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), dữ liệu của nút cần xóa (info)
// Đầu ra:	Con trỏ đến nút bị hủy (nếu có)
Node *RemoveNode(List &l, Data info)
{
	if (CompareData(l.pHead->info, info) == 0) {
		return RemoveHead(l);
	}
	Node *temp = l.pHead;
	while (temp->pNext) {
		if (CompareData(temp->pNext->info, info) == 0) {
			return RemoveAfter(l, temp);
		}
		temp = temp->pNext;
	}
	return NULL;
}

// 24. Hàm hủy toàn bộ DSLK cho trước
// Đầu vào:	Tham chiếu đến DSLK (l)
// Đầu ra:	Không có
void RemoveAll(List &l)
{
	l.pTail = NULL;
	while (l.pHead) {
		Node *temp = l.pHead;
		l.pHead = l.pHead->pNext;
		delete temp;
	}
}