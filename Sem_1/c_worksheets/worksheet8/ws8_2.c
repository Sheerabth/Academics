#include<stdio.h>
void main()
{
    char a[100];
    int i=0,countv=0,countc=0,f1=0,f2=0;
    printf("Please enter the sentence\n");
    scanf("%[^\n]s",a);
    while(a[i]!='\0')
    {
        if(a[i]== 'a' || a[i]=='A' || a[i]=='e' || a[i]=='E' || a[i]=='i' || a[i]=='I' || a[i]=='o' || a[i]=='O' || a[i]=='u' || a[i]=='U')
        {

            printf("The vowel is:\n");
            printf("%c",a[i]);
            countv++;
            f1=1;

        }

        else
        {
                printf("\nThe consonant is:\n");
            printf("%c",a[i]);
            countc++;
            f2=1;
        }
        printf("\n");
        i++;

    }
    if(f1==0)
        printf("There are no vowels\n");
    if(f2==0)
        printf("There are no consonants\n");
}
