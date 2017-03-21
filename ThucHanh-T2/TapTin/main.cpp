#include "ham.h"

int main(void)
{
	// replace char old to char new
	replaceChar("replace.txt", 'b', '3');
	// copy A.txt to B.txt
	copyFile("A.txt", "B.txt");
	// sap xep phan so trong file inps.txt -> outps.txt
	sortFilePhanSo("inps.txt", "outps.txt");
	// thong ke file thkein.txt -> thkeout.txt
	ThongKe("thkein.txt", "thkeout.txt");
	return 0;
}