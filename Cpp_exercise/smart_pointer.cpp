/*************************************************************************
	> Motto : Be better!
	> Author: ShadowsGtt 
	> Mail  : 1025814447@qq.com
	> Time  : 2018年07月24日 星期二 16时32分26秒
 ************************************************************************/

#include<iostream>
#include<mutex>
using namespace std;

/*  实现一个线程安全的智能指针 */


/* 引用计数基类 */
class Sp_counter
{
    private :
        size_t *_count;
        std::mutex mt;
    public :
        Sp_counter()
        {
            cout<<"父类构造,分配counter内存"<<endl;
            _count = new size_t(0);
        }
        virtual ~Sp_counter()
        {
            if(_count && !(*_count) ){
                cout<<"父类析构"<<endl;
                cout<<"[释放counter内存]"<<endl;
                delete _count;
                _count = NULL;
            }
        }
    Sp_counter &operator=(Sp_counter &spc)
    {
        cout<<"父类重载="<<endl;
        cout<<"[释放counter内存]"<<endl;
        delete _count;
        this->_count = spc._count;
        return *this;
    }
    Sp_counter &GetCounter()
    {
        return *this;
    }
    size_t Get_Reference()
    {
        return *_count;
    }
    virtual void Increase()
    {
        mt.lock();
        (*_count)++;
        //cout<<"_count++:"<<*_count<<endl;
        mt.unlock();
    }
    virtual void Decrease()
    {
            mt.lock();
            (*_count)--;
            //cout<<"_count--:"<<*_count<<endl;
            mt.unlock();
        }
};

template<typename T>
class smart_pointer : public Sp_counter
{
    private :
        T *_ptr;
    public :
        smart_pointer(T *ptr = NULL);               
        ~smart_pointer();                               
        smart_pointer(smart_pointer<T> &);
        smart_pointer<T> &operator=(smart_pointer<T> &);
        T &operator*();
        T *operator->(void);
        size_t use_count();
        
};


/* 子类参构造函数&带参数构造函数 */
template<typename T>
inline smart_pointer<T>::smart_pointer(T *ptr)
{
    if(ptr){
        cout<<"子类默认构造"<<endl;
        _ptr = ptr;
        this->Increase();
    }
}   


/* 子类析构函数 */
template<typename T>
smart_pointer<T>::~smart_pointer()
{
    /* 指针非空才析构 */
    if(this->_ptr){
        cout<<"子类析构,计数减1"<<endl;
        if(this->Get_Reference())
            this->Decrease();
        if(!(this->Get_Reference()) ){
            cout<<"(((子类析构,主内存被释放)))"<<endl;
            delete _ptr;
            _ptr = NULL;
        }
    }
}

/* 得到引用计数值 */
template<typename T>
inline size_t smart_pointer<T>::use_count()
{
    return this->Get_Reference();
}

/* 拷贝构造 */
template<typename T>
inline smart_pointer<T>::smart_pointer(smart_pointer<T> &sp)
{
    cout<<"子类拷贝构造"<<endl;

    /* 防止自己对自己的拷贝 */
    if(this != &sp){
        this->_ptr = sp._ptr;
        this->GetCounter() = sp.GetCounter();
        this->Increase();
    }
    
}
/* 赋值构造 */
template<typename T>
inline smart_pointer<T> &smart_pointer<T>::operator=(smart_pointer<T> &sp)
{

    /* 防止自己对自己的赋值以及指向相同内存单元的赋值 */
    if(this != &sp){

        cout<<"赋值构造"<<endl;

        /* 如果不是构造一个新智能指针并且两个只能指针不是指向同一内存单元 */
        /* =左边引用计数减1,=右边引用计数加1 */
        if(this->_ptr && this->_ptr != sp._ptr){
            this->Decrease();

            /* 引用计数为0时 */
            if(!this->Get_Reference()){
                cout<<"引用计数为0,主动调用析构"<<endl;
                this->~smart_pointer();
                //this->~Sp_counter();
                cout<<"调用完毕"<<endl;
            }
        }

        this->_ptr = sp._ptr;
        this->GetCounter() = sp.GetCounter();
        this->Increase();
    }
    return *this;
}

/* 重载解引用*运算符 */
template<typename T>
inline T &smart_pointer<T>::operator*()
{
    return *(this->_ptr);
}
template<typename T>
inline T *smart_pointer<T>::operator->(void)
{
    return this->_ptr;
}

int main()
{
    int *a = new int(10);
    int *b = new int(20);
    cout<<"-------------默认构造测试----------------->"<<endl;
    cout<<"构造sp"<<endl;
    smart_pointer<int> sp(a);
    cout<<"sp.use_count:"<<sp.use_count()<<endl;
    cout<<"------------------------------------------>"<<endl<<endl;
    
    {
        cout<<"-------------拷贝构造测试----------------->"<<endl;
        cout<<"构造sp1  :sp1(sp)"<<endl;
        smart_pointer<int> sp1(sp);
        cout<<"构造sp2  :sp2(sp)"<<endl;
        smart_pointer<int> sp2(sp1);
        cout<<"sp1和sp2引用计数为3才是正确的"<<endl;
        cout<<"sp1.use_count:"<<sp1.use_count()<<endl;
        cout<<"sp2.use_count:"<<sp2.use_count()<<endl;
        cout<<"------------------------------------------>"<<endl<<endl;
        cout<<"调用析构释放sp1,sp2"<<endl;
    }
    cout<<"-------------析构函数测试----------------->"<<endl;
    cout<<"此处sp.use_count应该为1才是正确的"<<endl;
    cout<<"sp.use_count:"<<sp.use_count()<<endl;
    cout<<"------------------------------------------>"<<endl<<endl;
    
    cout<<"-------------赋值构造测试----------------->"<<endl;
    cout<<"构造sp3  :sp3(b)"<<endl;
    smart_pointer<int> sp3(b);
    cout<<"sp3.use_count:"<<sp3.use_count()<<endl;
    cout<<"sp3 = sp"<<endl;
    sp3 = sp;
    cout<<"sp3先被释放,然后sp3引用计数为2才正确,sp的引用计数为2才正确"<<endl;
    cout<<"sp3.use_count:"<<sp3.use_count()<<endl;
    cout<<"sp.use_count :"<<sp.use_count()<<endl;
    cout<<"------------------------------------------>"<<endl<<endl;
    
    cout<<"-------------解引用测试----------------->"<<endl;
    cout<<"*sp3:"<<*sp3<<endl;
    cout<<"*sp3 = 100"<<endl;
    *sp3 = 100;
    cout<<"*sp3:"<<*sp3<<endl;
    cout<<"------------------------------------------>"<<endl;

    

   // cout<<"sp3.use_count:"<<sp3.use_count()<<endl;
    //cout<<"sp.use_count:"<<sp.use_count()<<endl;


    cout<<"===================end main===================="<<endl;
    return 0;
}
