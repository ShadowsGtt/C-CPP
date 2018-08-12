/*************************************************************************
	> Motto : Be better!
	> Author: ShadowsGtt 
	> Mail  : 1025814447@qq.com
	> Time  : 2018年07月29日 星期日 13时38分10秒
 ************************************************************************/

#include "../include/maze.h"
/* 打印迷宫 */
void Maze::PrintMaze()
{
    int row = _rows*2 + 1;
    int col = _cols*2 + 1;

    cout<<"row"<<row<<"col"<<col<<endl;
    _output[col*_mp.x + _mp.y] = "[*]";
    for(int i = 0;i < row;i++)
    {
        for(int j = 0;j < col;j++)
        {
            
            cout<<(this->_output)[i*col+j]<<" ";
        }
        cout<<endl;
    }
}
