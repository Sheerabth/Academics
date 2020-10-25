#include<stdio.h>
void main()
{
    int a[500],i,j,temp,num;
    printf("Please enter the number of terms\n");
    scanf("%d",&num);
    printf("Please enter the terms in an array\n");
    for(i=0;i<num;i++)
    {
        scanf("%d",&a[i]);
    }
    for(j=0;j<num;j++)
    {
        if(a[j]>a[j-1] && a[j]>a[j+1])
            printf("The index is %d and the element is %d\n",j,a[j]);
    }
}
