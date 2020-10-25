#include<windows.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int points=0;
/*void SCP(int x,int y)
{
    COORD e={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),e);
}*/
void rules()
{
    printf("\t\t\t\t\t\t\t\t\t\tWelcome to THE GAME\n\n\n");
    printf("The Instructions are as follow's\n");
    printf("1.The first step is to select the character.\n\t\tYou can select only the character's which are seen.\n");
    printf("2.The player one should roll the dice and his/her character moves forward.\n");
    printf("3.There are 18 square's on the board.(10 normal square's,7 DECK  square's,1 JAIL square and 1 START square)\n");
    printf("4.Gaining and Losing the Points.\n");
    printf("\t\tYou can gain or lose points by falling on DECK square or on JAIL square or passing the START square.\n");
    printf("\t\tYou lose 20 points if you land on JAIL.\n");
    printf("\t\tYou get 5 points each time you pass START.\n");
    printf("\t\tDECK square's\n");
    printf("\t\t\tThere are 4 DECK cards which you will get assigned randomly.They are:\n");
    printf("\t\t\t1.If you get card number 1 from the deck,you get 5 points.\n");
    printf("\t\t\t2.If you get card number 2 from the deck,you lose 5 points.\n");
    printf("\t\t\t3.If you get card number 3 from the deck,you need to roll the dice,If you get 1 you get 10 points.\n");
    printf("\t\t\t4.If you get card number 4 from the deck,you need to roll the dice,If you get 1 you lose 10 points.\n");
    printf("5.After the player 1 complete's THREE(3) rounds his points are recorded and the Player 2 can now play the game.\n");
    printf("6.The player at last who most of the points will be shown and he is the winner.\n\n\n");
    printf("\t\t\t\t\t\t\t\t\t\tHAPPY GAMING!!!");
}

