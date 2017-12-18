//统计较短字符串在较长字符串中出现的次数

#include<stdio.h>
#include<string.h>
int main()
{
    char a[] ="aabbabaaabbba";
    char b[] = "ab";
    int i = 0,j = 0,count = 0;
    int alength = strlen(a);
    int blength = strlen(b);

    while(a[i] != '\0')  //一直循环直到a串结束
    {
        if(b[j] == a[i]) //相同下标同时向后移动
        {
            i++;
            j++;
        }
        else//不相同
        {
            if(j != 0) //如果是短字符串非第一个位置处的字符不同
                j = 0;  //
            else //如果是短字符串的第一个字符
            {
                j = 0;
                i++;
            }
        }
        if(j == blength) //如果到短串末尾
        {
            j = 0;
            count++;
        }
    }
    printf("较短字符串在较长字符串中出现的次数为:%d\n",count);
    return 0;
}
