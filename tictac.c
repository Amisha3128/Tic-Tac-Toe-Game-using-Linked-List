#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
    char data;
    int pos;
    struct node *next;
};
struct node *f1=NULL;
struct node *l1=NULL;
struct node *f2=NULL;
struct node *l2=NULL;
void main()
{
int i=0;
int j=0;
int a1=0;
int a=0;
int n1=0;
int n2=0;                                   /* Loop counter                         */
int player = 0;                              /* Player number - 1 or 2               */
int go = 0;
int go1;                                  /* Square selection number for turn     */
int row = 0;                                 /* Row index for a square               */
int column = 0;                              /* Column index for a square            */
int line = 0;                                /* Row or column index in checking loop */
int winner = 0;
struct node *pnode1,*pnode2,*p1,*p2,*p3,*p4,*follow1,*follow2;
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
printf("\n\n");
printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
printf("---+---+---\n");
printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
printf("---+---+---\n");
printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);

for(i=0;i<3;i++)
 for(j=0;j<3;j++)
  board[i][j]=' ';

/* The main game loop. The game continues for up to 9 turns */
/* As long as there is no winner                            */
for( i = 0; i<9 && winner==0; i++)
{
/* Display the board */
if(i>0)
{
printf("\n\n");
printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
printf("---+---+---\n");
printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
printf("---+---+---\n");
printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}

player = i%2 + 1;                           /* Select player */

/* Get valid player square selection */

do
{
printf("\nPlayer %d, please enter the number of the square "
"where you want to place your %c: ", player,(player==1)?'X':'O');
scanf("%d", &go);
go1=go;
row = --go/3;                                 /* Get row index of square      */
column = go%3;                               /* Get column index of square   */
}while(go<0 || go>9 || board[row][column]>'9');


if(player==1)
    {
        pnode1=(struct node*)malloc(sizeof(struct node));
        pnode1->data='X';
        pnode1->pos=go1;
        if(f1==NULL)
        {
            f1=l1=pnode1;
        }
        else
        {
            l1->next=pnode1;
            l1=pnode1;
        }
    }
else
    {
        pnode2=(struct node*)malloc(sizeof(struct node));
        pnode2->data='O';
        pnode2->pos=go1;
        if(f2==NULL)
        {
            f2=l2=pnode2;
        }
        else
        {
            l2->next=pnode2;
            l2=pnode2;
        }
    }

p1=f1;
follow1=NULL;
while(follow1!=l1)
{
    n1++;
    follow1=p1;
    a=p1->pos;
    if(a==1)
	board[0][0]='X';
    else if(a==2)
	board[0][1]='X';
    else if(a==3)
	board[0][2]='X';
    else if(a==4)
	board[1][0]='X';
    else if(a==5)
	board[1][1]='X';
    else if(a==6)
	board[1][2]='X';
    else if(a==7)
	board[2][0]='X';
    else if(a==8)
	board[2][1]='X';
    else
	board[2][2]='X';
    p1=p1->next;
}

p2=f2;
follow2=NULL;
while(follow2!=l2)
{
    n2++;
    follow2=p2;
    a1=p2->pos;
    if(a1==1)
	board[0][0]='O';
    else if(a1==2)
	board[0][1]='O';
    else if(a1==3)
	board[0][2]='O';
    else if(a1==4)
	board[1][0]='O';
    else if(a1==5)
	board[1][1]='O';
    else if(a1==6)
	board[1][2]='O';
    else if(a1==7)
	board[2][0]='O';
    else if(a1==8)
	board[2][1]='O';
    else
	board[2][2]='O';
   p2=p2->next;
}
/*diagonal 123*/
if(n1>=3)
{
    if(f1->pos==1 && f1->next->pos==5 && f1->next->next->pos==9 ||
       f1->pos==5 && f1->next->pos==1 && f1->next->next->pos==9 ||
       f1->pos==1 && f1->next->pos==9 && f1->next->next->pos==5 ||
       f1->pos==5 && f1->next->pos==9 && f1->next->next->pos==1 ||
       f1->pos==9 && f1->next->pos==5 && f1->next->next->pos==1 ||
       f1->pos==9 && f1->next->pos==1 && f1->next->next->pos==5)
        winner=player;
}

if(n1>=3)
{
    if(f1->pos==3 && f1->next->pos==5 && f1->next->next->pos==7 ||
       f1->pos==5 && f1->next->pos==3 && f1->next->next->pos==7 ||
       f1->pos==3 && f1->next->pos==7 && f1->next->next->pos==5 ||
       f1->pos==5 && f1->next->pos==7 && f1->next->next->pos==3 ||
       f1->pos==7 && f1->next->pos==5 && f1->next->next->pos==3 ||
       f1->pos==7 && f1->next->pos==3 && f1->next->next->pos==5)
        winner=player;
}

if(n2>=3)
{
    if(f2->pos==1 && f2->next->pos==5 && f2->next->next->pos==9 ||
       f2->pos==5 && f2->next->pos==1 && f2->next->next->pos==9 ||
       f2->pos==1 && f2->next->pos==9 && f2->next->next->pos==5 ||
       f2->pos==5 && f2->next->pos==9 && f2->next->next->pos==1 ||
       f2->pos==9 && f2->next->pos==5 && f2->next->next->pos==1 ||
       f2->pos==9 && f2->next->pos==1 && f2->next->next->pos==5)
        winner=player;
}

if(n2>=3)
{
    if(f2->pos==3 && f2->next->pos==5 && f2->next->next->pos==7 ||
       f2->pos==5 && f2->next->pos==3 && f2->next->next->pos==7 ||
       f2->pos==3 && f2->next->pos==7 && f2->next->next->pos==5 ||
       f2->pos==5 && f2->next->pos==7 && f2->next->next->pos==3 ||
       f2->pos==7 && f2->next->pos==5 && f2->next->next->pos==3 ||
       f2->pos==7 && f2->next->pos==3 && f2->next->next->pos==5)
        winner=player;
}
/*rows 123*/
if(n1>=3)
{
    if(f1->pos==1 && f1->next->pos==2 && f1->next->next->pos==3 ||
       f1->pos==1 && f1->next->pos==3 && f1->next->next->pos==2 ||
       f1->pos==2 && f1->next->pos==1 && f1->next->next->pos==3 ||
       f1->pos==2 && f1->next->pos==3 && f1->next->next->pos==1 ||
       f1->pos==3 && f1->next->pos==2 && f1->next->next->pos==1 ||
       f1->pos==3 && f1->next->pos==1 && f1->next->next->pos==2)
        winner=player;
}
if(n1>=3)
{
    if(f1->pos==4 && f1->next->pos==5 && f1->next->next->pos==6 ||
       f1->pos==4 && f1->next->pos==6 && f1->next->next->pos==5 ||
       f1->pos==5 && f1->next->pos==4 && f1->next->next->pos==6 ||
       f1->pos==5 && f1->next->pos==6 && f1->next->next->pos==4 ||
       f1->pos==6 && f1->next->pos==4 && f1->next->next->pos==5 ||
       f1->pos==6 && f1->next->pos==5 && f1->next->next->pos==4)
        winner=player;
}

if(n1>=3)
{
    if(f1->pos==7 && f1->next->pos==8 && f1->next->next->pos==9 ||
       f1->pos==7 && f1->next->pos==9 && f1->next->next->pos==8 ||
       f1->pos==8 && f1->next->pos==7 && f1->next->next->pos==9 ||
       f1->pos==8 && f1->next->pos==9 && f1->next->next->pos==7 ||
       f1->pos==9 && f1->next->pos==7 && f1->next->next->pos==8 ||
       f1->pos==9 && f1->next->pos==8 && f1->next->next->pos==7)
        winner=player;
}
if(n2>=3)
{
    if(f2->pos==1 && f2->next->pos==2 && f2->next->next->pos==3 ||
       f2->pos==1 && f2->next->pos==3 && f2->next->next->pos==2 ||
       f2->pos==2 && f2->next->pos==1 && f2->next->next->pos==3 ||
       f2->pos==2 && f2->next->pos==3 && f2->next->next->pos==1 ||
       f2->pos==3 && f2->next->pos==2 && f2->next->next->pos==1 ||
       f2->pos==3 && f2->next->pos==1 && f2->next->next->pos==2)
        winner=player;
}
if(n2>=3)
{
    if(f2->pos==4 && f2->next->pos==5 && f2->next->next->pos==6 ||
       f2->pos==4 && f2->next->pos==6 && f2->next->next->pos==5 ||
       f2->pos==5 && f2->next->pos==4 && f2->next->next->pos==6 ||
       f2->pos==5 && f2->next->pos==6 && f2->next->next->pos==4 ||
       f2->pos==6 && f2->next->pos==4 && f2->next->next->pos==5 ||
       f2->pos==6 && f2->next->pos==5 && f2->next->next->pos==4)
        winner=player;
}

if(n2>=3)
{
    if(f2->pos==7 && f2->next->pos==8 && f2->next->next->pos==9 ||
       f2->pos==7 && f2->next->pos==9 && f2->next->next->pos==8 ||
       f2->pos==8 && f2->next->pos==7 && f2->next->next->pos==9 ||
       f2->pos==8 && f2->next->pos==9 && f2->next->next->pos==7 ||
       f2->pos==9 && f2->next->pos==7 && f2->next->next->pos==8 ||
       f2->pos==9 && f2->next->pos==8 && f2->next->next->pos==7)
        winner=player;
}
/*column 123*/
if(n1>=3)
{
    if(f1->pos==1 && f1->next->pos==4 && f1->next->next->pos==7 ||
       f1->pos==1 && f1->next->pos==7 && f1->next->next->pos==4 ||
       f1->pos==4 && f1->next->pos==1 && f1->next->next->pos==7 ||
       f1->pos==4 && f1->next->pos==7 && f1->next->next->pos==1 ||
       f1->pos==7 && f1->next->pos==1 && f1->next->next->pos==4 ||
       f1->pos==7 && f1->next->pos==4 && f1->next->next->pos==1)
        winner=player;
}
if(n1>=3)
{
    if(f1->pos==2 && f1->next->pos==5 && f1->next->next->pos==8 ||
       f1->pos==2 && f1->next->pos==8 && f1->next->next->pos==5 ||
       f1->pos==5 && f1->next->pos==2 && f1->next->next->pos==8 ||
       f1->pos==5 && f1->next->pos==8 && f1->next->next->pos==2 ||
       f1->pos==8 && f1->next->pos==2 && f1->next->next->pos==5 ||
       f1->pos==8 && f1->next->pos==5 && f1->next->next->pos==2)
        winner=player;
}

if(n1>=3)
{
    if(f1->pos==3 && f1->next->pos==6 && f1->next->next->pos==9 ||
       f1->pos==3 && f1->next->pos==9 && f1->next->next->pos==6 ||
       f1->pos==6 && f1->next->pos==3 && f1->next->next->pos==9 ||
       f1->pos==6 && f1->next->pos==9 && f1->next->next->pos==3 ||
       f1->pos==9 && f1->next->pos==3 && f1->next->next->pos==6 ||
       f1->pos==9 && f1->next->pos==6 && f1->next->next->pos==3)
        winner=player;
}

if(n2>=3)
{
    if(f2->pos==1 && f2->next->pos==4 && f2->next->next->pos==7 ||
       f2->pos==1 && f2->next->pos==7 && f2->next->next->pos==4 ||
       f2->pos==4 && f2->next->pos==1 && f2->next->next->pos==7 ||
       f2->pos==4 && f2->next->pos==7 && f2->next->next->pos==1 ||
       f2->pos==7 && f2->next->pos==1 && f2->next->next->pos==4 ||
       f2->pos==7 && f2->next->pos==4 && f2->next->next->pos==1)
        winner=player;
}
if(n1>=3)
{
    if(f2->pos==2 && f2->next->pos==5 && f2->next->next->pos==8 ||
       f2->pos==2 && f2->next->pos==8 && f2->next->next->pos==5 ||
       f2->pos==5 && f2->next->pos==2 && f2->next->next->pos==8 ||
       f2->pos==5 && f2->next->pos==8 && f2->next->next->pos==2 ||
       f2->pos==8 && f2->next->pos==2 && f2->next->next->pos==5 ||
       f2->pos==8 && f2->next->pos==5 && f2->next->next->pos==2)
        winner=player;
}

if(n1>=3)
{
    if(f2->pos==3 && f2->next->pos==6 && f2->next->next->pos==9 ||
       f2->pos==3 && f2->next->pos==9 && f2->next->next->pos==6 ||
       f2->pos==6 && f2->next->pos==3 && f2->next->next->pos==9 ||
       f2->pos==6 && f2->next->pos==9 && f2->next->next->pos==3 ||
       f2->pos==9 && f2->next->pos==3 && f2->next->next->pos==6 ||
       f2->pos==9 && f2->next->pos==6 && f2->next->next->pos==3)
        winner=player;
}
/*-----------------------------------------------------*/

/*diagonal 134*/
if(n1>=4)
{
    if(f1->pos==1 && f1->next->next->pos==5 && f1->next->next->next->pos==9 ||
       f1->pos==5 && f1->next->next->pos==1 && f1->next->next->next->pos==9 ||
       f1->pos==1 && f1->next->next->pos==9 && f1->next->next->next->pos==5 ||
       f1->pos==5 && f1->next->next->pos==9 && f1->next->next->next->pos==1 ||
       f1->pos==9 && f1->next->next->pos==5 && f1->next->next->next->pos==1 ||
       f1->pos==9 && f1->next->next->pos==1 && f1->next->next->next->pos==5)
        winner=player;
}

if(n1>=4)
{
    if(f1->pos==3 && f1->next->next->pos==5 && f1->next->next->next->pos==7 ||
       f1->pos==5 && f1->next->next->pos==3 && f1->next->next->next->pos==7 ||
       f1->pos==3 && f1->next->next->pos==7 && f1->next->next->next->pos==5 ||
       f1->pos==5 && f1->next->pos==7 && f1->next->next->next->pos==3 ||
       f1->pos==7 && f1->next->next->pos==5 && f1->next->next->next->pos==3 ||
       f1->pos==7 && f1->next->next->pos==3 && f1->next->next->next->pos==5)
        winner=player;
}

if(n2>=4)
{
    if(f2->pos==1 && f2->next->next->pos==5 && f2->next->next->next->pos==9 ||
       f2->pos==5 && f2->next->next->pos==1 && f2->next->next->next->pos==9 ||
       f2->pos==1 && f2->next->next->pos==9 && f2->next->next->next->pos==5 ||
       f2->pos==5 && f2->next->next->pos==9 && f2->next->next->next->pos==1 ||
       f2->pos==9 && f2->next->next->pos==5 && f2->next->next->next->pos==1 ||
       f2->pos==9 && f2->next->next->pos==1 && f2->next->next->next->pos==5)
        winner=player;
}

if(n2>=4)
{
    if(f2->pos==3 && f2->next->next->pos==5 && f2->next->next->next->pos==7 ||
       f2->pos==5 && f2->next->next->pos==3 && f2->next->next->next->pos==7 ||
       f2->pos==3 && f2->next->next->pos==7 && f2->next->next->next->pos==5 ||
       f2->pos==5 && f2->next->next->pos==7 && f2->next->next->next->pos==3 ||
       f2->pos==7 && f2->next->next->pos==5 && f2->next->next->next->pos==3 ||
       f2->pos==7 && f2->next->next->pos==3 && f2->next->next->next->pos==5)
        winner=player;
}
/*rows 134*/
if(n1>=4)
{
    if(f1->pos==1 && f1->next->next->pos==2 && f1->next->next->next->pos==3 ||
       f1->pos==1 && f1->next->next->pos==3 && f1->next->next->next->pos==2 ||
       f1->pos==2 && f1->next->next->pos==1 && f1->next->next->next->pos==3 ||
       f1->pos==2 && f1->next->next->pos==3 && f1->next->next->next->pos==1 ||
       f1->pos==3 && f1->next->next->pos==2 && f1->next->next->next->pos==1 ||
       f1->pos==3 && f1->next->next->pos==1 && f1->next->next->next->pos==2)
        winner=player;
}
if(n1>=4)
{
    if(f1->pos==4 && f1->next->next->next->pos==5 && f1->next->next->pos==6 ||
       f1->pos==4 && f1->next->next->next->pos==6 && f1->next->next->pos==5 ||
       f1->pos==5 && f1->next->next->next->pos==4 && f1->next->next->pos==6 ||
       f1->pos==5 && f1->next->next->next->pos==6 && f1->next->next->pos==4 ||
       f1->pos==6 && f1->next->next->next->pos==4 && f1->next->next->pos==5 ||
       f1->pos==6 && f1->next->next->next->pos==5 && f1->next->next->pos==4)
        winner=player;
}

if(n1>=4)
{
    if(f1->pos==7 && f1->next->next->next->pos==8 && f1->next->next->pos==9 ||
       f1->pos==7 && f1->next->next->next->pos==9 && f1->next->next->pos==8 ||
       f1->pos==8 && f1->next->next->next->pos==7 && f1->next->next->pos==9 ||
       f1->pos==8 && f1->next->next->next->pos==9 && f1->next->next->pos==7 ||
       f1->pos==9 && f1->next->next->next->pos==7 && f1->next->next->pos==8 ||
       f1->pos==9 && f1->next->next->next->pos==8 && f1->next->next->pos==7)
        winner=player;
}
if(n2>=4)
{
    if(f2->pos==1 && f2->next->next->next->pos==2 && f2->next->next->pos==3 ||
       f2->pos==1 && f2->next->next->next->pos==3 && f2->next->next->pos==2 ||
       f2->pos==2 && f2->next->next->next->pos==1 && f2->next->next->pos==3 ||
       f2->pos==2 && f2->next->next->next->pos==3 && f2->next->next->pos==1 ||
       f2->pos==3 && f2->next->next->next->pos==2 && f2->next->next->pos==1 ||
       f2->pos==3 && f2->next->next->next->pos==1 && f2->next->next->pos==2)
        winner=player;
}
if(n2>=4)
{
    if(f2->pos==4 && f2->next->next->next->pos==5 && f2->next->next->pos==6 ||
       f2->pos==4 && f2->next->next->next->pos==6 && f2->next->next->pos==5 ||
       f2->pos==5 && f2->next->next->next->pos==4 && f2->next->next->pos==6 ||
       f2->pos==5 && f2->next->next->next->pos==6 && f2->next->next->pos==4 ||
       f2->pos==6 && f2->next->next->next->pos==4 && f2->next->next->pos==5 ||
       f2->pos==6 && f2->next->next->next->pos==5 && f2->next->next->pos==4)
        winner=player;
}

if(n2>=4)
{
    if(f2->pos==7 && f2->next->next->next->pos==8 && f2->next->next->pos==9 ||
       f2->pos==7 && f2->next->next->next->pos==9 && f2->next->next->pos==8 ||
       f2->pos==8 && f2->next->next->next->pos==7 && f2->next->next->pos==9 ||
       f2->pos==8 && f2->next->next->next->pos==9 && f2->next->next->pos==7 ||
       f2->pos==9 && f2->next->next->next->pos==7 && f2->next->next->pos==8 ||
       f2->pos==9 && f2->next->next->next->pos==8 && f2->next->next->pos==7)
        winner=player;
}
/*column 134*/
if(n1>=4)
{
    if(f1->pos==1 && f1->next->next->next->pos==4 && f1->next->next->pos==7 ||
       f1->pos==1 && f1->next->next->next->pos==7 && f1->next->next->pos==4 ||
       f1->pos==4 && f1->next->next->next->pos==1 && f1->next->next->pos==7 ||
       f1->pos==4 && f1->next->next->next->pos==7 && f1->next->next->pos==1 ||
       f1->pos==7 && f1->next->next->next->pos==1 && f1->next->next->pos==4 ||
       f1->pos==7 && f1->next->next->next->pos==4 && f1->next->next->pos==1)
        winner=player;
}
if(n1>=4)
{
    if(f1->pos==2 && f1->next->next->next->pos==5 && f1->next->next->pos==8 ||
       f1->pos==2 && f1->next->next->next->pos==8 && f1->next->next->pos==5 ||
       f1->pos==5 && f1->next->next->next->pos==2 && f1->next->next->pos==8 ||
       f1->pos==5 && f1->next->next->next->pos==8 && f1->next->next->pos==2 ||
       f1->pos==8 && f1->next->next->next->pos==2 && f1->next->next->pos==5 ||
       f1->pos==8 && f1->next->next->next->pos==5 && f1->next->next->pos==2)
        winner=player;
}

if(n1>=4)
{
    if(f1->pos==3 && f1->next->next->next->pos==6 && f1->next->next->pos==9 ||
       f1->pos==3 && f1->next->next->next->pos==9 && f1->next->next->pos==6 ||
       f1->pos==6 && f1->next->next->next->pos==3 && f1->next->next->pos==9 ||
       f1->pos==6 && f1->next->next->next->pos==9 && f1->next->next->pos==3 ||
       f1->pos==9 && f1->next->next->next->pos==3 && f1->next->next->pos==6 ||
       f1->pos==9 && f1->next->next->next->pos==6 && f1->next->next->pos==3)
        winner=player;
}

if(n2>=4)
{
    if(f2->pos==1 && f2->next->next->next->pos==4 && f2->next->next->pos==7 ||
       f2->pos==1 && f2->next->next->next->pos==7 && f2->next->next->pos==4 ||
       f2->pos==4 && f2->next->next->next->pos==1 && f2->next->next->pos==7 ||
       f2->pos==4 && f2->next->next->next->pos==7 && f2->next->next->pos==1 ||
       f2->pos==7 && f2->next->next->next->pos==1 && f2->next->next->pos==4 ||
       f2->pos==7 && f2->next->next->next->pos==4 && f2->next->next->pos==1)
        winner=player;
}
if(n2>=4)
{
    if(f2->pos==2 && f2->next->next->next->pos==5 && f2->next->next->pos==8 ||
       f2->pos==2 && f2->next->next->next->pos==8 && f2->next->next->pos==5 ||
       f2->pos==5 && f2->next->next->next->pos==2 && f2->next->next->pos==8 ||
       f2->pos==5 && f2->next->next->next->pos==8 && f2->next->next->pos==2 ||
       f2->pos==8 && f2->next->next->next->pos==2 && f2->next->next->pos==5 ||
       f2->pos==8 && f2->next->next->next->pos==5 && f2->next->next->pos==2)
        winner=player;
}

if(n2>=4)
{
    if(f2->pos==3 && f2->next->next->next->pos==6 && f2->next->next->pos==9 ||
       f2->pos==3 && f2->next->next->next->pos==9 && f2->next->next->pos==6 ||
       f2->pos==6 && f2->next->next->next->pos==3 && f2->next->next->pos==9 ||
       f2->pos==6 && f2->next->next->next->pos==9 && f2->next->next->pos==3 ||
       f2->pos==9 && f2->next->next->next->pos==3 && f2->next->next->pos==6 ||
       f2->pos==9 && f2->next->next->next->pos==6 && f2->next->next->pos==3)
        winner=player;
}
/*-----------------------------------------------------*/

/*diagonal 124*/
if(n1>=4)
{
    if(f1->pos==1 && f1->next->pos==5 && f1->next->next->next->pos==9 ||
       f1->pos==5 && f1->next->pos==1 && f1->next->next->next->pos==9 ||
       f1->pos==1 && f1->next->pos==9 && f1->next->next->next->pos==5 ||
       f1->pos==5 && f1->next->pos==9 && f1->next->next->next->pos==1 ||
       f1->pos==9 && f1->next->pos==5 && f1->next->next->next->pos==1 ||
       f1->pos==9 && f1->next->pos==1 && f1->next->next->next->pos==5)
        winner=player;
}

if(n1>=4)
{
    if(f1->pos==3 && f1->next->pos==5 && f1->next->next->next->pos==7 ||
       f1->pos==5 && f1->next->pos==3 && f1->next->next->next->pos==7 ||
       f1->pos==3 && f1->next->pos==7 && f1->next->next->next->pos==5 ||
       f1->pos==5 && f1->next->pos==7 && f1->next->next->next->pos==3 ||
       f1->pos==7 && f1->next->pos==5 && f1->next->next->next->pos==3 ||
       f1->pos==7 && f1->next->pos==3 && f1->next->next->next->pos==5)
        winner=player;
}

if(n2>=4)
{
    if(f2->pos==1 && f2->next->pos==5 && f2->next->next->next->pos==9 ||
       f2->pos==5 && f2->next->pos==1 && f2->next->next->next->pos==9 ||
       f2->pos==1 && f2->next->pos==9 && f2->next->next->next->pos==5 ||
       f2->pos==5 && f2->next->pos==9 && f2->next->next->next->pos==1 ||
       f2->pos==9 && f2->next->pos==5 && f2->next->next->next->pos==1 ||
       f2->pos==9 && f2->next->pos==1 && f2->next->next->next->pos==5)
        winner=player;
}

if(n2>=4)
{
    if(f2->pos==3 && f2->next->pos==5 && f2->next->next->next->pos==7 ||
       f2->pos==5 && f2->next->pos==3 && f2->next->next->next->pos==7 ||
       f2->pos==3 && f2->next->pos==7 && f2->next->next->next->pos==5 ||
       f2->pos==5 && f2->next->pos==7 && f2->next->next->next->pos==3 ||
       f2->pos==7 && f2->next->pos==5 && f2->next->next->next->pos==3 ||
       f2->pos==7 && f2->next->pos==3 && f2->next->next->next->pos==5)
        winner=player;
}
/*rows 124*/
if(n1>=4)
{
    if(f1->pos==1 && f1->next->pos==2 && f1->next->next->next->pos==3 ||
       f1->pos==1 && f1->next->pos==3 && f1->next->next->next->pos==2 ||
       f1->pos==2 && f1->next->pos==1 && f1->next->next->next->pos==3 ||
       f1->pos==2 && f1->next->pos==3 && f1->next->next->next->pos==1 ||
       f1->pos==3 && f1->next->pos==2 && f1->next->next->next->pos==1 ||
       f1->pos==3 && f1->next->pos==1 && f1->next->next->next->pos==2)
        winner=player;
}
if(n1>=4)
{
    if(f1->pos==4 && f1->next->next->next->pos==5 && f1->next->pos==6 ||
       f1->pos==4 && f1->next->next->next->pos==6 && f1->next->pos==5 ||
       f1->pos==5 && f1->next->next->next->pos==4 && f1->next->pos==6 ||
       f1->pos==5 && f1->next->next->next->pos==6 && f1->next->pos==4 ||
       f1->pos==6 && f1->next->next->next->pos==4 && f1->next->pos==5 ||
       f1->pos==6 && f1->next->next->next->pos==5 && f1->next->pos==4)
        winner=player;
}

if(n1>=4)
{
    if(f1->pos==7 && f1->next->next->next->pos==8 && f1->next->pos==9 ||
       f1->pos==7 && f1->next->next->next->pos==9 && f1->next->pos==8 ||
       f1->pos==8 && f1->next->next->next->pos==7 && f1->next->pos==9 ||
       f1->pos==8 && f1->next->next->next->pos==9 && f1->next->pos==7 ||
       f1->pos==9 && f1->next->next->next->pos==7 && f1->next->pos==8 ||
       f1->pos==9 && f1->next->next->next->pos==8 && f1->next->pos==7)
        winner=player;
}
if(n2>=4)
{
    if(f2->pos==1 && f2->next->next->next->pos==2 && f2->next->pos==3 ||
       f2->pos==1 && f2->next->next->next->pos==3 && f2->next->pos==2 ||
       f2->pos==2 && f2->next->next->next->pos==1 && f2->next->pos==3 ||
       f2->pos==2 && f2->next->next->next->pos==3 && f2->next->pos==1 ||
       f2->pos==3 && f2->next->next->next->pos==2 && f2->next->pos==1 ||
       f2->pos==3 && f2->next->next->next->pos==1 && f2->next->pos==2)
        winner=player;
}
if(n2>=4)
{
    if(f2->pos==4 && f2->next->next->next->pos==5 && f2->next->pos==6 ||
       f2->pos==4 && f2->next->next->next->pos==6 && f2->next->pos==5 ||
       f2->pos==5 && f2->next->next->next->pos==4 && f2->next->pos==6 ||
       f2->pos==5 && f2->next->next->next->pos==6 && f2->next->pos==4 ||
       f2->pos==6 && f2->next->next->next->pos==4 && f2->next->pos==5 ||
       f2->pos==6 && f2->next->next->next->pos==5 && f2->next->pos==4)
        winner=player;
}

if(n2>=4)
{
    if(f2->pos==7 && f2->next->next->next->pos==8 && f2->next->pos==9 ||
       f2->pos==7 && f2->next->next->next->pos==9 && f2->next->pos==8 ||
       f2->pos==8 && f2->next->next->next->pos==7 && f2->next->pos==9 ||
       f2->pos==8 && f2->next->next->next->pos==9 && f2->next->pos==7 ||
       f2->pos==9 && f2->next->next->next->pos==7 && f2->next->pos==8 ||
       f2->pos==9 && f2->next->next->next->pos==8 && f2->next->pos==7)
        winner=player;
}
/*column 124*/
if(n1>=4)
{
    if(f1->pos==1 && f1->next->next->next->pos==4 && f1->next->pos==7 ||
       f1->pos==1 && f1->next->next->next->pos==7 && f1->next->pos==4 ||
       f1->pos==4 && f1->next->next->next->pos==1 && f1->next->pos==7 ||
       f1->pos==4 && f1->next->next->next->pos==7 && f1->next->pos==1 ||
       f1->pos==7 && f1->next->next->next->pos==1 && f1->next->pos==4 ||
       f1->pos==7 && f1->next->next->next->pos==4 && f1->next->pos==1)
        winner=player;
}
if(n1>=4)
{
    if(f1->pos==2 && f1->next->next->next->pos==5 && f1->next->pos==8 ||
       f1->pos==2 && f1->next->next->next->pos==8 && f1->next->pos==5 ||
       f1->pos==5 && f1->next->next->next->pos==2 && f1->next->pos==8 ||
       f1->pos==5 && f1->next->next->next->pos==8 && f1->next->pos==2 ||
       f1->pos==8 && f1->next->next->next->pos==2 && f1->next->pos==5 ||
       f1->pos==8 && f1->next->next->next->pos==5 && f1->next->pos==2)
        winner=player;
}

if(n1>=4)
{
    if(f1->pos==3 && f1->next->next->next->pos==6 && f1->next->pos==9 ||
       f1->pos==3 && f1->next->next->next->pos==9 && f1->next->pos==6 ||
       f1->pos==6 && f1->next->next->next->pos==3 && f1->next->pos==9 ||
       f1->pos==6 && f1->next->next->next->pos==9 && f1->next->pos==3 ||
       f1->pos==9 && f1->next->next->next->pos==3 && f1->next->pos==6 ||
       f1->pos==9 && f1->next->next->next->pos==6 && f1->next->pos==3)
        winner=player;
}

if(n2>=4)
{
    if(f2->pos==1 && f2->next->next->next->pos==4 && f2->next->pos==7 ||
       f2->pos==1 && f2->next->next->next->pos==7 && f2->next->pos==4 ||
       f2->pos==4 && f2->next->next->next->pos==1 && f2->next->pos==7 ||
       f2->pos==4 && f2->next->next->next->pos==7 && f2->next->pos==1 ||
       f2->pos==7 && f2->next->next->next->pos==1 && f2->next->pos==4 ||
       f2->pos==7 && f2->next->next->next->pos==4 && f2->next->pos==1)
        winner=player;
}
if(n2>=4)
{
    if(f2->pos==2 && f2->next->next->next->pos==5 && f2->next->pos==8 ||
       f2->pos==2 && f2->next->next->next->pos==8 && f2->next->pos==5 ||
       f2->pos==5 && f2->next->next->next->pos==2 && f2->next->pos==8 ||
       f2->pos==5 && f2->next->next->next->pos==8 && f2->next->pos==2 ||
       f2->pos==8 && f2->next->next->next->pos==2 && f2->next->pos==5 ||
       f2->pos==8 && f2->next->next->next->pos==5 && f2->next->pos==2)
        winner=player;
}

if(n2>=4)
{
    if(f2->pos==3 && f2->next->next->next->pos==6 && f2->next->pos==9 ||
       f2->pos==3 && f2->next->next->next->pos==9 && f2->next->pos==6 ||
       f2->pos==6 && f2->next->next->next->pos==3 && f2->next->pos==9 ||
       f2->pos==6 && f2->next->next->next->pos==9 && f2->next->pos==3 ||
       f2->pos==9 && f2->next->next->next->pos==3 && f2->next->pos==6 ||
       f2->pos==9 && f2->next->next->next->pos==6 && f2->next->pos==3)
        winner=player;
}
/*-----------------------------------------------------*/

/*diagonal 234*/
if(n1>=4)
{
    if(f1->next->pos==1 && f1->next->next->pos==5 && f1->next->next->next->pos==9 ||
       f1->next->pos==5 && f1->next->next->pos==1 && f1->next->next->next->pos==9 ||
       f1->next->pos==1 && f1->next->next->pos==9 && f1->next->next->next->pos==5 ||
       f1->next->pos==5 && f1->next->next->pos==9 && f1->next->next->next->pos==1 ||
       f1->next->pos==9 && f1->next->next->pos==5 && f1->next->next->next->pos==1 ||
       f1->next->pos==9 && f1->next->next->pos==1 && f1->next->next->next->pos==5)
        winner=player;
}

if(n1>=4)
{
    if(f1->next->pos==3 && f1->next->next->pos==5 && f1->next->next->next->pos==7 ||
       f1->next->pos==5 && f1->next->next->pos==3 && f1->next->next->next->pos==7 ||
       f1->next->pos==3 && f1->next->next->pos==7 && f1->next->next->next->pos==5 ||
       f1->next->pos==5 && f1->next->pos==7 && f1->next->next->next->pos==3 ||
       f1->next->pos==7 && f1->next->next->pos==5 && f1->next->next->next->pos==3 ||
       f1->next->pos==7 && f1->next->next->pos==3 && f1->next->next->next->pos==5)
        winner=player;
}

if(n2>=4)
{
    if(f2->next->pos==1 && f2->next->next->pos==5 && f2->next->next->next->pos==9 ||
       f2->next->pos==5 && f2->next->next->pos==1 && f2->next->next->next->pos==9 ||
       f2->next->pos==1 && f2->next->next->pos==9 && f2->next->next->next->pos==5 ||
       f2->next->pos==5 && f2->next->next->pos==9 && f2->next->next->next->pos==1 ||
       f2->next->pos==9 && f2->next->next->pos==5 && f2->next->next->next->pos==1 ||
       f2->next->pos==9 && f2->next->next->pos==1 && f2->next->next->next->pos==5)
        winner=player;
}

if(n2>=4)
{
    if(f2->next->pos==3 && f2->next->next->pos==5 && f2->next->next->next->pos==7 ||
       f2->next->pos==5 && f2->next->next->pos==3 && f2->next->next->next->pos==7 ||
       f2->next->pos==3 && f2->next->next->pos==7 && f2->next->next->next->pos==5 ||
       f2->next->pos==5 && f2->next->next->pos==7 && f2->next->next->next->pos==3 ||
       f2->next->pos==7 && f2->next->next->pos==5 && f2->next->next->next->pos==3 ||
       f2->next->pos==7 && f2->next->next->pos==3 && f2->next->next->next->pos==5)
        winner=player;
}
/*rows 234*/
if(n1>=4)
{
    if(f1->next->pos==1 && f1->next->next->pos==2 && f1->next->next->next->pos==3 ||
       f1->next->pos==1 && f1->next->next->pos==3 && f1->next->next->next->pos==2 ||
       f1->next->pos==2 && f1->next->next->pos==1 && f1->next->next->next->pos==3 ||
       f1->next->pos==2 && f1->next->next->pos==3 && f1->next->next->next->pos==1 ||
       f1->next->pos==3 && f1->next->next->pos==2 && f1->next->next->next->pos==1 ||
       f1->next->pos==3 && f1->next->next->pos==1 && f1->next->next->next->pos==2)
        winner=player;
}
if(n1>=4)
{
    if(f1->next->pos==4 && f1->next->next->next->pos==5 && f1->next->next->pos==6 ||
       f1->next->pos==4 && f1->next->next->next->pos==6 && f1->next->next->pos==5 ||
       f1->next->pos==5 && f1->next->next->next->pos==4 && f1->next->next->pos==6 ||
       f1->next->pos==5 && f1->next->next->next->pos==6 && f1->next->next->pos==4 ||
       f1->next->pos==6 && f1->next->next->next->pos==4 && f1->next->next->pos==5 ||
       f1->next->pos==6 && f1->next->next->next->pos==5 && f1->next->next->pos==4)
        winner=player;
}

if(n1>=4)
{
    if(f1->next->pos==7 && f1->next->next->next->pos==8 && f1->next->next->pos==9 ||
       f1->next->pos==7 && f1->next->next->next->pos==9 && f1->next->next->pos==8 ||
       f1->next->pos==8 && f1->next->next->next->pos==7 && f1->next->next->pos==9 ||
       f1->next->pos==8 && f1->next->next->next->pos==9 && f1->next->next->pos==7 ||
       f1->next->pos==9 && f1->next->next->next->pos==7 && f1->next->next->pos==8 ||
       f1->next->pos==9 && f1->next->next->next->pos==8 && f1->next->next->pos==7)
        winner=player;
}
if(n2>=4)
{
    if(f2->next->pos==1 && f2->next->next->next->pos==2 && f2->next->next->pos==3 ||
       f2->next->pos==1 && f2->next->next->next->pos==3 && f2->next->next->pos==2 ||
       f2->next->pos==2 && f2->next->next->next->pos==1 && f2->next->next->pos==3 ||
       f2->next->pos==2 && f2->next->next->next->pos==3 && f2->next->next->pos==1 ||
       f2->next->pos==3 && f2->next->next->next->pos==2 && f2->next->next->pos==1 ||
       f2->next->pos==3 && f2->next->next->next->pos==1 && f2->next->next->pos==2)
        winner=player;
}
if(n2>=4)
{
    if(f2->next->pos==4 && f2->next->next->next->pos==5 && f2->next->next->pos==6 ||
       f2->next->pos==4 && f2->next->next->next->pos==6 && f2->next->next->pos==5 ||
       f2->next->pos==5 && f2->next->next->next->pos==4 && f2->next->next->pos==6 ||
       f2->next->pos==5 && f2->next->next->next->pos==6 && f2->next->next->pos==4 ||
       f2->next->pos==6 && f2->next->next->next->pos==4 && f2->next->next->pos==5 ||
       f2->next->pos==6 && f2->next->next->next->pos==5 && f2->next->next->pos==4)
        winner=player;
}

if(n2>=4)
{
    if(f2->next->pos==7 && f2->next->next->next->pos==8 && f2->next->next->pos==9 ||
       f2->next->pos==7 && f2->next->next->next->pos==9 && f2->next->next->pos==8 ||
       f2->next->pos==8 && f2->next->next->next->pos==7 && f2->next->next->pos==9 ||
       f2->next->pos==8 && f2->next->next->next->pos==9 && f2->next->next->pos==7 ||
       f2->next->pos==9 && f2->next->next->next->pos==7 && f2->next->next->pos==8 ||
       f2->next->pos==9 && f2->next->next->next->pos==8 && f2->next->next->pos==7)
        winner=player;
}
/*column 234*/
if(n1>=4)
{
    if(f1->next->pos==1 && f1->next->next->next->pos==4 && f1->next->next->pos==7 ||
       f1->next->pos==1 && f1->next->next->next->pos==7 && f1->next->next->pos==4 ||
       f1->next->pos==4 && f1->next->next->next->pos==1 && f1->next->next->pos==7 ||
       f1->next->pos==4 && f1->next->next->next->pos==7 && f1->next->next->pos==1 ||
       f1->next->pos==7 && f1->next->next->next->pos==1 && f1->next->next->pos==4 ||
       f1->next->pos==7 && f1->next->next->next->pos==4 && f1->next->next->pos==1)
        winner=player;
}
if(n1>=4)
{
    if(f1->next->pos==2 && f1->next->next->next->pos==5 && f1->next->next->pos==8 ||
       f1->next->pos==2 && f1->next->next->next->pos==8 && f1->next->next->pos==5 ||
       f1->next->pos==5 && f1->next->next->next->pos==2 && f1->next->next->pos==8 ||
       f1->next->pos==5 && f1->next->next->next->pos==8 && f1->next->next->pos==2 ||
       f1->next->pos==8 && f1->next->next->next->pos==2 && f1->next->next->pos==5 ||
       f1->next->pos==8 && f1->next->next->next->pos==5 && f1->next->next->pos==2)
        winner=player;
}

if(n1>=4)
{
    if(f1->next->pos==3 && f1->next->next->next->pos==6 && f1->next->next->pos==9 ||
       f1->next->pos==3 && f1->next->next->next->pos==9 && f1->next->next->pos==6 ||
       f1->next->pos==6 && f1->next->next->next->pos==3 && f1->next->next->pos==9 ||
       f1->next->pos==6 && f1->next->next->next->pos==9 && f1->next->next->pos==3 ||
       f1->next->pos==9 && f1->next->next->next->pos==3 && f1->next->next->pos==6 ||
       f1->next->pos==9 && f1->next->next->next->pos==6 && f1->next->next->pos==3)
        winner=player;
}

if(n2>=4)
{
    if(f2->next->pos==1 && f2->next->next->next->pos==4 && f2->next->next->pos==7 ||
       f2->next->pos==1 && f2->next->next->next->pos==7 && f2->next->next->pos==4 ||
       f2->next->pos==4 && f2->next->next->next->pos==1 && f2->next->next->pos==7 ||
       f2->next->pos==4 && f2->next->next->next->pos==7 && f2->next->next->pos==1 ||
       f2->next->pos==7 && f2->next->next->next->pos==1 && f2->next->next->pos==4 ||
       f2->next->pos==7 && f2->next->next->next->pos==4 && f2->next->next->pos==1)
        winner=player;
}
if(n2>=4)
{
    if(f2->next->pos==2 && f2->next->next->next->pos==5 && f2->next->next->pos==8 ||
       f2->next->pos==2 && f2->next->next->next->pos==8 && f2->next->next->pos==5 ||
       f2->next->pos==5 && f2->next->next->next->pos==2 && f2->next->next->pos==8 ||
       f2->next->pos==5 && f2->next->next->next->pos==8 && f2->next->next->pos==2 ||
       f2->next->pos==8 && f2->next->next->next->pos==2 && f2->next->next->pos==5 ||
       f2->next->pos==8 && f2->next->next->next->pos==5 && f2->next->next->pos==2)
        winner=player;
}

if(n2>=4)
{
    if(f2->next->pos==3 && f2->next->next->next->pos==6 && f2->next->next->pos==9 ||
       f2->next->pos==3 && f2->next->next->next->pos==9 && f2->next->next->pos==6 ||
       f2->next->pos==6 && f2->next->next->next->pos==3 && f2->next->next->pos==9 ||
       f2->next->pos==6 && f2->next->next->next->pos==9 && f2->next->next->pos==3 ||
       f2->next->pos==9 && f2->next->next->next->pos==3 && f2->next->next->pos==6 ||
       f2->next->pos==9 && f2->next->next->next->pos==6 && f2->next->next->pos==3)
        winner=player;
}
/*-----------------------------------------------------*/



}
/* Game is over so display the final board
printf("\n\n");
printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
printf("---+---+---\n");
printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
printf("---+---+---\n");
printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
*/
/* Display result message */
if(winner == 0)
{
printf("\n\n");
printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
printf("---+---+---\n");
printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
printf("---+---+---\n");
printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
printf("\nHow boring, it is a draw\n");
}
else
{
printf("\n\n");
printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
printf("---+---+---\n");
printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
printf("---+---+---\n");
printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
printf("\nCongratulations, player %d, YOU ARE THE WINNER!\n", winner);
}

p1=f1;
follow1=NULL;
while(follow1!=l1)
{
    follow1=p1;
    p3=p1;
    p1=p1->next;
    free(p3);
}

p2=f2;
follow2=NULL;
while(follow2!=l2)
{
    follow2=p2;
    p4=p2;
    p2=p2->next;
    free(p4);
}

getch();
}
