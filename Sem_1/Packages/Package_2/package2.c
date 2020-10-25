#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define T printf("Test\n");
int p[100]={0},s[100]={0},sp[100]={0},in[596]={0},au[100]={0};
void countwords(char b[])
{
    int nw=0,i=0;
    while(b[i]!='\0')
    {
        if(b[i]==' ' || b[i]=='.' || b[i]==',' || b[i]=='!' || b[i]=='-' || b[i]=='?' || b[i]==';' || b[i]==':' || b[i]=='{' || b[i]=='}' || b[i]=='(' || b[i]==')' || b[i]=='[' || b[i]==']')
            nw++;
        i++;
    }
   printf("The no of words is %d\n",nw);

}
void countchar(char b[])
{
    int i,nc;
    nc=0;
    for(i=0;b[i]!='\0';i++)
    {
            nc++;
    }
    printf("The no of characters are %d\n",nc);

}
void input(char a[])
{
    printf("Input the article\n");
    scanf("%[^\n]s",a);
}
void countlines(char b[])
{
    int no=0,i=0;
    for(i=0;b[i]!='\0';i++)
    {
        if(b[i]=='.')
        {
            no++;
        }
    }
    printf("The number if lines are %d\n",no);
}
void change(char a[])
{
    int i=0;
    while(a[i]!='\0')
    {
            a[i]=tolower(a[i]);
        i++;
    }
    i=0;
    while(a[i]!='\0')
    {
        if(a[i]=='.' || a[i]==',' || a[i]=='!' || a[i]=='-' || a[i]=='?' || a[i]==';' || a[i]==':' || a[i]=='{' || a[i]=='}' || a[i]=='(' || a[i]==')' || a[i]=='[' || a[i]==']')
        {
            a[i]=' ';
        }
        i++;
    }
}


