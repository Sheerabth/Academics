#include<stdio.h>
void main()
{
    int sum=0,x,i;
    printf("Guess a number between 0-9\n");
    for(i=0;i<9;i++)
    {
        printf("Please enter the number which you guess\n");
        scanf("%d",&x);
        printf("Sorry,it is the wrong number\n\n\n");
        sum+=x;
    }
    printf("The correct number is %d\n",45-sum);
}
