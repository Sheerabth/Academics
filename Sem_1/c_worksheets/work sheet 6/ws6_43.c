#include<stdio.h>
void main()
{
    int a[10][2]={0},i,k,j,sum[10]={0};
    for(i=0;i<10;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("Please enter the score of %d round %d ball ",i+1,j);
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<10;i++)
    {
        for(j=0;j<2;)
        {
            if((a[i][j]!=10 && a[i][j+1]!=10)|| (a[i][j]+a[i][j+1]!=10))
            {
                sum[i]+=a[i][j];
            }
            if(a[i][j]+a[i][j+1]==10 && (a[i][j] !=0 || a[i][j+1] !=0))
            {
                sum[i]+=a[i][j]+a[i+1][j];
            }
            if(a[i][j]==10 && a[i][j+1]==0)
            {
                sum[i]+=a[i][j]+a[i+1][j];
            }
            j++;
        }
    }
    for(i=0;i<10;i++)
    {
        printf("Score after Frame %d is %d\n",i+1,sum[i]);
    }
}
