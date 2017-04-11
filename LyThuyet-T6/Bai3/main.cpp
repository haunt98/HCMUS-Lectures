#include "xuly.h"

int main(void)
{
	char main_str[MAX];
	cout << "Nhap chuoi : ";
	fgets(main_str, MAX - 1, stdin);
	int main_len = strlen(main_str);
	main_str[main_len - 1] = '\0'; --main_len;

	char sub_str[MAX];
	cout << "Nhap chuoi con : ";
	fgets(sub_str, MAX - 1, stdin);
	int sub_len = strlen(sub_str);
	sub_str[sub_len - 1] = '\0'; --sub_len;

	cout << "Vi tri chuoi con trong chuoi lon : " << findSubPos(main_str, sub_str, 0) << endl;

	cout << "Tat ca hoan vi cua chuoi : " << endl;
	printPermutation(main_str, 0, main_len - 1);

	reverseString(main_str, 0, main_len - 1);
	cout << "Chuoi dao nguoc : " << main_str << endl;

	upperWord(main_str, 0);
	cout << "Viet hoa chu cai dau cua chuoi chinh : " << main_str << endl;
}