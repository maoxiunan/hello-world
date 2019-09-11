/*********************************
 *						         *
 * 文件夹: ▲03 栈和队列\04 Maze *
 * 						         *
 * 内  容: 迷宫相关函数测试      *
 *                               *
 *********************************/

#include "Maze.c"						//**▲03 栈和队列**//

int main_c(int argc, char *argv[])
{
    /***二维的迷宫数组*/
    MazeType maze[N][N];
    /****开始和结算的位置*/
    PosType start, end;
    /**迷宫*/
    SElemType_Sq e;
    char Re = 'Y';

    while(Re=='Y' || Re=='y')
    {
        InitMaze(maze, &start, &end);	//初始化迷宫，包括出入口
        ShowMaze(maze);					//显示迷宫的初始状态
        MazePath(maze,start,end);		//迷宫寻路

        printf("重置？（Y/N）：");
        scanf("%c", &Re);
    }

    return 0;
}
