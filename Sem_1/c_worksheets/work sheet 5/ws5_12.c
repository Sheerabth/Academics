#include<stdio.h>
void main()
{
    int a,i,d;
    printf("Please enter the value of number\n");
    scanf("%d",&a);
     d=a&1;
     if(d==1)
        a=a-1;
     if(d!=1)
        a=a;
    printf("The number which is rounded to its nearest multiple of 2 is %d \n ",a);
}
