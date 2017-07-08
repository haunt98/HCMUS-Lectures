#include "ham.h"


int songay(int thang,int nam)
{
	int re;
	switch(thang)
	{
	case 4:
	case 6:
	case 9:
	case 11:
		re=30;
		break;
	case 2:
		if( (nam%4==0 && nam%100 != 0) || nam%400==0 )
			re=29;
		else
			re=28;
		break;
	default:
		re=31;
		break;
	}
	return re;
}

int stt(thuthap A)
{
	int re=0;
	for(int i=1;i<A.thang;++i)
		re+=songay(i,A.nam);
	re+=A.ngay;
	return re;
}

void nhap(FILE *f,thuthap A[],int &len)
{
	char tam[MAX],name[MAX];
	int i;
	i=0;len=0;
	
	while(fgets(tam,MAX-1,f))
	{
		fscanf(f,"%d %d %d ",&A[i].ngay,&A[i].thang,&A[i].nam);
		fscanf(f,"%s",A[i].ten);
		++i;++len;
	}
}
int ktra(char s[], char t[])
{
	if(strlen(s)!=strlen(t))
		return 0;
	for(int i=0;i<strlen(s);++i)
		if (s[i]!=t[i])
			return 0;
	return 1;
}
int dem(int chi_so,thuthap A[],int len)
{
	int re=0;
	for(int i=0;i<len;++i)
		if(ktra(A[chi_so].ten,A[i].ten))
			++re;
	return re;
}

void lietke(thuthap A[],int len)
{
	int i,j,flag;
	printf("So luong thu thap duoc cua moi loai vat\n");
	for(i=0;i<len;++i)
	{
		flag=1;
		for(j=0;j<i;++j)
			if(ktra(A[j].ten,A[i].ten))
				flag=0;
		if(flag==1)
			printf("%s : %d con\n",A[i].ten,dem(i,A,len));
	}
}

void lk_thang(thuthap A[],int len)
{
	int i,j;
	printf("So luong thu thap loai vat trong moi thang\n");
	for(i=1;i<=12;++i)
	{
		printf("Thu thap trong thang %d\n",i);
		for(j=0;j<len;++j)
			if(A[j].thang==i)
				printf("%s\n",A[j].ten);
	}
}

void lk_daunam(thuthap A[],int len)
{
	int tam[MAX],nl,i,j,flag,min;
	nl=0;
	printf("\n");
	for(i=0;i<len;++i)
	{
		flag=1;
		for(j=0;j<i;++j)
			if(A[j].nam==A[i].nam)
				flag=0;
		if(flag==1)
			tam[nl++]=i;
	}
	for(i=0;i<nl;++i)
	{
		min=tam[i];
		for(j=0;j<len;++j)
			if(A[j].nam==A[i].nam)
				if(stt(A[j])<stt(A[min]))
					min=j;
		printf("Dau tien cua nam %d : %s\n",A[i].nam,A[min].ten);
	}
}
	