/*************************************************************************
	> Motto : Be better!
	> Author: ShadowsGtt 
	> Mail  : 1025814447@qq.com
	> Time  : 2018年07月29日 星期日 13时34分51秒
 ************************************************************************/

/* 
* 本文件函数判断输入的所有通路是否可以连通
* 如果不可以连通则返回false并设置错误码
* */


 #include "../include/maze.h"

/* 判断输入的通路是否可以连通
* 通路只可以是相邻的正北 正东  正西  正南
* */
bool Maze::canRoadConnect()
{
    for(auto c :_road)
    { 
        int abs_x = abs(c.first.x-c.second.x);
        int abs_y = abs(c.first.y-c.second.y);
    
        if(abs_x == 0 )
        {
            if(abs_y != 0 && abs_y > 1)
            {
                ERRNO = MFE;
                return false;
            }
        }
        else if(abs_y == 0)
        {
            if(abs_x > 1)
            {
                ERRNO = MFE;
                return false;
            }
        }
    }
    return true;
}

