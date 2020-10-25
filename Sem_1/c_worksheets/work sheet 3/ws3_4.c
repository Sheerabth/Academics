#include<stdio.h>
void main()
{
    float p,t,sum=0,s;
    for( ; ; )
    {
            int o,x;
            printf("please enter the price(in $)\n");
            scanf("%f",&p);
            printf("Overnight delivery(0 = no, 1 = yes)\n");
            scanf("%d",&o);
            if(p<10)
            {
                if(o==0)
                {
                   t=p+2;
                   s=2;
                }   
                else
                { 
                    t=p+7;
                    s=7;
                }    
            }        
            else if(p>10)
            {
                if(o==0)
                {
                   t=p+3;
                   s=3;
                }   
                else
                { 
                    t=p+8;
                    s=8;
                }    
            }
            printf("price\t\t%f\nshipping\t\t%f\ntotal\t\t%f\n",p,s,t);
            sum+=t;
            printf("More item -1 to stop,other to continue\n");
            scanf("%d",&x);
            if(x == -1)
                break;
    }
    printf("total\t\t%d\n",sum);
}                