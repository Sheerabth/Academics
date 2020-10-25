#include<stdio.h>
void main()
{
    int i,n,min,x;
    printf("Please enter the number of integers that should be entered \n");
    scanf("%d",&n);
    scanf("%d",&x);
    min=x;
    for( i=2 ; i<=n ; i++ )
    {
        scanf("%d",&x);    
        if(min>x)
            min=x;
    }
    print("The minimum value of the given integers is %d",min );
}