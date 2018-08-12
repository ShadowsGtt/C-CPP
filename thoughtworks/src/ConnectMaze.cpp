/*************************************************************************
	> Motto : Be better!
	> Author: ShadowsGtt 
	> Mail  : 1025814447@qq.com
	> Time  : 2018年07月29日 星期日 13时43分26秒
 ************************************************************************/

#include "../include/maze.h"

/*
* 本文件函数连通迷宫中可以相通的道路
* */

/* 连通迷宫中的道路 */
static Point coordinateMap(Point );

void Maze::ConnectMaze()
{
    for(auto c : _road)
    {
        Point p1 = coordinateMap(c.first);
        Point p2 = coordinateMap(c.second);

        if(p1.x == p2.x)
        {
            if(p1.y < p2.y)
            {
                for(int i = p1.y; i < p2.y;i++)
                {
                    _output[p1.x*(_cols*2+1)+i] = "[R]";
                    #ifdef TEST
                    cout<<"渲染:"<<"("<<p1.x<<"," <<i<<")"<<endl;
                    cout<<"插入:"<<p1.x*(_cols*2+1)+i<<endl;
                    #endif
                }
            }
            else
            {
                for(int i = p2.y; i < p1.y;i++)
                {

                    _output[p1.x*(_cols*2+1)+i] = "[R]";
                    #ifdef TEST
                    cout<<"渲染:"<<"("<<p1.x<<"," <<i<<")"<<endl;
                    cout<<"插入:"<<p1.x*(_cols*2+1)+i<<endl;
                    #endif
                }
            }
            
        }
        else if(p1.y == p2.y)
        {
            if(p1.x < p2.x)
            {
                for(int i = p1.x; i < p2.x;i++)
                {
                    _output[i*(_cols*2+1)+p1.y] = "[R]";
                    #ifdef TEST
                    cout<<"渲染:"<<"("<<i<<"," <<p1.y<<")"<<endl;
                    cout<<"插入:"<<i*(_cols*2+1)+p1.y<<endl;
                    #endif
                }
            }
            else
            {
                for(int i = p2.x; i < p1.x;i++)
                {
                    _output[i*(_cols*2+1)+p1.y] = "[R]";
                    #ifdef TEST
                    cout<<"渲染:"<<"("<<i<<"," <<p1.y<<")"<<endl;
                    cout<<"插入:"<<i*(_cols*2+1)+p1.y<<endl;
                    #endif
                }
            }
        }
    }
}

/* 将原始坐标 映射 成新坐标 */
static Point coordinateMap(Point p)
{
    Point np;
    np.x = 2*p.x + 1;
    np.y = 2*p.y + 1;

    return np;
}


