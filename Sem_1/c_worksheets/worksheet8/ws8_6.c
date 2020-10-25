#include<stdio.h>
void main()
{
    char a[100];
    int i=0;
    printf("Please enter the sentence\n");
    scanf("%[^\n]s",a);
    while(a[i]!='\0')
    {
        if(a[i]== 'a' || a[i]=='A' || a[i]=='e' || a[i]=='E' || a[i]=='i' || a[i]=='I' || a[i]=='o' || a[i]=='O' || a[i]=='u' || a[i]=='U')
        {

            a[i]='*';

        }

        else
        {
            a[i]='#';
        }

        i++;
    }
    printf("The new string is:%s",a);
}
