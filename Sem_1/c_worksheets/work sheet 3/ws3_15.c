#include<stdio.h>
void main()
{
    int num,x1,x2,x3;
    printf("Please enter the three(3) digit number\n");
    scanf("%d",&num);
    x1=num%10;
    x2=(num%100)/10;
    x3=num/10;
    if(x1+x3==x2)
        printf("the sum of the first and last digit is equal to the middle digit/n");
    else
        printf("the sum of the first and last digit is not equal to the middle digit/n");    
}