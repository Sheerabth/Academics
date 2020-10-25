#include<stdio.h>
int a1[100],a2[200],a3[100],a4[100],a5[100];
void sum(int n)
{
    int sum1=0,sum2=0,i;
    for(i=0;i<n;i++)
    {
        sum1+=a1[i];
        sum2+=a2[i];
    }
    printf("The sum of array 1 elements is %d\n",sum1);
    printf("The sum of array 2 elements is %d\n",sum2);
}
void copy(int n)
{
    for(i=0;i<n;i++)
    {
        a4[i]=a1[i];
    }
}
void main()
{
    int i,n;
    printf("Please enter the number if elements\n");
    scanf("%d",&n);
    printf("Please enter the elements of array 1\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a1[i]);
    }
    printf("Please enter the elements of array 2\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a2[i]);
    }
    sum(n);
    copy(n);

}
