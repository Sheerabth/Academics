#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
    int a[6]={0},i,j,n;
    printf("Please enter the no times the die should roll\n");
    scanf("%d",&n);
    srand (time(0));
    for(i=0;i<n;i++)
    {
        j=rand()%6+1;
        if(j==1)
            a[0]++;
       else if(j==2)
            a[1]++;
       else if(j==3)
            a[2]++;
       else if(j==4)
            a[3]++;
       else if(j==5)
            a[4]++;
       else if(j==6)
            a[5]++;
    }
    printf("The number of times each number is rolled is\n");
    printf("1\t2\t3\t4\t5\t6\t\n");
    printf("%d\t%d\t%d\t%d\t%d\t%d\t\n",a[0],a[1],a[2],a[3],a[4],a[5]);
}
