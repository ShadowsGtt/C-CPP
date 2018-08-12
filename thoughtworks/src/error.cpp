/*************************************************************************
	> Motto : Be better!
	> Author: ShadowsGtt 
	> Mail  : 1025814447@qq.com
	> Time  : 2018年07月28日 星期六 12时28分51秒
 ************************************************************************/
#include "../include/maze.h"


/* 全局错误码 */
MAZE_ERRNO ERRNO;


void maze_perror(string m_error)
{
    switch(ERRNO)
    {
        case INF:
            cout<<m_error<<":Invalid number format"<<endl;
            break;
        case NOOR:     
            cout<<m_error<<":Number out of ranger"<<endl;
            break;
        case ICF:       
            cout<<m_error<<":Incorrect command format"<<endl;
            break;
        case MFE:
            cout<<m_error<<":Maze format erro"<<endl;
            break;
        default:
            break;
    }
    exit(-1);
}