void printchar(char ch,int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%c",ch);
}
int dice()
{
    srand(time(0));
    int d;
    d=rand()%3+1;
    if(d==1)
        printf("You rolled a\n . \n");
    if(d==2)
        printf("You rolled a\n . . \n");
    if(d==3)
        printf("You rolled an\n.\n .\n  .\n");
    return d;
}
int deck(int x)
{
    srand(time(0));
    int deck,d,testd;
    deck=rand()%4+1;
    if(deck==1)
    {
        printf("You Got card number 1 from the deck.\nYou get 5 points\n");
        x+=5;
    }
    if(deck==2)
    {
        printf("You Got card number 2 from the deck.\nYou lose 5 points\n");
        x-=5;
    }
    if(deck==3)
    {
        printf("You Got card number 3 from the deck.\nRoll the dice if you get 1 you get 10 points\n");
        printf("Press 1 to roll the dice\n");
            scanf("%d",&testd);
            if(testd==1)
            {
                d=dice();
                if(d==1)
                {
                    printf("You add 10 points\n");
                    x+=10;
                }
                else
                    printf("You didn't roll a 1\n");
            }


    }
    if(deck==4)
    {

        printf("You Got card number 4 from the deck.\nRoll the dice if you get 1 you lose 10 points\n");
        printf("Press 1 to roll the dice\n");
            scanf("%d",&testd);
            if(testd==1)
            {
                d=dice();
                if(d==1)
                {
                    printf("You lose 10 points\n");
                    x-=10;
                }
                else
                    printf("You didnt roll a 1\n");
            }

    }
    return x;
}
int printtable(int playpos,char ch,int x)
{
    int nump,i,j,k,n,m,b,l,flag=0;
    char a[500][500];
    if(x==1 && flag==0)
    {
        points=0;
        flag=1;
    }
    printf("\n\t\t\t\t");
    for(i=0; i<100; i++)
    {
        a[0][i]='-';
        printf("%c",a[0][i]);
        a[i+1][1]='|';
        a[i+1][99]='|';
    }
    printf("-");
    for(k=25; k<76; k++)
    {
        a[5][k]='-';
        a[15][k]='-';
    }
    for(n=5; n<16; n++)
    {
        a[n][25]='|';
        a[n][75]='|';
    }
    printf("\n");
    for(j=0; j<40; j++)
    {
        if (j<9 || j>30)
        {
            for(l=0;l<56;l++)
            {
                if(l<31)
                    printf(" ");
                else if(l==32)
                    printf("%c",a[j+1][1]);
                else
                    printf(" ");
            }
            printf("|");
            for(l=0;l<76;l++)
            {
                if(l<15)
                    printf(" ");
                else if(l==15)
                    printf("|");
                else if(l<32)
                    printf(" ");
                else if(l==32)
                    printf("|");
                else if (l<50)
                    printf(" ");
                else if(l==50)
                    printf("|");
                else if(l<75)
                    printf(" ");
                else
                    printf("%c",a[j+1][99]);
            }
            printf("\n");
        }
         else if ((j>9 || j<30) && j!=11 && j!=17 && j!=22 && j!=27)
        {
            if(j==9|| j==30 || j==14 || j==20 || j==25)
            {
                for(l = 0; l<91; l++)
                {
                    if(l<32)
                        printf(" ");
                    else if(l==32)
                        printf("|");
                    else if(l<56)
                        printf("-");
                    else if(l==56)
                        printf("|");
                    else if (l==57)
                        printchar('-',50);
                    else if(l==58)
                        printf("|");
                    else if(l==59)
                        printchar('-',24);
                    else if(l==60)
                        printf("|\n");
                }
            }
            for(l=0;l<89;l++)
            {
                if(l<32)
                    printf(" ");
                else if(l==32)
                    printf("|");
                else if(l<56)
                    printf(" ");
                else if(l==56)
                    printf("|");
                else if(l==57)
                    printchar('-',50);
                else if(l==58)
                    printf("|");
                else if(l<83)
                    printf(" ");
                else if(l==83)
                    printf("|\n");
            }
        }
        if(j==3 && playpos==14)
        {
            for(l=0;l<56;l++)
            {
                if(l<31)
                    printf(" ");
                else if(l==32)
                    printf("%c",a[j+1][1]);
                else if(l<44)
                    printf(" ");
                else if(l==44)
                    printf("%c",ch);
                else
                    printf(" ");
            }
            printf("|");
            for(l=0;l<76;l++)
            {
                if(l<15)
                    printf(" ");
                else if(l==15)
                    printf("|");
                else if(l<32)
                    printf(" ");
                else if(l==32)
                    printf("|");
                else if (l<50)
                    printf(" ");
                else if(l==50)
                    printf("|");
                else if(l<75)
                    printf(" ");
                else
                    printf("%c",a[j+1][99]);
            }
            printf("\n");
        }
         if(j==3 && playpos==13)
        {
            for(l=0;l<56;l++)
            {
                if(l<31)
                    printf(" ");
                else if(l==32)
                    printf("%c",a[j+1][1]);
                else if(l<44)
                    printf(" ");
                else if(l==44)
                    printf(" ");
                else
                    printf(" ");
            }
            printf("|");
            for(l=0;l<76;l++)
            {
                if(l<7)
                    printf(" ");
                else if(l==7)
                    printf("%c",ch);
                else if(l<15)
                    printf(" ");
                else if(l==15)
                    printf("|");
                else if(l<32)
                    printf(" ");
                else if(l==32)
                    printf("|");
                else if (l<50)
                    printf(" ");
                else if(l==50)
                    printf("|");
                else if(l<75)
                    printf(" ");
                else
                    printf("%c",a[j+1][99]);
            }
            printf("\n");
        }
         if(j==3 && playpos==12)
        {
            for(l=0;l<56;l++)
            {
                if(l<31)
                    printf(" ");
                else if(l==32)
                    printf("%c",a[j+1][1]);
                else if(l<44)
                    printf(" ");
                else if(l==44)
                    printf(" ");
                else
                    printf(" ");
            }
            printf("|");
            for(l=0;l<76;l++)
            {
                if(l<7)
                    printf(" ");
                else if(l==7)
                    printf(" ");
                else if(l<15)
                    printf(" ");
                else if(l==15)
                    printf("|");
                else if(l<23)
                    printf(" ");
                else if(l==23)
                    printf("%c",ch);
                else if(l<32)
                    printf(" ");
                else if(l==32)
                    printf("|");
                else if (l<50)
                    printf(" ");
                else if(l==50)
                    printf("|");
                else if(l<75)
                    printf(" ");
                else
                    printf("%c",a[j+1][99]);
            }
            printf("\n");
        }
         if(j==3 && playpos==11)
        {
            for(l=0;l<56;l++)
            {
                if(l<31)
                    printf(" ");
                else if(l==32)
                    printf("%c",a[j+1][1]);
                else if(l<44)
                    printf(" ");
                else if(l==44)
                    printf(" ");
                else
                    printf(" ");
            }
            printf("|");
            for(l=0;l<76;l++)
            {
                if(l<7)
                    printf(" ");
                else if(l==7)
                    printf(" ");
                else if(l<15)
                    printf(" ");
                else if(l==15)
                    printf("|");
                else if(l<32)
                    printf(" ");
                else if(l==32)
                    printf("|");
                else if(l<41)
                    printf(" ");
                else if(l==41)
                    printf("%c",ch);
                else if (l<50)
                    printf(" ");
                else if(l==50)
                    printf("|");

                else if(l<75)
                    printf(" ");
                else
                    printf("%c",a[j+1][99]);
            }
            printf("\n");
        }
        if(j==3 && playpos==10)
        {
            for(l=0;l<56;l++)
            {
                if(l<31)
                    printf(" ");
                else if(l==32)
                    printf("%c",a[j+1][1]);
                else if(l<44)
                    printf(" ");
                else if(l==44)
                    printf(" ");
                else
                    printf(" ");
            }
            printf("|");
            for(l=0;l<76;l++)
            {
                if(l<7)
                    printf(" ");
                else if(l==7)
                    printf(" ");
                else if(l<15)
                    printf(" ");
                else if(l==15)
                    printf("|");
                else if(l<32)
                    printf(" ");
                else if(l==32)
                    printf("|");
                else if(l<41)
                    printf(" ");
                else if(l==41)
                    printf(" ");
                else if (l<50)
                    printf(" ");
                else if(l==50)
                    printf("|");
                else if(l<62)
                    printf(" ");
                else if(l==62)
                    printf("%c",ch);
                else if(l<75)
                    printf(" ");
                else
                    printf("%c",a[j+1][99]);
            }
            printf("\n");
        }
        if(j==10 && playpos==15)
        {
            for(l=0;l<89;l++)
            {
                if(l<32)
                    printf(" ");
                else if(l==32)
                    printf("|");
                else if(l<44)
                    printf(" ");
                else if(l==44)
                    printf("%c",ch);
                else if(l<56)
                    printf(" ");
                else if(l==56)
                    printf("|");
                else if(l==57)
                    printchar('-',50);
                else if(l==58)
                    printf("|");
                else if(l<83)
                    printf(" ");
                else if(l==83)
                    printf("|\n");
            }
        }
        if(j==17 && playpos==16)
        {
            for(l=0;l<89;l++)
            {
                if(l<32)
                    printf(" ");
                else if(l==32)
                    printf("|");
                else if(l<44)
                    printf(" ");
                else if(l==44)
                    printf("%c",ch);
                else if(l<56)
                    printf(" ");
                else if(l==56)
                    printf("|");
                else if(l==57)
                    printchar('-',50);
                else if(l==58)
                    printf("|");
                else if(l<83)
                    printf(" ");
                else if(l==83)
                    printf("|\n");
            }
        }
        if(j==22 && playpos==17)
        {
            for(l=0;l<89;l++)
            {
                if(l<32)
                    printf(" ");
                else if(l==32)
                    printf("|");
                else if(l<44)
                    printf(" ");
                else if(l==44)
                    printf("%c",ch);
                else if(l<56)
                    printf(" ");
                else if(l==56)
                    printf("|");
                else if(l==57)
                    printchar('-',50);
                else if(l==58)
                    printf("|");
                else if(l<83)
                    printf(" ");
                else if(l==83)
                    printf("|\n");
            }
        }
         if(j==27 && playpos==18)
        {
            for(l=0;l<89;l++)
            {
                if(l<32)
                    printf(" ");
                else if(l==32)
                    printf("|");
                else if(l<44)
                    printf(" ");
                else if(l==44)
                    printf("%c",ch);
                else if(l<56)
                    printf(" ");
                else if(l==56)
                    printf("|");
                else if(l==57)
                    printchar('-',50);
                else if(l==58)
                    printf("|");
                else if(l<83)
                    printf(" ");
                else if(l==83)
                    printf("|\n");
            }
        }
        if(j==32 && playpos==1)
        {
            for(l=0;l<56;l++)
            {
                if(l<31)
                    printf(" ");
                else if(l==32)
                    printf("%c",a[j+1][1]);
                else if(l<44)
                    printf(" ");
                else if(l==44)
                    printf("%c",ch);
                else
                    printf(" ");
            }
            printf("|");
            for(l=0;l<76;l++)
            {
                if(l<15)
                    printf(" ");
                else if(l==15)
                    printf("|");
                else if(l<32)
                    printf(" ");
                else if(l==32)
                    printf("|");
                else if (l<50)
                    printf(" ");
                else if(l==50)
                    printf("|");
                else if(l<75)
                    printf(" ");
                else
                    printf("%c",a[j+1][99]);
            }
            printf("\n");
        }
        if(j==32 && playpos==2)
        {
            for(l=0;l<56;l++)
            {
                if(l<31)
                    printf(" ");
                else if(l==32)
                    printf("%c",a[j+1][1]);
                else if(l<56)
                    printf(" ");
            }
            printf("|");
            for(l=0;l<76;l++)
            {
                if(l<7)
                    printf(" ");
                else if(l==7)
                    printf("%c",ch);
                else if(l<15)
                    printf(" ");
                else if(l==15)
                    printf("|");
                else if(l<32)
                    printf(" ");
                else if(l==32)
                    printf("|");
                else if (l<50)
                    printf(" ");
                else if(l==50)
                    printf("|");
                else if(l<75)
                    printf(" ");
                else
                    printf("%c",a[j+1][99]);
            }
            printf("\n");
        }

        if(j==32 && playpos==3)
        {
            for(l=0;l<56;l++)
            {
                if(l<31)
                    printf(" ");
                else if(l==32)
                    printf("%c",a[j+1][1]);
                else if(l<56)
                    printf(" ");
            }
            printf("|");
            for(l=0;l<76;l++)
            {
                if(l<15)
                    printf(" ");
                else if(l==15)
                    printf("|");
                else if(l<23)
                    printf(" ");
                else if(l==23)
                    printf("%c",ch);
                else if(l<32)
                    printf(" ");
                else if(l==32)
                    printf("|");
                else if (l<50)
                    printf(" ");
                else if(l==50)
                    printf("|");
                else if(l<75)
                    printf(" ");
                else
                    printf("%c",a[j+1][99]);
            }
            printf("\n");
        }
        if(j==32 && playpos==4)
        {
            for(l=0;l<56;l++)
            {
                if(l<31)
                    printf(" ");
                else if(l==32)
                    printf("%c",a[j+1][1]);
                else if(l<56)
                    printf(" ");
            }
            printf("|");
            for(l=0;l<76;l++)
            {
                if(l<15)
                    printf(" ");
                else if(l==15)
                    printf("|");
                else if(l<23)
                    printf(" ");
                else if(l==23)
                    printf(" ");
                else if(l<32)
                    printf(" ");
                else if(l==32)
                    printf("|");
                else if(l<41)
                    printf(" ");
                else if(l==41)
                    printf("%c",ch);
                else if (l<50)
                    printf(" ");
                else if(l==50)
                    printf("|");
                else if(l<75)
                    printf(" ");
                else
                    printf("%c",a[j+1][99]);
            }
            printf("\n");
        }
        if(j==32 && playpos==5)
        {
            for(l=0;l<56;l++)
            {
                if(l<31)
                    printf(" ");
                else if(l==32)
                    printf("%c",a[j+1][1]);
                else if(l<56)
                    printf(" ");
            }
            printf("|");
            for(l=0;l<76;l++)
            {
                if(l<15)
                    printf(" ");
                else if(l==15)
                    printf("|");
                else if(l<23)
                    printf(" ");
                else if(l==23)
                    printf(" ");
                else if(l<32)
                    printf(" ");
                else if(l==32)
                    printf("|");
                else if (l<50)
                    printf(" ");
                else if(l==50)
                    printf("|");
                else if(l<63)
                    printf(" ");
                else if(l==63)
                    printf("%c",ch);
                else if(l<75)
                    printf(" ");
                else
                    printf("%c",a[j+1][99]);
            }
            printf("\n");
        }
        if(j==27 && playpos==6)
        {
            for(l=0;l<89;l++)
            {
                if(l<32)
                    printf(" ");
                else if(l==32)
                    printf("|");
                else if(l<56)
                    printf(" ");
                else if(l==56)
                    printf("|");
                else if(l==57)
                    printchar('-',50);
                else if(l==58)
                    printf("|");
                else if(l<71)
                    printf(" ");
                else if(l==71)
                    printf("%c",ch);
                else if(l<83)
                    printf(" ");
                else if(l==83)
                    printf("|\n");
            }
        }
        if(j==22 && playpos==7)
        {
            for(l=0;l<89;l++)
            {
                if(l<32)
                    printf(" ");
                else if(l==32)
                    printf("|");
                else if(l<56)
                    printf(" ");
                else if(l==56)
                    printf("|");
                else if(l==57)
                    printchar('-',50);
                else if(l==58)
                    printf("|");
                else if(l<71)
                    printf(" ");
                else if(l==71)
                    printf("%c",ch);
                else if(l<83)
                    printf(" ");
                else if(l==83)
                    printf("|\n");
            }
        }
        if(j==17 && playpos==8)
        {
            for(l=0;l<89;l++)
            {
                if(l<32)
                    printf(" ");
                else if(l==32)
                    printf("|");
                else if(l<56)
                    printf(" ");
                else if(l==56)
                    printf("|");
                else if(l==57)
                    printchar('-',50);
                else if(l==58)
                    printf("|");
                else if(l<71)
                    printf(" ");
                else if(l==71)
                    printf("%c",ch);
                else if(l<83)
                    printf(" ");
                else if(l==83)
                    printf("|\n");
            }
        }
        if(j==10 && playpos==9)
        {
            for(l=0;l<89;l++)
            {
                if(l<32)
                    printf(" ");
                else if(l==32)
                    printf("|");
                else if(l<56)
                    printf(" ");
                else if(l==56)
                    printf("|");
                else if(l==57)
                    printchar('-',50);
                else if(l==58)
                    printf("|");
                else if(l<71)
                    printf(" ");
                else if(l==71)
                    printf("%c",ch);
                else if(l<83)
                    printf(" ");
                else if(l==83)
                    printf("|\n");
            }
        }
        if(j==0)
        {
            for(l=0;l<124;l++)
            {
                if(l<32)
                    printf(" ");
                else if(l==32)
                    printf("%c",a[j+1][1]);
                else if(l<41)
                    printf(" ");
                else if(l==41)
                    printf("Jail");
                else if(l<53)
                    printf(" ");
                else if(l==53)
                    printf("|");
                else if(l<61)
                    printf(" ");
                else if(l==61)
                    printf("Deck");
                else if(l<66)
                    printf(" ");
                else if(l==66)
                    printf("|");
                else if(l<83)
                    printf(" ");
                else if(l==83)
                    printf("|");
                else if(l<90)
                    printf(" ");
                else if(l==90)
                    printf("Deck");
                else if(l<98)
                    printf(" ");
                else if(l==98)
                    printf("|");
                else if(l<123 )
                    printf(" ");
                else if(l==123)
                    printf("%c",a[j+1][99]);

            }


            printf("\n");
        }
        if(j==11)
        {
            for(l=0;l<85;l++)
            {
                if(l<32)
                    printf(" ");
                else if(l==32)
                    printf("|");
                else if(l<43)
                    printf(" ");
                else if(l==43)
                    printf("Deck");
                else if(l<53)
                    printf(" ");
                else if(l==53)
                    printf("%c",a[j+1][1]);
                else if(l==54)
                    printchar('-',50);
                else if(l==55)
                    printf("|");
                else if(l<80)
                    printf(" ");
                else if(l==80)
                    printf("|\n");
            }


        }
        if(j==17)
        {
            for(l=0;l<89 ;l++)
            {
                if(l<32)
                    printf(" ");
                else if(l==32)
                    printf("|");
                else if(l<56)
                    printf(" ");
                else if(l==56)
                    printf("%c",a[j+1][1]);
                else if(l==57)
                    printchar('-',50);
                else if(l==58)
                    printf("|");
                else if(l<70)
                    printf(" ");
                else if(l==70)
                    printf("Deck");
                else if(l<80)
                    printf(" ");
                else if(l==80)
                    printf("|\n");
            }
        }
        if(j==22)
        {
            for(l=0;l<85;l++)
            {
                if(l<32)
                    printf(" ");
                else if(l==32)
                    printf("|");
                else if(l<43)
                    printf(" ");
                else if(l==43)
                    printf("Deck");
                else if(l<53)
                    printf(" ");
                else if(l==53)
                    printf("%c",a[j+1][1]);
                else if(l==54)
                    printchar('-',50);
                else if(l==55)
                    printf("|");
                else if(l<80)
                    printf(" ");
                else if(l==80)
                    printf("|\n");
            }
        }
        if(j==27)
        {
           for(l=0;l<89 ;l++)
            {
                if(l<32)
                    printf(" ");
                else if(l==32)
                    printf("|");
                else if(l<56)
                    printf(" ");
                else if(l==56)
                    printf("%c",a[j+1][1]);
                else if(l==57)
                    printchar('-',50);
                else if(l==58)
                    printf("|");
                else if(l<70)
                    printf(" ");
                else if(l==70)
                    printf("Deck");
                else if(l<80)
                    printf(" ");
                else if(l==80)
                    printf("|\n");
            }
        }
        if(j==30)
        {
            for(l=0;l<156;l++)
            {
                if(l<32)
                    printf(" ");
                else if(l==32)
                    printf("%c",a[j+1][1]);
                else if(l>32 && l<42)
                    printf(" ");
                else if(l==42)
                    printf("START");
                else if(l>42 && l<52)
                    printf(" ");
                else if (l==52)
                    printf("|");
                else if (l<68)
                    printf(" ");
                else if (l==68)
                    printf("|");
                else if (l<76)
                    printf(" ");
                else if(l==76)
                    printf("Deck");
                else if (l>76 && l<82)
                    printf(" ");
                else if(l==82)
                    printf("|");
                else if(l<100 && l>82)
                    printf(" ");
                else if(l==100)
                    printf("|");
                else if(l>100 && l<125)
                    printf(" ");
                else if (l==125)
                    printf("%c",a[j+1][99]);

            }
            printf("\n");
        }
    }

        printf("\t\t\t\t");
    printchar('-',101);
    if(playpos==3 || playpos==6 || playpos==8  || playpos==11 || playpos==13 || playpos==15 || playpos==17)
    {
        printf("\n");
        points=deck(points);
    }
    if(playpos==14)
        points-=20;
    if(playpos==1)
        points+=5;
    return points;


}
void main()
{
    char playchar[2];
    int i,d,testd,round[2][2]={0},playpos=0,points[2]={0},x=0,flag=0;
    rules();
    printf("\n");
    for(i=0;i<2;i++)
    {
        if(i==0)
        {
            printf("Enter your character Player %d:",i+1);
            scanf("%c",&playchar[i]);
        }
        else
        {
            printf("Enter your character Player %d:",i+1);
            scanf("%*c%c",&playchar[i]);
        }
    }
    i=0;
    while(i<2)
    {
        while(round[1][i]<3)
        {
            d=0;
            testd=0;
            l1:printf("Press 1 to roll the dice player %d\n",i+1);
            scanf("%d",&testd);
            if(testd==1)
                d=dice();
            else
            {
                printf("Sorry please enter again\n");
                goto l1;
            }
            playpos+=d;
            if(playpos>18)
            {
                playpos=playpos-18;
                round[1][i]++;
            }
            if(i==2 && flag==1)
                x==1;
            points[i]=printtable(playpos,playchar[i],x);
            printf("\n");
        }
        i++;
    }
    printf("%d\n%d\n", points[0],points[1]);
    if(points[0]>points[1])
        printf("Player 1 wins with %d difference\n",points[0]-points[1]);
    else if(points[0]==points[1])
        printf("Both the players have same points.So both are the winner's\n");
    else
        printf("Player 2 wins with %d difference\n",points[1]-points[0]);

}

