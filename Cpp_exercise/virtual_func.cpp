
#include<iostream>
using namespace std;
class A
{
    public:
        virtual void print()
        {
            cout<<"A::print"<<endl;
        }
};

class B :public A
{
    public:
        void print()
        {
            cout<<"B::print"<<endl;
        }
};

class C : public B
{
    public:
        virtual void print()
        {
            cout<<"C::print"<<endl;
        }
    
};

void print(B &temp)
{
    temp.print();
}
int main()
{
    C c;
    ::print(c);
    
}
