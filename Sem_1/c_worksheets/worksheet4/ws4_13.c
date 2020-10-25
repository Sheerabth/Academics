#include<stdio.h>
void main()
{
    int i,j,pro;
    for(i=1;i<=9;i++)
    {
        for(j=1;j<=9;j++)
        {
            pro=j*i;
            printf("%d",pro);
        }
        printf("\n");
    }
}