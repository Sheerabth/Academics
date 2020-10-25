#include<stdio.h>
void main()
{
    char a[100];
    int i=0,j,k;
    printf("Please enter the sentence\n");
    scanf("%[^\n]s",a);
    while(a[i]!='\0')
    {
        printf("%c\n",a[i]);
        i++;
    }

}
