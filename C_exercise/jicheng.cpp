#include<iostream>
using namespace std;

class A
{
    private :
        int a;
    public :
    A(int a = 1):a(a){cout<<"A construct"<<endl;}
        int getA()
        {
            return a;
        }
};

class B : public A
{
    private :
        int b;
    public :
        //B(int b = 2):A(2){cout<<"B construct"<<endl;}
        B(int a  ,int b = 2):A(a),b(b){cout<<"B construct"<<endl;}
        int getB()
        {
            return b;
        }
};

class C : public B
{
    private:
        int c;
    public :
        int getC()
        {
            return c;
        }
};
int main()
{
    //B b(10,20);
    //cout<<"b.getA:"<<b.getA()<<endl;
    //cout<<"b.getB:"<<b.getB()<<endl;
    //cout<<"d.getD:"<<d.getD()<<endl;
}
