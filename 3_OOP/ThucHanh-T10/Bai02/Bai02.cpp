// 1612180
// Nguyễn Trần Hậu
// Bài 2

#include <iostream>

using namespace std;

class Base
{
      public:
	Base()
	{
		cout << "Base cto" << endl;
	}
	virtual ~Base()
	{
		cout << "Base dto" << endl;
	}
};

class Derived : public Base
{
      public:
	Derived()
	{
		cout << "Derived cto" << endl;
	}
	~Derived()
	{
		cout << "Derived dto" << endl;
	}
};

int main()
{
	Base *a = new Derived();
	delete a;
	return 0;
}

// Nếu trong class Base, hàm hủy không có virtual thì khi delete a
// chương trình chỉ thực hiện hàm hủy của Base mà không thực hiện hàm
// hủy của Derived, dẫn tới việc có thể rò rỉ dữ liệu