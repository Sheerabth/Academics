#include<stdio.h>
#include<string.h>
void main()
{
    char a[100],b[100];
    int i,j,k,temp,n;
    printf("Please enter the string1:");
    scanf("%[^\n]s",a);
    scanf("%*c");
    printf("Please enter the string2:");
    scanf("%[^\n]s",b);
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(b[i]>b[j])
            {
                temp=b[i];
                b[i]=b[j];
                b[j]=temp;
            }
        }
    }
    k=strcmp(a,b);
    if(k==0)
        printf("The is a String 1 is valid shuffle of String 2");
    else
        printf("The is a String 1 is valid not shuffle of String 2");
}
