#include <stdio.h>
#include <stdlib.h>

char map[10][10]={
    {'#','#','#','#','#','#','#','#','#','#'},
    {'#','I','#','#','#','#','#','#','#','#'},
    {'#',' ',' ','#','#','#','#','#','#','#'},
    {'#','#',' ','#','#',' ',' ',' ','#','#'},
    {'#','#',' ','#','#',' ','#',' ','#','#'},
    {'#',' ',' ','#','#',' ','#',' ','#','#'},
    {'#',' ','#','#','#',' ','#','#','#','#'},
    {'#',' ',' ',' ',' ',' ','#','#','#','#'},
    {'#','#','#','#','#',' ',' ',' ',' ','#'},
    {'#','#','#','#','#','#','#','#','X','#'}
};

int meX=1,meY=1;

void drawMap()
{
    int i,j;

    system("cls");
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            printf("%c",map[i][j]);
        }
        printf("\n");
    }
}

int isWall(int x,int y)
{
    return map[y][x]=='#';//数组写法上和数学上不一样//
}

int isExit(int x,int y)
{
    return map[y][x]=='X';
}
int move(int offsetX,int offsetY)
{
    if (isExit(meX+offsetX,meY+offsetY))
    {
        return 1;
    }
    if(!isWall(meX+offsetX,meY+offsetY))
    {
        map[meY][meX]='D';//横坐标v在后，纵坐标在数组前//
        meX+=offsetX;
        meY+=offsetY;
        map[meY][meX]='F';
        drawMap();
    }
    return 0;
}

int main()
{
    int successed;
    drawMap();
    while(1)
    {
        switch (getch())
        {
            case 'w':
                successed = move(0,-1);
                break;
            case 's':
                successed = move(0,1);
                break;
            case 'a':
                successed = move(-1,0);
                break;
            case 'd':
                successed = move(1,0);
                break;
            case 'q':
                return 0;
        }
        if(successed)
        {
            printf("Congratulations! You Win!!!");
            break;
        }
    }
	return 0;
}
