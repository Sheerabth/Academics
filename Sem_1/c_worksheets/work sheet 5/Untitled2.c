#include<stdio.h>
void main()
{
    int c,f;
    printf("Celsius   |   farenheit \n");
    for(f=32;f<213;f+=18)
    {

        c=(f-32)*5/9;
        printf("%d            %d\n",c,f);
    }
}
