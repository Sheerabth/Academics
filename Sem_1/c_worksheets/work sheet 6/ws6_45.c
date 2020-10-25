#include<stdio.h>
void main()
{
    int a[100][100],b[100][100],c[100][100],sum[100][100],diff[100][100],mul[100][100],i,j,k,n;
    printf("enter no of rows and column:");
    scanf("%d",&n);
    printf("Plase enter the first matrix column wise\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
     printf("Plase enter the second matrix column wise\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            sum[i][j]=a[i][j]+b[i][j];
        }
    }
     for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            diff[i][j]=a[i][j]-b[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
                mul[i][j]=a[k][j]+a[i][k];
        }
    }
    printf("The sum matrix is \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",sum[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("The difference matrix is\n");
     for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",diff[i][j]);
        }
        printf("\n");
    }
    printf("The multplication matrix is\n");
     for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",mul[i][j]);
        }
        printf("\n");
    }

}
