#include<stdio.h>
void main()
{
    int e,m,p,sume=0,summ=0,sump=0,i,n;
    printf("Please enter the number of students\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("Please enter the english score of student %d\n",i);
        scnaf("%d",e);
        sume+=e;
         printf("Please enter the math score of student %d\n",i);
        scnaf("%d",m);
        summ+=m;
         printf("Please enter the physics score of student %d\n",i);
        scnaf("%d",p);
        sump+=p;
    }
    printf("Mean of english score=%d\n",sume/n);
    printf("Mean of math score=%d\n",summ/n);
    printf("Mean of physics score=%d\n",sump/n);
}