#include<stdio.h>
#include<ctype.h>
void main()
{
    int i=0,j=0,k=0;
    char a[500];
    printf("Please enter the INPUT\n");
    scanf("%[^\n]s",a);
    while(a[i]!='\0')
    {
        if((a[0]=='t' || a[0]=='T') && (a[1]=='h') && (a[2]=='e') && (a[3]==' '))
        {
            while(a[j]!='\0')
            {
                a[j]=a[j+4];
                j++;
            }
        }
        if((a[0]=='a'|| a[0]=='A') && a[1]==' ')
        {
            for(j=0;a[j]!='\0';j++)
                a[j]=a[j+2];
        }
        if((a[0]=='a'|| a[i]=='A') && a[1]=='n' && a[2]==' ')
        {
            for(j=0;a[j]!='\0';j++)
                a[j]=a[j+3];

        }
        if((a[i]==' ') && (a[i+1]=='t') && (a[i+2]=='h') && (a[i+3]=='e') && (a[i+4]==' '))
        {
            for(j=i;a[j]!='\0';j++)
                a[j]=a[j+4];
        }
        if(a[i]==' ' && a[i+1]=='a' && a[i+2]==' ')
        {
            for(j=i;a[j]!='\0';j++)
                a[j]=a[j+2];
        }
        if(a[i]==' ' && a[i+1]=='a' && a[i+2]=='n'&& a[i+3]==' ')
        {
            for(j=i;a[j]!='\0';j++)
                a[j]=a[j+3];
        }
        i++;
    }
    a[0]= toupper (a[0]);
    printf("After removing the articles the string is \n%s\n",a);
}
