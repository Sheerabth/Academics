#include<stdio.h>

void main()
{
    char s[80], search[10];
    int count1 = 0, count2 = 0, i, j, f;

    printf("Enter a string:");
    gets(s);
    printf("Enter search substring:");
    gets(search);
    while (s[count1] != '\0')
        count1++;
    while (search[count2] != '\0')
        count2++;
    for (i = 0; i <= count1 - count2; i++)
    {
        for (j = i; j < i + count2; j++)
        {
            f = 1;
            if (s[j] != search[j - i])
            {
                f = 0;
                break;
            }
        }
        if (f == 1)
            break;
    }
    if (f == 1)
        printf("THE STRING IS PRESENT");
    else
        printf("THE STRING IS NOT PRESENT");
}
