#include<stdio.h>
void main()
{
    int a,j,i,d,ctr=0;
    printf("Please enter the value of the number\n");
    scanf("%d",&a);
    for(i=31;i<=0;i--)
    {
        d=a>>i&1;
        if(d==1)
            {
            ctr+=1;
            }
        else
        {
            break;
        }

    }
    printf("%d\n",i);
    printf("The number of leading zeros is %d\n",ctr);
}
