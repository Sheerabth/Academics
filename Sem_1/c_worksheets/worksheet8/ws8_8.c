#include<stdio.h>
#include<string.h>
void main()
{
    char a[100];
    int i=0,j=0,k=0,l;
    printf("Enter the string:");
    gets(a);
    l=strlen(a);
    printf("\n");
    while(k!=l)
    {
        for(j=0;j<=k;j++)
        {
            printf("%c",a[j]);
        }
        printf("\n");
        k++;
    }

}
