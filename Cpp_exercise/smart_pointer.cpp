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
            cout<<"父类构造"<<endl;
            _count = new size_t(0);
        }
        virtual ~Sp_counter()
        {
            cout<<"父类析构"<<endl;
            if(_count && !(*_count) ){
                delete _count;
                _count = NULL;
            }
        }
        Sp_counter &operator=(Sp_counter &spc)
        {
            cout<<"父类重载="<<endl;
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
            cout<<"_count++:"<<*_count<<endl;
            mt.unlock();
        }
        virtual void Decrease()
        {
            mt.lock();
            (*_count)--;
            cout<<"_count--:"<<*_count<<endl;
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
        ~smart_pointer()
        {
            cout<<"子类析构"<<endl;
            if(this->_ptr)
            if(!(this->Get_Reference()) ){
                delete _ptr;
                _ptr = NULL;
            }
            else{
                cout<<"---------"<<endl;
                this->Decrease();
            }
        }
        smart_pointer(smart_pointer<T> &);
        smart_pointer<T> &operator=(smart_pointer<T> &);
        size_t use_count();
        
};


/* 得到引用计数值 */
template<typename T>
inline size_t smart_pointer<T>::use_count()
{
    return this->Get_Reference();
}

/* 无参构造函数&带参数构造函数 */
template<typename T>
inline smart_pointer<T>::smart_pointer(T *ptr)
{
    if(ptr){
        _ptr = ptr;
        this->Increase();
    }
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
    cout<<"赋值构造"<<endl;

    /* 防止自己对自己的赋值 */
    if(this != &sp){

        /* 如果使用赋值构造去构造一个新智能指针时 */
        if(this->_ptr){
            this->Decrease();

            /* 引用计数为0时 */
            if(!this->Get_Reference()){
                cout<<"引用计数为0"<<endl;
                this->~smart_pointer();
                this->~Sp_counter();
            }
        }

        this->_ptr = sp._ptr;
        this->GetCounter() = sp.GetCounter();
        this->Increase();
    }
    return *this;
}
int main()
{
    int *a = new int(10);
    smart_pointer<int> sp(a);
    {
        smart_pointer<int> sp1(sp);
        smart_pointer<int> sp2(sp1);
        cout<<"sp1.use_count:"<<sp1.use_count()<<endl;
        cout<<"sp2.use_count:"<<sp2.use_count()<<endl;
    }

    cout<<"sp.use_count:"<<sp.use_count()<<endl;
    return 0;
}
