//MSSV: 1612180
//Ho ten: Nguyen Tran Hau
//Cuoi ki

#include "ham.h"

int main(void)
{
	thuthap A[MAX];
	int len;
	FILE *f=fopen("input.txt","r");
	if(f==NULL)
		return 0;
	nhap(f,A,len);
	
	lietke(A,len);
	lk_thang(A,len);
	fclose(f);
	lk_daunam(A,len);
	return 0;
}