void checkpolitics(char a[])
{
    FILE *P;
    FILE *c;
    int i,j,k;
    char s1[15],s2[15],t;
    P=fopen("politics.txt","r");
    c=fopen("copy.txt","w+");
    fprintf(c,"%s",a);
    rewind(c);
    while(!feof(c))
    {
        i=0;
        fscanf(c,"%s",s1);
        while(!feof(P))
        {
            fscanf(P,"%s",s2);
            if(strcmp(s1,s2)==0)
                p[i]++;
            i++;
        }
        rewind(P);
    }
    rewind(c);

    fclose(P);
    fclose(c);
}
void checkscience(char a[])
{
    FILE *S;
    FILE *c;
    int i,j,k;
    char s1[15],s2[15],t;
    S=fopen("science.txt","r");
    c=fopen("copy.txt","w+");
    fprintf(c,"%s",a);
    j=0;
    rewind(c);
    while(!feof(c))
    {
        i=0;
        fscanf(c,"%s",s1);
        while(!feof(S))
        {
            fscanf(S,"%s",s2);
            if(strcmp(s1,s2)==0)
            {
                s[i]++;
            }
            i++;
        }
        rewind(S);
    }
    fclose(S);
    fclose(c);
}
void checksports(char a[])
{
    FILE *Sp;
    FILE *c;
    int i,j,k;
    char s1[15],s2[15],t;
    Sp=fopen("sports.txt","r");
    c=fopen("copy.txt","w+");
    fprintf(c,"%s",a);
    j=0;

    rewind(c);
    while(!feof(c))
    {
        i=0;
        fscanf(c,"%s",s1);
        while(!feof(Sp))
        {
            fscanf(Sp,"%s",s2);
            if(strcmp(s1,s2)==0)
                sp[i]++;
            i++;
        }
        rewind(Sp);
    }
    fclose(Sp);
    fclose(c);
}
void checkinternational(char a[])
{
    FILE *I;
    FILE *c;
    int i,j,k;
    char s1[15],s2[15],t;
    I=fopen("international.txt","r");
    c=fopen("copy.txt","w+");
    fprintf(c,"%s",a);
    j=0;
    rewind(c);
    while(!feof(c))
    {
        i=0;
        fscanf(c,"%s",s1);
        while(!feof(I))
        {
            fscanf(I,"%s",s2);
            if(strcmp(s1,s2)==0)
            {
                in[i]++;
            }
            i++;
        }
        rewind(I);
    }
    fclose(I);
    fclose(c);
}
void checkautomobile(char a[])
{
    FILE *A;
    FILE *c;
    int i,j,k;
    char s1[15],s2[15],t;
    A=fopen("automobile.txt","r");
    c=fopen("copy.txt","w+");
    fprintf(c,"%s",a);
    j=0;
    rewind(c);
    while(!feof(c))
    {
        i=0;
        fscanf(c,"%s",s1);
        while(!feof(A))
        {
            fscanf(A,"%s",s2);
            if(strcmp(s1,s2)==0)
                au[i]++;
            i++;
        }
        rewind(A);
    }
    fclose(A);
    fclose(c);
}
void printans()
{
    int i,j,k,sum1=0,sum2=0,sum3=0,sum4=0,sum5=0,f1=0,f2=0,f3=0,f4=0,f5=0,f6=0;
    for(i=0;i<100;i++)
        sum1+=p[i];
    for(i=0;i<100;i++)
        sum2+=sp[i];
    for(i=0;i<100;i++)
        sum3+=s[i];
    for(i=0;i<100;i++)
        sum4+=au[i];
     for(i=0;i<596;i++)
        sum5+=in[i];
    printf("It belongs to the genre\n");
    if(sum1>=3)
    {
        printf("Politics\n");
        f1=1;
    }
    if(sum2>=3)
    {
        printf("Sports\n");
        f2=1;
    }
    if(sum3>=3)
    {
        printf("Science\n");
        f3=1;
    }
    if(sum4>=3)
    {
        printf("Automobile\n");
        f4=1;
    }
    if(sum5>=3)
    {
        printf("International\n");
        f5=1;
    }
    for(i=0;i<100;i++)
    {
        if(p[i]>=2 && f1==0)
        {
            printf("Politics\n");
            f1=1;
                break;
        }
    }
    for(i=0;i<100;i++)
    {
        if(sp[i]>=2 && f2==0)
        {
            printf("Sports\n");
            f2=1;
                break;
        }
    }
    for(i=0;i<100;i++)
    {
        if(s[i]>=2 && f3==0)
        {
            printf("Science\n");
            f3=1;
                break;
        }
    }
    for(i=0;i<100;i++)
    {
        if(au[i]>=2 && f4==0)
        {
            printf("Automobile\n");
            f4=1;
                break;
        }
    }
    for(i=0;i<596;i++)
    {
        if(in[i]>=2 && f5==0)
        {
            printf("International\n");
            f5=1;
                break;
        }
    }
        if(f1==0 && f2==0 && f3==0 && f4==0 && f5==0)
    {
        printf("Miscellaneous\n");
        f6=1;
    }

}
void manipulatioin(char b[])
{
    int i=0,j,k;
    char c1,c2;
    printf("Do you want to change any character?\nIf yes press 1\nIf no press 0\n");
    scanf("%d",&k);
    if(k==1)
    {
        printf("Please enter the character you want to swap with\n");
        scanf("%*c%c",&c1);
        printf("Please enter the character you want to swap to\n");
        getchar();
        scanf("%c",&c2);
        while(b[i]!='\0')
        {
            if(b[i]==c1)
            {
                b[i]=c2;
            }
            i++;
        }
        printf("%s",b);
    }
}
void main()
{
    char a[10000],b[10000];
    int i;
    input(a);
    for(i=0;a[i]!='\0';i++)
    {
        b[i]=a[i];
    }
    change(a);
    countwords(b);
    countchar(b);
    countlines(b);
    checkpolitics(a);
    checkscience(a);
    checkautomobile(a);
    checksports(a);
    checkinternational(a);
    printans();
    manipulatioin(b);
}
