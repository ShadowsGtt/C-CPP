/*************************************************************************
	> Motto : Be better!
	> Author: ShadowsGtt 
	> Mail  : 1025814447@qq.com
	> Time  : 2018年07月27日 星期五 16时04分46秒
 ************************************************************************/

/*
 * 本文件中的函数提供从文件获取输入
 * 判断输入的格式是否正确
 * 如果格式正确则将输入按照一定格式保存,用于后续操作
 * 如果格式不正确则返回false,并设置错误码
* */

#include "../include/maze.h"

static bool isCharLeagal(char c);
static bool spliteString(char ,const string &,vector<string> &);
static void StringToCoordinate(const string &str,Road &p);
static bool roadFormat(const string &);
static bool store_row_col_value(string,uint32_t &,uint32_t &);



/* 从文件读取输入
*  成功:返回true并将输入存储_input
*  失败:返回false*/
bool Maze::GetInput(const char *file_name)
{
    if(!file_name)
        return false;

    FILE *fp;
    uint32_t index = 0;
    char line[MAX_LINE];

    fp = fopen(file_name,"r");
    if(!fp)
        perror("open file error");
    while( fgets(line, MAX_LINE, fp) != NULL )
    {
        if(line[0] == '\0')
            return false;
        if(line[strlen(line)-1] == '\n')
            line[strlen(line)-1] = '\0';
        (this->_input).push_back(line);
    }
    fclose(fp);

    cout<<"your input :"<<endl;
    for(auto str : _input)
        cout<<str<<endl;

    cout<<endl<<endl;
    return true;
}



/* 判断输入是否合法
* 合法返回true并存储道路信息和迷宫行列值
* 非法返回false*/
bool Maze::isFormatLeagal()
{
    
    uint32_t row,col;
    //存储 行，列值
    if(!store_row_col_value(_input[0],row,col))
    {
        ERRNO = ICF;
        return false;
    }
    
    this->_rows = row;
    this->_cols = col;
    

    //每个string 存储一条通道 
    //例如: road[0] 为:0,1 0,2
    vector<string> roads;
    if(!spliteString(';',(this->_input)[1],roads))
    {
        #ifdef TEST
        cout<<"spliteString error"<<endl;
        #endif
        ERRNO = ICF;
        return false;
    }
#ifdef TEST
    cout<<endl;
    cout<<"roads.size():"<<roads.size()<<endl;
    cout<<endl;
#endif
    for(int i = 0; i < roads.size();i++)
    {
        Road r;
        StringToCoordinate(roads[i],r);
        _road.push_back(pair<Point,Point>(r.p1,r.p2));
#ifdef TEST
    cout<<endl;
        cout<<"x1:"<<r.p1.x<<"   y1:"<<r.p1.y<<endl;
        cout<<"x2:"<<r.p2.x<<"   y2:"<<r.p2.y<<endl;
    cout<<endl;
#endif
        
    }
    
    return true;
}



static bool store_row_col_value(string str,uint32_t &_rows,uint32_t &_cols)
{
    char numstr[MAX_LENGTH] = {0};
    int j = 0,i = 0;
    int spaceNum = 0;
    int row = 0, col = 0;
    
    for(auto c : str)
    {
        if(c != ' ' && (c >= '9' && c <= '0'))
            return false;
        if(c == ' ')
            spaceNum++;
    }

    if(spaceNum != 1)
        return false;

    //获取row
    for(; i < str.size();i++)
    {
        if(str[i] == ' ')
            break;
        numstr[j] = str[i];
        j++;
    }
    i++;
    j = 0;
    row = atoi(numstr);
    bzero(numstr,sizeof(numstr));

    //获取col
    for(; i < str.size();i++)
    {
        numstr[j] = str[i];
        j++;
    }
    col  = atoi(numstr);
#ifdef TEST 
    cout<<endl;
    cout<<"row:"<<row<<"   col:"<<col<<endl;
    cout<<endl;
#endif
    _rows = row;
    _cols = col;
    return true;
}


/*  将input字符串用pattern符号分割
 *  分割结果存入output
 *  */
static bool spliteString(char pattern,const string &input,vector<string> &output)
{
    sleep(2);
    char str[MAX_LENGTH] = {0};
    int j = 0;
    
    #ifdef TEST
    cout<<endl;
    cout<<"splite string:"<<input<<"  size:"<<input.size()<<endl;
    cout<<endl;
    #endif

    //同时判断每个字符是否合法
    for(int i = 0; i < input.size();i++)
    {
        if(!isCharLeagal(input[i]))
            return false;

        str[j] = input[i];
        if(str[j] == pattern || (i == input.size()-1)){ 
            if(i != input.size()-1)
            {
                str[j] = '\0';

            }
            if(!roadFormat(str))
            {
                return false;
            }
            output.push_back(str);
            #ifdef TEST
            cout<<"通路:"<<str<<endl;
            #endif
            
           // i++;
        }
        j++;
        if(input[i] == ';')
        j= 0;
    }
    return true;
}

bool isCharLeagal(char c)
{
    if(c == ' ' || (c <= '9' && c >= '0') || c == ';' || c == ',')
        return true;
    return false;
}

/* 
 * 检测每个输入的通路格式正确性 
 *  以;分割的每个字符串中
 *  空格数等于1, 
 *  逗号数等于1时为true 
 * */
static bool roadFormat(const string &str)
{
    int spaceNum = 0;
    int commaNum = 0;
    for(int i = 0; i < str.size();i++)
        if(str[i] == ' ')
            ++spaceNum;
        else if(str[i] == ',')
            ++commaNum;
    
    if(commaNum == 2 && spaceNum == 1)
        return true;

    return false;
}



/* 将字符串转换成坐标 */
static void StringToCoordinate(const string &str,Road &p)
{
#ifdef TEST
    cout<<"要转换成坐标的字符串:"<<str<<endl;
#endif
    int i = 0;
    int j = 0;
    char numstr[MAX_LENGTH] = {0};
    
    for(int k = 0;k < 2;k++)
    {
        //x坐标转换成int
        while(str[i] != ',' && i < str.size())
        {
            numstr[j] = str[i];
            ++i; 
            ++j;
        }
        i++;
        j = 0;

        int x = atoi(numstr);
        if( k == 0 )
            p.p1.x = x;
        else if( k == 1 )
            p.p2.x = x;
        bzero(numstr,sizeof(numstr));
        
        
        //y坐标转换成int
        while(str[i] != ' ' && i < str.size())
        {
            numstr[j] = str[i];
            ++i; 
            ++j;
        }
        i++;
        j = 0;
        int y = atoi(numstr);
        if( k == 0 )
            p.p1.y = y;
        else if( k == 1 )
            p.p2.y = y;
        bzero(numstr,sizeof(numstr));
        
    }
}


