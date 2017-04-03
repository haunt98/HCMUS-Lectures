#include "ham.h"

int *fun()
{
	int *point = (int *)malloc(sizeof *point); /* Mandatory. */
	*point = 12;
	return point;
}

int main(void)
{
	char p[10], q[] = "abcde", r[20] = "xyz", t[20] = "abababab";

	cout << "Chuoi q va chuoi r va chuoi t: " << endl;
	puts(q), puts(r); puts(t);

	cout << "Sao chep 2 ky tu cua q vao p" << endl;
	StringNCopy(p, q, 2);
	cout << "Chuoi p : " << endl;
	puts(p);

	cout << "Kiem tra 2.3 - sao chep q tu vi tri 1, 3 ky tu sang p" << endl;
	CopySubString(p, q, 1, 3);
	cout << "Chuoi p : " << endl;
	puts(p);

	cout << "Sao chep q vao p" << endl;
	StringCopy(p, q);
	cout << "Chuoi p : " << endl;
	puts(p);

	cout << "Kiem tra 2.4 - chen q vao r tai vi tri 2" << endl;
	InsertSubString(r, q, 2);
	cout << "Chuoi r : " << endl;
	puts(r);

	cout << "Xoa chuoi con q tu vi tri 1, 3 ky tu" << endl;
	DeleteSubString(q, 1, 3);
	cout << "Chuoi q : " << endl;
	puts(q);

	cout << "Tim chuoi con \"cd\" trong p tu vi tri 1" << endl;
	cout << "Vi tri tim duoc : " << FindSubString(p, "cd", 1) << endl;

	cout << "Ton tai chuoi con \"de\" trong p" << endl;
	cout << "Ton tai : " << IsSubString(p, "de") << endl;

	cout << "So lan xuat hien \"ab\" trong t : " << CountMatches(t, "ab") << endl;
	return 0;
}