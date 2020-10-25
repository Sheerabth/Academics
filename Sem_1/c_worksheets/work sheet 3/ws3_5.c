#include<stdio.h>
void main()
{
    printf("Please enter an integer betwenn 0 and 999 \n");
    int i,n,d,sum=0;
    scanf("%d",&n);
    for( ; n>0 ;n/10)
    {
        d=n%10;
        sum+=d;
    }
    printf("The sum of the digits is %d\n",sum);
}