#include<stdio.h>
void main()
{
    float mmin,wmax,x,y;
    int i;
    for( i=1; ;i++ )
    {
        if (i=1)
        {
             printf("Please enter the value of mens score");
            scanf("%f",&x);
            mmin=x;
                continue;
        }
        if(i=2)
        {
            printf("Please enter the value of womens score");
            scanf("%f",&y);
            wmax=y;
                continue;
        }
        if(i%2!=0)
        {
             printf("Please enter the value of mens score");
             scanf("%f",&x);
                if(mmin>x)
                {
                    mmin=x;
                    break;
                } 
                if(x==0)
                    break;   

        }
        
        if(i%2==0)
        {
             printf("Please enter the value of women score");
             scanf("%f",&y);
                if(wmax<y)
                    wmax=x;
                    break;
        }
        
    }
    printf("Minimum score in mens is %.2f\n",mmin);
    printf("Maximum score in women is %.2f\n",wmax);
}