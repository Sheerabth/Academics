#include<stdio.h>
void main()
{
    char c1;
    float x,y,total=0;
    printf("Please select the transaction type\n");
    scanf("%c",&c1);
    for( ; ; )
    {
        if(c1=='d')
        {
            printf("Please enter the amount you wish to deposit\n");
            scanf("%f",&x);
            total+=x;
        }
        if(c1=='w')
        {
           
            printf("Please enter the amount you wish to withdrawl\n");
            scanf("%f",&y);
            total-=y;
            if(total<0)
            {
                 break;

            } 
            printf("Sorry your account is in lesser than minimum balance\nYour current amount is Rs.%d\n",total);
        }

    }
}

