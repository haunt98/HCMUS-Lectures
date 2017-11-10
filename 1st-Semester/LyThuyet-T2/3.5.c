#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float p,q,x,t;

    printf("Giai pt x^3+p^2*x+q=0\n");
    printf("Nhap p va q\n");
    scanf("%f %f",&p,&q);

    t=sqrt(pow(p,6)/27.0+pow(q,2)/4.0);
    x=pow((t-q/2),1.0/3.0)-pow((t+q/2),1.0/3.0);
    printf("PT co nghiem %f\n",x);
    return 0;
}