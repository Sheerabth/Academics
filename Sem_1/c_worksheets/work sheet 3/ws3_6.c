#include<stdio.h>
void main()
{
    int n,d;
    printf("Please enter the number\n");
    scanf("%d",&n);
    printf("The individual digits are\n");
    for( ; n<0 ; n/10 )
    {
        d=n%10;
        printf("%d",d);

    }
}