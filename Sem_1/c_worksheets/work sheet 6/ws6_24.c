#include<stdio.h>
void main()
{
    char a[100];
    int i=0,j,sum=0;
    printf("Please enter the word\n");
    scanf("%[^\n]%*c",&a);
    while(a[i]!='\0')
    {
        if(a[i]=='a')
            sum+=1;
        else if(a[i]=='b')
                sum+=3;
        else if(a[i]=='c')
                sum+=3;
        else if(a[i]=='d')
                sum+=2;
        else if(a[i]=='e')
                sum+=1;
        else if(a[i]=='f')
                sum+=4;
        else if(a[i]=='g')
                sum+=2;
        else if(a[i]=='h')
                sum+=4;
        else if(a[i]=='i')
                sum+=1;
        else if(a[i]=='j')
                sum+=1;
        else if(a[i]=='k')
                sum+=5;
        else if(a[i]=='l')
                sum+=1;
        else if(a[i]=='m')
                sum+=3;
        else if(a[i]=='n')
                sum+=1;
        else if(a[i]=='o')
                sum+=1;
        else if(a[i]=='p')
                sum+=3;
        else if(a[i]=='q')
                sum+=10;
        else if(a[i]=='r')
                sum+=1;
        else if(a[i]=='s')
                sum+=1;
        else if(a[i]=='t')
                sum+=1;
        else if(a[i]=='u')
                sum+=1;
        else if(a[i]=='v')
                sum+=2;
        else if(a[i]=='w')
                sum+=2;
        else if(a[i]=='x')
                sum+=8;
        else if(a[i]=='y')
                sum+=4;
        else if(a[i]=='z')
                sum+=10;
        i++;
    }
    printf("The score of the word is:%d",sum);
}
