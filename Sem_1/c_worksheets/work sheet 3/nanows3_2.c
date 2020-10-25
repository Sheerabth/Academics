#include<stdio.h>
#include<math.h>
void main()
{
     float v,t,wci;
     printf("Please enter the wind speed in miles per hour\n");
     scanf("%f",&v);
     printf("Please enter the temprature in fahrenheit\n");
     scanf("%f",&v);
     if(v<=4 && v>=0)
        wci=t;
    else if(v>=45)
        wci=1.6*t-55;
    else 
       wci=91.4+(91.4-t)*(0.0203*v-0.304*sqrt(v)-0.474);
    printf("Based on the given values the wind chill index is %d\n",wci);
}    
       