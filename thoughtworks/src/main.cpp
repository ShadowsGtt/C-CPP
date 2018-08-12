/*************************************************************************
	> Motto : Be better!
	> Author: ShadowsGtt 
	> Mail  : 1025814447@qq.com
	> Time  : 2018年07月27日 星期五 16时30分41秒
 ************************************************************************/

#include<iostream>
#include "../include/maze.h"

using namespace std;

int main()
{
    Maze maz;
    if(!maz.GetInput("maze.input"))
        cout<<"get input failed"<<endl;
    if(!maz.isFormatLeagal())
        maze_perror("error");
    if(!maz.isValueLeagal())
        maze_perror("error");
    if(!maz.canRoadConnect())
        maze_perror("error");
    maz.CreateMaze();
    maz.ConnectMaze();
    
    string str = "1,0 DDS";
    maz.Move(str);
    maz.PrintMaze();
    return 0;
}
