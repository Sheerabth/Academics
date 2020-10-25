#include<stdio.h>
void main()
{
    char a[100];
    int i=0,countu=0,countl=0,counts=0;
    printf("Please enter the sentence\n");
    scanf("%[^\n]s",a);
    while(a[i]!='\0')
    {
        if(a[i]>=65 && a[i]<=90)
            countu++;
        if(a[i]>=97 && a[i]<=122)
            countl++;
        else
            counts++;
        i++;
    }
    printf("The no. of upper case charecter's are:%d\n",countu);
    printf("The no. of lower case charecter's are:%d\n",countl);
    printf("The no. of special case charecter's are:%d\n",counts-1);

}
