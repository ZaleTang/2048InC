#include <stdio.h>
#include <time.h>
#include <conio.h>

void printaline(int,int,int,int);
void printmatrix(int*);
void deal(int,int*);

int rand1();
int getkey();

int main()
{
    int i,j,key;

    int a[4][4];
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            a[i][j]=0;
    i=0;j=0;
    a[2][3]=2;
    a[2][2]=2;

    printmatrix(&a);


    deal(getch(),&a);
    printmatrix(&a);

    deal(getch(),&a);
    printmatrix(&a);

    deal(getch(),&a);
    printmatrix(&a);

    deal(getch(),&a);
    printmatrix(&a);

    deal(getch(),&a);
    printmatrix(&a);



}


void printaline(int a,int b,int c,int d)
{
    printf("//  "); printf("%d   ",a); printf("//  ");
    printf("//  "); printf("%d   ",b); printf("//  ");
    printf("//  "); printf("%d   ",c); printf("//  ");
    printf("//  "); printf("%d   ",d); printf("//  \n");
}

void printmatrix(int* martrix)
{
    system("cls");
    printf("////////////////////////////////////////////////\n");
    printaline(*martrix,*(martrix+1),*(martrix+2),*(martrix+3));
    printaline(*(martrix+4),*(martrix+5),*(martrix+6),*(martrix+7));
    printaline(*(martrix+8),*(martrix+9),*(martrix+10),*(martrix+11));
    printaline(*(martrix+12),*(martrix+13),*(martrix+14),*(martrix+15));
    printf("////////////////////////////////////////////////\n");


}

int rand1()
{
    srand((unsigned)time(NULL));
    return rand();
}

//int getkey()
//{
//    char a;
//    switch(getch())
//    {
//        case 72:a=1;break;
//        case 80:a=2;break;
//        case 75:a=3;break;
//        case 77:a=4;break;
//        case 27:a=5;break;
//    }
//
//    return a;
//}

void deal(int key,int* martrix)
{
    int n,i,j,it,jt,at[4][4];


    martrix--;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
        {
            at[i][j]=*(martrix++);
        }

    //整体上移
    if (key==72)
    {
        for(j=0;j<4;j++)
        {
            if (at[0][j] == 0 || at[0][j] == at[1][j])
            {
                at[0][j] = at[0][j] + at[1][j];
                at[1][j] = at[2][j];
                at[2][j] = at[3][j];
                at[3][j] = 0;
            }

            if (at[1][j] == 0 || at[1][j] == at[2][j])
            {
                at[1][j] = at[1][j] + at[2][j];
                at[2][j] = at[3][j];
                at[3][j] = 0;
            }

            if (at[2][j] == 0 || at[2][j] == at[3][j])
            {
                at[2][j] = at[2][j] + at[3][j];
                at[3][j] = 0;
            }

        }
    }

    //整体下移
    if (key==2)
    {
        for(j=0;j<4;j++)
            for(i=3;i>=0;i--)
            {
                while(at[i][j]==0)
                {
                    at[i][j]=at[i+1][j];
                }

                if(at[i][j]=at[i-1][j])
                {
                    at[i][j]=2*at[i][j];
                    for(i=i-1;j>0;i--)
                    {
                        at[i][j]=at[i+1][j];
                    }
                }

            }

    }


    if (key==3)
    {
        for(i=0;i<4;i++)
            for(j=0;j<4;j++)
            {
                if(at[i][j]=at[i][j+1])
                {
                    at[i][j]=2*at[i][j];
                    for(j=j+1;j<4;j++)
                    {
                        at[i][j]=at[i][j+1];
                    }
                }

            }

    }

    martrix-=16;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
        {
            *(martrix++)=at[i][j];
        }



}
