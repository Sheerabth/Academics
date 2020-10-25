#include<stdio.h>
void main()
{
    int i,a,ctr=0;
    printf("Please enter the value of the number\n");
    scanf("%d",&a);
    for(i=31;i<=0;i--)
    {
        if(a>>i&1)
            ctr+=1;
    }
    if(ctr==1)
        printf("The entered number is a power of two\n");
    else
        printf("The entered number is not a power of two\n");

}
