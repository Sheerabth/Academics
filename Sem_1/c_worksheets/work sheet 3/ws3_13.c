#include<stdio.h>
void main()
{
    int i;
    float a,b,c;
    while (i>0)  
    {
        printf("please enter the value of first side a\n");
        scanf("%f",&a);
        printf("please enter the value of second side b\n");
        scanf("%f",&b);
        printf("please enter the value of third side c\n");
        scanf("%f",&c);
        if(a<0 || b<0 || c<0)
        {
            break;
        }
        if(a+b<=c || b+c<=a || a+c<=b )
            printf("Invalid input\n");        
        if(a==b && b==c)
            printf("Equilateral\n");
        else if(a==b || b==c || a==c )
            printf("Isoceles\n");
        else
        {
                printf("the given triangle is not equilateral or isoceles\n");
        }
    }    
}
