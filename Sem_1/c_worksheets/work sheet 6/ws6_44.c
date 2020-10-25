#include <stdio.h>
void main(void)
{
    int n, k,p[100][100],i,j ;
    printf("Enter n:\n");
    scanf("%d",&n);
    for(i=0;i<n+1;++i)
    {
        p[i][0] = 1 ;
        p[i][i] = 1 ;
    }

    for(i=2;i<n+1;++i)
    {
        for(j=1;j<i;++j)
        {
            p[i][j] = p[i-1][j-1] + p[i-1][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)
        {
            for(k=0;k<n-i;k++)
            {
                printf(" ");
            }
            printf("%d",p[i][j]);
        }
        printf("\n");
    }
}
