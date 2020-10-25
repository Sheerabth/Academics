#include<stdio.h>
void main()
{
    int a[31],i,j,n,max,min,sum=0;
    printf("Please enter the number of days\n");
    scanf("%d",&n);
    printf("Please enter the temperature\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    min=a[0];
    max=a[0];
    printf("%d\n",max);
    for(j=0;j<n;j++)
    {
        if(max<a[j])
            max=a[j];
        if(min>a[j])
            min=a[j];
    }
    printf("The maximum temperature is %d\n",max);
    printf("The minimum temperature is %d\n",min);
    printf("The average temperature is %d\n",sum/n);

}
