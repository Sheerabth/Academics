#include<stdio.h>
#include<ctype.h>
#include<string.h>
void main()
{
    char a[100];
    int i=0,j,k;
    printf("Please enter the sentence\n");
    scanf("%[^\n]s",a);
    while(a[i]!='\0')
    {
        if(a[i]>=65 && a[i]<=90)
            a[i]=tolower(a[i]);
        else if(a[i]>=97 && a[i]<=122)
            a[i]=toupper(a[i]);
        i++;
    }
    printf("The new string is:\n");
    for(j=0;j<strlen(a);j++)
    {
        printf("%c",a[j]);
    }

}
