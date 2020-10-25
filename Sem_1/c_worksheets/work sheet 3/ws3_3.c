#include<stdio.h>
void main()
{
    int n;
    printf("Please enter the number\n");
    scanf("%d",&n);
    if(n%5==0 && n%6==0)
        printf("Is %d divisible by 5 and 6?true\n",n);
    else if(n%5!=0 && n%6==0)
        {
            printf("Is %d divisible by and 6?false\n",n);
            printf("Is %d divisible by 5 or 6 but not both?true\n",n);
        } 
    else if(n%5==0 && n%6!=0)
        {
            printf("Is %d divisible by 5 and 6?false\n",n);
            printf("Is %d divisible by 5 or 6 but not both?true\n",n);
        } 
    else if(n%5==0 || n%6==0)
            printf("Is %d divisible by 5 or 6?true\n",n);
    else if(n%5==0 || n%6!=0)
            printf("Is %d divisible by 5 or 6?false\n",n);
    else if(n%5!=0 || n%6==0)
            printf("Is %d divisible by 5 or 6?false\n",n);
}