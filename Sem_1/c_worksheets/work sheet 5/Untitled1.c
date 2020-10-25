#include<stdio.h>
void main()
{
    int num,n,i,j;
    printf("Please enter the number\n");
    scanf("%d",&n);
    printf("How do you want to modify the given number\n1.Get the rightmost bit of the number\n2.Get the three (3) rightmost bits\n");
    printf("3.Get the leftmost bit of the number\n4.Get the three (3) leftmost bits\n");
    printf("5.Remove rightmost bit\n6.Remove rightmost three bits\n");
    printf("7.Remove left most bit\n8.Remove leftmost three bits\n");
    printf("9.Get four (4) rightmost bits of any input and remove the last bit\n");
    printf("10.Remove the first bit of any input,and add it to the right");
l1 :printf("Select which modification you want to make (the serial number)\n");
    scanf("%d",&num);
    switch (num)
    {
        case 1: if (n&1)
                    printf("The rightmost bit of the number is 1\n");
                else
                    printf("The rightmost bit of the number is 0\n");
                        break;

        case 2: if (n&1)
                    printf("The rightmost bit of the number is 1\n");
                else
                    printf("The rightmost bit of the number is 0\n");
                if (n>>1&1)
                    printf("The second rightmost bit of the number is 1\n");
                else
                    printf("The rightmost bit of the number is 0\n");
                if (n>>2&1)
                    printf("The third rightmost bit of the number is 1\n");
                else
                    printf("The third rightmost bit of the number is 0\n");
                        break;
        case 3: if (n>>31&1)
                    printf("The leftmost bit of the number is 1\n");
                else
                    printf("The leftmost bit of the number is 0\n");
                        break;
        case 4:  if (n>>31&1)
                    printf("The rightmost bit of the number is 1\n");
                else
                    printf("The rightmost bit of the number is 0\n");
                if (n>>30&1)
                    printf("The second rightmost bit of the number is 1\n");
                else
                    printf("The rightmost bit of the number is 0\n");
                if (n>>29&1)
                    printf("The third rightmost bit of the number is 1\n");
                else
                    printf("The third rightmost bit of the number is 0\n");
                        break;
        case 5: printf("After removing the right most bit the number is %d\n",n>>1);
                        break;
        case 6: printf("After removing the three right most bits the number is %d\n",n>>3);
                        break;
        case 7: printf("After removing the left most bit the number is %d\n",n<<1);
                        break;
        case 8: printf("After removing the three left most bits the number is %d\n",n<<3);
                        break;
        case 9: for (i=3 ; i>=0 ; i--)
                {
                    if (n>>i&1)
                        printf("1 ");
                    else
                        printf("0 ");
                }
                 printf("\n");
                 printf("After removing the right most bit the number is %d\n",n>>1);
                        break;
        case 10: if (n&1)
                    j=1;
                 else
                        j=0;
                 printf("After removing the first bit and adding it to the right most bit is %d\n",(n>>1)+j);
                        break;
        default : printf("Please input an valid number\n");
                    goto l1;
    }
}
