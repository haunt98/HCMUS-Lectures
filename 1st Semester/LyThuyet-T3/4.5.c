#include <stdio.h>
//Dem cac so bt4.5
int main()
{
    printf("Cac so co tinh chat da cho:\n");
    int dem=0;
    for(int i=100;i<1000;++i)
    {
        if((i/10)%10==i%10+i/100)
        {
            ++dem;
            printf("%d\t",i);
        }
    }
    printf("\nCo %d so co tinh chat da cho.\n",dem);
}