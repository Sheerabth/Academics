#include<stdio.h>
void main()
{
    int a[500],i,j,temp,num;
    printf("Please enter the number of terms\n");
    scanf("%d",&num);
    printf("Please enter the number of terms in an array\n");
    for(i=0;i<num;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("The array in the ascending order is \n");
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
    for(i=0;i<num;i++)
        printf("%d\n",a[i]);
}
