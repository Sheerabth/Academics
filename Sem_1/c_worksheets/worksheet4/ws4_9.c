#include<stdio.h>
void main()
{
    int x,n,i,sum=0,d;
    printf("Please enter the value of x\n");
    scanf("%d",&x);
    printf("Please enter the value of n\n");
    scanf("%d",&n);
    for(i=1;i<=n;)
    {
        d=d*((x-1)/x);
        sum=(float) sum+d/2;
    }
    printf("The answer is %d\n",sum);
}