#include<stdio.h>
void main()
{
    int a[10]={0},i,j,x;
    printf("Guess a number between 0-9\n");
    for(i=0;i<9;i++)
    {
        printf("Please enter the number which you guess\n");
        scanf("%d",&x);
        printf("Sorry,it is the wrong number\n\n\n");
        a[x]=1;
    }
    for(j=0;j<9;j++)
    {
        if(a[j]==0)
        	printf("The correct number is %d\n",j);
    }
}
