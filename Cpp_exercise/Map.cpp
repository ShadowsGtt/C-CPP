#include "head.h"

using namespace std;


/* 使用map统计输入单词的个数
 * string 作为键
 * string出现的次数作为值
 * */
int main()
{
    map<string,size_t> word_count;
    string word;
    while(cin>>word)
        ++word_count[word];
    for(auto &w : word_count)
    {
        cout<<"单词:"<<w.first<<"  "<<"出现次数:"<<w.second<<endl;
    }

}
