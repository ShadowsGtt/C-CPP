/*************************************************************************
	> Motto : Be better!
	> Author: ShadowsGtt 
	> Mail  : 1025814447@qq.com
	> Time  : 2018年07月29日 星期日 14时12分27秒
 ************************************************************************/


#include "../include/maze.h"
/* 创建迷宫图 */
void Maze::CreateMaze()
{
    int row = 2*_rows + 1;
    int col = 2*_cols + 1;

    _output = new string[row*col]();
    
    for(int i = 0;i < row;i++)
    {
        for(int j = 0;j < col;j++)
        {
            (this->_output)[i*col+j] = "[W]";
        }
    }
    for(int i = 0; i < _rows;i++)
    {
        for(int j = 0;j < _cols;j++)
        {
            int x = 2*i + 1;
            int y = 2*j + 1;
            _output[x*col + y] = "[R]";
            
        }
    }
    
}


