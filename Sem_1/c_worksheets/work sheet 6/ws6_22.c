#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
    int a[100],i,j=0,n,x,y,b[13]={0},sum;

    srand (time(0));

    while(j<3600)
    {
        x=rand()%6+1;
        y=rand()%6+1;
        sum=x+y;
        if(sum==2)
            b[2]++;
        if(sum==3)
            b[3]++;
        if(sum==4)
            b[4]++;
        if(sum==5)
            b[5]++;
        if(sum==6)
            b[6]++;
        if(sum==7)
            b[7]++;
        if(sum==8)
            b[8]++;
        if(sum==9)
            b[9]++;
        if(sum==10)
            b[10]++;
        if(sum==11)
            b[11]++;
        if(sum==12)
            b[12]++;

            j++;

    }
    printf("The no. of times the sum is \n2\t3\t4\t5\t6\t7\t8\t9\t10\t11\t12\n");
    printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t",b[2],b[3],b[4],b[5],b[6],b[7],b[8],b[9],b[10],b[11],b[12]);
}
