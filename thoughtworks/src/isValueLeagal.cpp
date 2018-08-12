/*************************************************************************
	> Motto : Be better!
	> Author: ShadowsGtt 
	> Mail  : 1025814447@qq.com
	> Time  : 2018年07月29日 星期日 13时30分35秒
 ************************************************************************/


#include "../include/maze.h"

static bool isRange(Road,int,int);

/* 检查输入值是否符合在合理范围 */
bool Maze::isValueLeagal()
{
   
    if(_rows <=0 || _cols <= 0)
        return false;
    /* 检查每条通路的点范围 */
    for(auto c : _road)
    {
        Road r;
        r.p1 = c.first;
        r.p2 = c.second;
        if(!isRange(r,_rows,_cols))
        {
            ERRNO = NOOR;
            return false;
        }
    }
    return true;
}


//一条路的两个点是否在范围內
static bool isRange(Road r,int rangX,int rangY)
{
    int x1 = r.p1.x;
    int y1 = r.p2.y;
    int x2 = r.p2.x;
    int y2 = r.p2.y;


    if(x1 < 0 || x1 >= rangX || x2 < 0 || x2 >= rangX)
        return false;
    if(y1 < 0 || y1 >= rangY || y2 < 0 || y2 >= rangY)
        return false;

    return true;
}


