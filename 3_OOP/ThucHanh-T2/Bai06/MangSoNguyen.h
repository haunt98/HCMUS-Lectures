#ifndef MANGSONGUYEN_H
#define MANGSONGUYEN_H

class MangSoNguyen
{
      private:
	int m_size;
	int *m_arr;

      public:
	void Xuat();
	MangSoNguyen();
	MangSoNguyen(int size);
	MangSoNguyen(int *arr, int size);
	MangSoNguyen(const MangSoNguyen &mang);
	~MangSoNguyen();
};

#endif