/*************************************************************************
	> Motto : Be better!
	> Author: ShadowsGtt 
	> Mail  : 1025814447@qq.com
	> Time  : 2018年07月27日 星期五 13时24分21秒
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;

class String
{
    public :
        String(const char *str = NULL);
        ~String();
        String(String &);
        
    //String &String::String(const char *str = NULL);
        
        String &operator=(String &);
        char &operator[](size_t ); 
        size_t size();
    String & String(const char *str)
    {
        String st(str);
        return st; 

    }

    private :
        char *_str;
        size_t _size;
};

/*
String &String::String(const char *str = NULL)
{
    cout<<"not 默认构造"<<endl;
    if(str){
        _size = strlen(str);
        _str  = new char[_size + 1];
        strncpy(_str,str,_size);
    }
    else
        _size = 0;

    return *this;
}
*/

/* 析构函数 */
String::~String()
{
    if(_str){
        delete[] _str;
        _size = 0;
    }
}

/* 默认构造 */
inline String::String(const char *str)
{
    cout<<"默认构造"<<endl;
    if(str){
        _size = strlen(str);
        _str  = new char[_size + 1];
        strncpy(_str,str,_size);
    }
    else
        _size = 0;
}

/* 拷贝构造 */
inline String::String(String &str)
{
    if(this != &str && str._str)
    {
        cout<<"拷贝构造"<<endl;
        _size = str._size;
        _str = new char[_size + 1];
        strncpy(_str,str._str,_size);
    }
}



/* 赋值构造 */
inline String &String::operator=(String &str)
{
    cout<<"赋值构造"<<endl;
    if(this != &str && str._str ){
        if(_str){
            delete []_str;
            _size = 0;
        }
        _size = str._size;
        _str  = new char[_size + 1];
        strncpy(_str,str._str,_size); 
    }

    return *this;
}

inline char &String::operator[](size_t index)
{
    cout<<"重载[]"<<endl;
    return _str[index];
}

/* 得到字符串长度 */
inline size_t String::size(void)
{
    return _size;
}


int main()
{
    //String str1("abc");
  //String str = "abc";  
    String str2 = String("ab");

    //String str2(str1);
    //String str3 = str1 ;
    //str3 = str1;
    //cout<<str1[0]<<endl;
    
    //cout<<st.get_ptr()<<endl;
    return 0;
}
