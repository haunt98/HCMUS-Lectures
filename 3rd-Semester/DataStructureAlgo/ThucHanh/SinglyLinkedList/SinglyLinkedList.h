#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Danh sách liên kết (DSLK) đơn
typedef struct
{
    int x;
} Data;

typedef struct tagNode
{
    Data info;
    struct tagNode *pNext;
} Node;

typedef struct tagList
{
    Node *pHead;
    Node *pTail;
} List;

// 01. Hàm so sánh 2 biến kiểu cấu trúc cho trước
// Đầu vào: biến cấu trúc (info1) và biến cấu trúc (info2)
// Đầu ra:	0 (bằng nhau), -1 (info1 nhỏ hơn info2), 1 (info1 lớn hơn info2)
int CompareData(Data info1, Data info2);

// 02. Hàm khởi tạo DSLK (rỗng)
// Đầu vào:	tham chiếu đến DSLK cần khởi tạo (l)
// Đầu ra:	Không có
void InitList(List &l);

// 03. Hàm kiểm tra DSLK cho trước có phải là DSLK rỗng hay không?
// Đầu vào:	DSLK cần kiểm tra (l)
// Đầu ra:	DSLK rỗng hay không (true/false)
bool IsEmptyList(List l);

// 04. Hàm in DSLK cho trước
// Đầu vào: DSLK cần in (l) kèm theo chuỗi thông báo (str)
// Đầu ra:	Không có
void PrintList(List l, char *str);

// 05. Hàm tạo một nút mới với dữ liệu cho trước
// Đầu vào:	Dữ liệu của nút (info)
// Đầu ra:	Con trỏ đến nút đó (trả về NULL nếu không tạo được)
Node *CreateNode(Data info);

// 06. Hàm tìm nút đầu tiên trong DSLK cho trước có dữ liệu cho trước
// Đầu vào:	DSLK (l), dữ liệu của nút cần tìm (info)
// Đầu ra:	Con trỏ đến nút tìm được (trả về NULL nếu không tìm được)
Node *GetNodePointer(List l, Data info);

// 07. Hàm tìm nút có chỉ số (bắt đầu từ 0) cho trước
// Đầu vào:	DSLK (l), chỉ số của nút cần lấy (index)
// Đầu ra:	Con trỏ đến nút tìm được (trả về NULL nếu không tìm được)
Node *GetNodePointer(List l, int index);

// 08. Hàm xác định vị trí của một nút cho trước trong DSLK cho trước
// Đầu vào:	DSLK (l), con trỏ đến nút cần xác định vị trí (pNode)
// Đầu ra:	Thứ tự của nút cho trước (trả về -1 nếu nút này không có trong
// DSLK)
int GetNodeIndex(List l, Node *pNode);

// 09. Hàm xác định con trỏ đến nút đứng trước của một nút cho trước trong DSLK
// Đầu vào:	DSLK (l), con trỏ đến nút cho trước (pNode)
// Đầu ra:	Con trỏ đến nút tìm được (trả về NULL nếu không tìm được)
Node *GetPreviousNodePointer(List l, Node *pNode);

// 10. Hàm chèn một nút cho trước vào đầu DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cần chèn (pNewNode)
// Đầu ra:	Không có
void AddHead(List &l, Node *pNewNode);

// 11. Hàm chèn một nút có dữ liệu cho trước vào đầu DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), dữ liệu của nút cần chèn (info)
// Đầu ra:	Con trỏ đến nút được chèn (trả về NULL nếu không chèn được)
Node *AddHead(List &l, Data info);

// 12. Hàm chèn một nút cho trước vào cuối DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cần chèn (pNewNode)
// Đầu ra:	Không có
void AddTail(List &l, Node *pNewNode);

// 13. Hàm chèn một nút có dữ liệu cho trước vào cuối DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), dữ liệu của nút cần chèn (info)
// Đầu ra:	Con trỏ đến nút được chèn (trả về NULL nếu không chèn được)
Node *AddTail(List &l, Data info);

// 14. Hàm chèn một nút cho trước vào sau một nút khác cho trước
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cho trước (q), con trỏ
// đến nút cần chèn (pNewNode) Đầu ra:	Không có
void AddAfter(List &l, Node *q, Node *pNewNode);

// 15. Hàm chèn một nút có dữ liệu cho trước vào sau một nút khác cho trước
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cho trước (q), dữ liệu
// của nút cần chèn (info) Đầu ra:	Con trỏ đến nút được chèn (trả về NULL
// nếu không chèn được)
Node *AddAfter(List &l, Node *q, Data info);

// 16. Hàm chèn một nút cho trước vào trước một nút khác cho trước
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cho trước (q), con trỏ
// đến nút cần chèn (pNewNode) Đầu ra:	Không có
void AddBefore(List &l, Node *q, Node *pNewNode);

// 17. Hàm chèn một nút có dữ liệu cho trước vào trước một nút khác cho trước
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cho trước (q), dữ liệu
// của nút cần chèn (info) Đầu ra:	Con trỏ đến nút được chèn (trả về NULL
// nếu không chèn được)
Node *AddBefore(List &l, Node *q, Data info);

// 18. Hàm chèn một nút cho trước sao cho DSLK cho trước vẫn tăng dần
// Đầu vào: Tham chiếu đến DSLK (l), con trỏ đến nút cần chèn (pNewNode)
// Đầu ra:	Không có
void AddAscendingList(List &l, Node *pNewNode);

// 19. Hàm chèn một nút có dữ liệu cho trước sao cho DSLK cho trước vẫn tăng dần
// Đầu vào: Tham chiếu đến DSLK (l), dữ liệu của nút cần chèn (info)
// Đầu ra:	Con trỏ đến nút được chèn (trả về NULL nếu không chèn được)
Node *AddAscendingList(List &l, Data info);

// 20. Hàm hủy một nút đầu DSLK
// Đầu vào:	Tham chiếu đến DSLK (l)
// Đầu ra:	Con trỏ đến nút bị hủy (nếu có)
Node *RemoveHead(List &l);

// 21. Hàm hủy một nút cuối DSLK
// Đầu vào:	Tham chiếu đến DSLK (l)
// Đầu ra:	Con trỏ đến nút bị hủy (nếu có)
Node *RemoveTail(List &l);

// 22. Hàm hủy một nút đứng sau một nút cho trước trong DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cho trước (q)
// Đầu ra:	Con trỏ đến nút bị hủy (nếu có)
Node *RemoveAfter(List &l, Node *q);

// 23. Hàm hủy một nút có dữ liệu cho trước trong DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), dữ liệu của nút cần xóa (info)
// Đầu ra:	Con trỏ đến nút bị hủy (nếu có)
Node *RemoveNode(List &l, Data info);

// 24. Hàm hủy toàn bộ DSLK cho trước
// Đầu vào:	Tham chiếu đến DSLK (l)
// Đầu ra:	Không có
void RemoveAll(List &l);

#endif