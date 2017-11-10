#include <stdio.h>
//bt tinh tong  S 4.4.c
int main()
{
    int n,t=1,s=0;
    printf("Nhap n\n");
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        t*=(i+1);
        s+=t;
    }
    printf("S = %d\n",s);
    return 0;
}