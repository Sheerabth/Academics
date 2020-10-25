#include<stdio.h>
#include<string.h>
void main()
{
    char a[100];
    printf("Enter the string:\n");
    gets(a);
    strrev(a);
    printf("The new string is:%s",a);
}
