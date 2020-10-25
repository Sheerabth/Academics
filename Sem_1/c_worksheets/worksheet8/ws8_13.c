#include<stdio.h>
#include<string.h>
void main()
{
    char  a[100],c;
    int i,j,k;
    printf("Enter the string:");
    gets(a);
    printf("Enter the character that should be removed:");
    scanf("%c",&c);
    for(i<0;i<strlen(a);i++)
    {
        if(a[i]==c)
        {
            for(j=i;j<strlen(a);j++)
            {
                a[j]=a[j+1];
            }
        }
    }
    printf("The new string is:%s",a);
}
