//字符串逆置


#include<stdio.h>
#include<string.h>
int main()
{
    char a[] = "i am a student";
    char tmp;
    int i = 0; 
    int j = strlen(a) - 1;
    //先将字符串整体逆置
    while(i < j) 
    {
        tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
        i++;
        j--;
    }
    printf("%s\n",a);

    i = 0;
    j = 0;
    int k = 0;
    int head = 0; //每个单词的起始字母下标
    int tail = 0; //每个单词的最后字母下标
    //将每个单词逆置
    while(a[k] != '\0')
    {
        while(a[tail] != ' ' && a[tail] != '\0')
        {
            tail++;
        }
        i = head;
        j = tail - 1;
        while(i < j)
        {
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
        k = tail;
        head = ++tail;
    }
    printf("%s\n",a);
    return 0;
}
