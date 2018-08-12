/*************************************************************************
	> Motto : Be better!
	> Author: ShadowsGtt 
	> Mail  : 1025814447@qq.com
	> Time  : 2018年07月29日 星期日 13时39分40秒
 ************************************************************************/

#include "../include/maze.h"

Maze::Maze()
{
    this->_rows = 0;
    this->_cols = 0;
    this->_output = NULL;
}

Maze::~Maze()
{
    if(_output)
        delete []_output;
}
