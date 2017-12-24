#include <stdio.h>

int main()
{
    float do_c;
    printf("Nhap nhiet do o dang Do C\n");
    scanf("%f",&do_c);
    float do_f = do_c*1.8+32;
    float do_k = do_c+273;
    printf("Do F: %f\nDo K: %f\n",do_f,do_k);
    return 0;
}