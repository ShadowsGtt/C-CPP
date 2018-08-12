/*************************************************************************
	> Motto : Be better!
	> Author: ShadowsGtt 
	> Mail  : 1025814447@qq.com
	> Time  : 2018年07月27日 星期五 15时53分54秒
 ************************************************************************/

#ifndef _MAZE_H
#define _MAZE_H

#include <iostream>
#include <map>
#include<cstdlib>
#include <fstream>
#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <vector>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <cstring>
#include <string>
#include <utility>

#define MAX_LINE  1024
#define MAX_LENGTH 100

using namespace std;

/* 错误码 */
enum MAZE_ERRNO
{
    INF ,     //Invalid number format
    NOOR,     //Number out of ranger
    ICF,       //Incorrect command format
    MFE       //Maze format error
};

extern MAZE_ERRNO ERRNO;

/* 坐标点 */
struct Point
{
    int x;
    int y;
    Point():x(0),y(0){}
};

/* 道路 */
struct Road
{
    Point p1;
    Point p2;
    Road(){}
};

class Maze
{
    public :
        Maze();
        ~Maze();
        bool GetInput(const char *);  //从文件中读取输入并存入_input
        bool isFormatLeagal();          //判断输入是否合法
        bool canRoadConnect();
        bool isValueLeagal();
        void CreateMaze();
        void ConnectMaze();
        void PrintMaze();
        void Move(string);
        //void WriteTestData(string data);
                                       //input[0]为行列值 input[1]为通路
    private :
        Point _mp;
        vector<string> _input;  //输入
        string *_output;         //输出
        uint32_t _rows;         //迷宫行值(未渲染)
        uint32_t _cols;         //迷宫列值(未渲染)
        vector< pair<Point,Point> >  _road;   //存储所有输入的通路 
                                //key为一条道路
                                //value为是否可以相同
        
};



/* 根据错误码打印错误类型 */
extern void maze_perror(string);
#endif
