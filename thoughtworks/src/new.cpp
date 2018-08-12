/*************************************************************************
	> Motto : Be better!
	> Author: ShadowsGtt 
	> Mail  : 1025814447@qq.com
	> Time  : 2018年08月04日 星期六 17时08分18秒
 ************************************************************************/
#include "../include/maze.h"


static Point coordinateMap(Point p)
{
    Point np;
    np.x = 2*p.x + 1;
    np.y = 2*p.y + 1;

    return np;
}

void Maze::Move(string input)
{
    if(input.size() == 0)
        return;

    int i = 0;
    int j = 0;

    char str[MAX_LENGTH] = {0};
    while(input[i] != ',')
    {
        str[j] = input[i];
        i++;
    }

    i++;
    int row = atoi(str);
    cout<<"row:"<<row<<endl;
    bzero(str,sizeof(str));

    while(input[i] != ' ')
    {
        str[j] = input[i];
        i++;
    }
    i++;
    int col = atoi(str);
    cout<<"col:"<<col<<endl;
    
    Point p ;
    p.x = row;
    p.y = col;
    
    Point np = coordinateMap(p);

    cout<<"机器人坐标点:"<<endl;
    cout<<"x:"<<np.x<<"    y:"<<np.y<<endl;

    while(i < input.size())
    {
        if(input[i] == 'W')
        {
            if(_output[(_cols*2+1)*(np.x - 1) + np.y] != "[W]")
            {
                np.x--;
            }
        }
        else if(input[i] == 'S')
        {
            if(_output[(_cols*2+1)*(np.x + 1) + np.y] != "[W]")
            {
                np.x++;
            }
        }
        else if(input[i] == 'A')
        {
            if(_output[(_cols*2+1)*np.x + np.y - 1] != "[W]")
            {
                np.y--;
            }
        }
        else if(input[i] == 'D')
        {
            if(_output[(_cols*2+1)*np.x + np.y + 1] != "[W]")
            {
                np.y++;
            }

        }
        i++;
    }
cout<<"最终位置"<<endl;
    cout<<"x:"<<np.x<<"    y:"<<np.y<<endl;
    _mp = np;

}
