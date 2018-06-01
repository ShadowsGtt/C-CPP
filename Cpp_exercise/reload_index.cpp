/*************************************************************************
	> File Name: reload_index.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年05月09日 星期三 19时24分38秒
 ************************************************************************/

#include<iostream>
#include<stdlib.h>
using namespace std;

class Vector
{
    private:
        int array[5];
    public:
        Vector()
        {
            for(int i = 0;i < 5;i++)
            array[i] = 0;
        }
        ~Vector(){}
        int &operator[](int i)
        {
            if(i < 0 || i > 4)
            {
                cout<<"error"<<endl;
                exit(-1);
            }
            return array[i];
        }
};

int main()
{
    Vector aa;
    aa[3] = 3;
    cout<<aa[3]<<endl;
}
