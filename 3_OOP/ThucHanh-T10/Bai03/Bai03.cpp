// 1612180
// Nguyễn Trần Hậu
// Bài 3

#include <iostream>

using namespace std;

class absList
{ // Bắt đầu của lớp absList
      protected:
	int dataId;

      public:
	absList(int pId = 0)
	{
		dataId = pId;
	}
	virtual ~absList()
	{
	}
	int getData()
	{
		return dataId;
	}
	virtual absList *addFirst(int pId) = 0;
	virtual absList *getSubItem() = 0;
	virtual void showAll(ostream &) = 0;
	virtual int countAll()
	{
		return 0; // tạm thời 0 phần tử
	}
}; // Kết thức lớp absList

class simpleList : public absList
{
      public:
	simpleList(int pId) : absList(pId)
	{
	}
	virtual absList *addFirst(int pId)
	{
		dataId = pId;
		return this;
	}
	virtual absList *getSubItem()
	{
		return NULL; // Không có thành phần con
	}
	virtual void showAll(ostream &outDev)
	{
		outDev << dataId << " ";
	}
	virtual int countAll()
	{
		return 1; // Chỉ có đúng một phần tử
	}
};

// Lớp linearList
class linearList : public absList
{
	absList *subLst;

      public:
	linearList(int pId) : absList(pId)
	{
		subLst = NULL;
	}
	virtual ~linearList()
	{
		if (subLst != NULL)
			delete subLst;
	}

	virtual absList *addFirst(int pId)
	{
		linearList *Lst = new linearList(pId);
		Lst->subLst = this;
		return Lst;
	}
	virtual absList *getSubItem()
	{
		return subLst;
	}
	virtual void showAll(ostream &outDev)
	{
		if (subLst) {
			outDev << subLst->getData() << " ";
			subLst->showAll(outDev);
		} else {
			outDev << endl;
		}
	}
	virtual int countAll()
	{
		if (subLst) {
			// Tra ve 1 phan tu la subLst
			// va subLst cua chinh no
			return 1 + subLst->countAll();
		}
		// Khong co subLst
		return 0;
	}
}; // Kết thúc linearList

void main()
{
	simpleList *sLst = new simpleList(-13);
	absList *lnkLst = new linearList(37);
	for (int i = 1; i <= 8; i++) {
		lnkLst = lnkLst->addFirst(i * i - 7 * i);
	}

	// Đếm số phần tử trong lnkLst
	cout << "So phan tu trong lnkLst" << endl;
	cout << lnkLst->countAll() << endl;

	// In các phần tử trong lnkLst
	cout << "Cac phan tu trong lnkLst" << endl;
	lnkLst->showAll(cout);

	delete lnkLst;
}

// Câu a
// Không thể tạo đối tượng từ lớp absList vì đây là lớp thuần ảo
// (có sử dụng = 0 khi khai báo hàm trong lớp này)

// Câu b
// lệnh delete lnkLst gọi hàm hủy linearList 9 lần
// 8 lần đầu là do trong hàm hủy linearList
// gọi hàm delete subLst trong lớp này
// Lần cuối là hủy linearList(37) đã new

// Câu e
// Cấu trúc dữ liệu được cài đặt bởi lớp linearList
// thực chất là danh sách liên kết, mỗi phần tử thuộc lớp linearList
// chứa subLst giữ địa chỉ của một phần tử thuộc lớp linearList khác
// Mở rộng thêm, subLst không chỉ giữ địa chỉ của một lớp linearList,
// mà còn có thể giữ địa chỉ của lớp simpleList nữa
// Đây là composite design pattern