#include<stdio.h>
void main()
{
    char a[100];
    int i=0,n;
    printf("Please enter the Sentence\n");
    scanf("%[^\n]s",a);
    printf("Please enter the integer\n");
    scanf("%d",&n);
    while(a[i]!='\0')
    {
        a[i]+=n;
        i++;
    }
    printf("The coded sentence is:%s\n",a);
}
