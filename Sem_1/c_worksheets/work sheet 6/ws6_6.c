#include <stdio.h>
void main()
{
    int a[500],i,j,temp,num,sum=0;
    printf("Please enter the number of terms\n");
    scanf("%d",&num);
    printf("Please enter the number of terms in an array\n");
    for(i=0;i<num;i++)
    {
        scanf("%d",&a[i]);
    }
    for(j=0;j<num;j++)
    {
        sum+=a[j];
    }
     for (i = 0; i < num; i++)
    {
        for (j = 0; j < (num - i - 1); j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    i=0;
    j=num-1;
    for( ; i<num ; i++)
    {
        for( ; j>=0 ; )
        {
            if(sum==a[i]+a[j])
            {
                printf("The indices are %d and %d,and the elements %d and %d",i,j,a[i],a[j]);
                    break;
            }
            else if(a[i]+a[j]>sum)
            {
                j--;
                break;
            }
            else
            {
                continue;
            }

        }
    }
}
