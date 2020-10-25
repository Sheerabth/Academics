#include<stdio.h>
#include<string.h>
void main()
{
    int a[4][6]={0},i,j,k;
    char name[4][15];
    strcpy(name[3],"Totals");
    printf("Please enter the names\n");
    for(i=0;i<3;i++)
    {
        scanf("%s",name[i]);
    }
    printf("Input the values each employee's production\n");
    for(i=0;i<3;i++)
    {
        printf("Enter the values for employee %d\n",i+1);
        for(j=0;j<5;j++)
        {
            scanf("%d",&a[i][j]);
            a[i][5]+=a[i][j];
        }
    }
    for(i=0;i<5;i++)
    {
        for(j=0;j<3;j++)
        {
            a[3][i]+=a[j][i];
        }
    }
    printf("Emp name\tMon\tTue\tWed\tThu\tFri\tTotals\n");
    for(i=0;i<4;i++)
    {
        printf("%s\t\t",name[i]);
        for(j=0;j<6;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }

}
