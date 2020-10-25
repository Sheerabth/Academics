#include<stdio.h>
int functiontest();
int main()
{
    int num[10],i;
    for(i=0;i<10;i++)
        scanf("%d",&num[i]);
    functiontest(num);
}
int functiontest(int num[])
{
    int n=10,sum=0,i;
    for(i=0;i<10;i++)
        {
        sum+=num[i]*n;
        n--;
        }
    printf("%d",sum);
    if(sum%11==0)
       printf("ISBN number is valid");
    else
        printf("ISBN number is not valid");
}
