#include<iostream>
#include<string>
#include<cctype>        // 处理字符串中的内容的头文件
using namespace std;
/**
 * 习题：这是 3.2.3 章节的习题
 */
int main(){

#if 0       // 练习3.6：使用for将字符串内的所有字符用x代替
    string str("HelloWorld");
    for(auto &c : str)   // 使用范围for语句。引用c作为str的别名，对c操作便可直接对str操作       
        c = 'x';
    cout << str << endl;
#elif 0     // 练习3.7：若类型为char 会发生什么：我猜：只改变第一个字母为x，其他正常；答案：无变化
    string str("Hello");
    for(char &c : str)   // 使用范围for语句。引用c作为str的别名，对c操作便可直接对str操作       
        c = 'x';
    cout << str << endl;

#elif 0     // 练习3.8：用while循环和传统for循环写一遍3.6,感觉那个更好:范围for语句更好
    string str("Helloworld");
    string s("Helloworld");
    int i=0;
    while (i <= str.size())
    {
        str[i]='x';
        ++i;
    }
    cout << str << endl;

    for (int j = 0; j <= s.size(); j++)
    {
        s[j]='x';
    }
    cout << s << endl;
#elif 0     // 练习3.9：判断下面程序是否合法。我猜：不合法，s为空string，无法用s[0]指引。答案：合法，但是输出空白
    string s;
    cout << s[0] << endl;
#elif 0     // 练习3.10：编写程序：读如一个包含标点符号的字符串，将标点符号去除后，输出其他部分。
    /* 使用cctype头文件：ispunct(c)函数，若识别为标点符号则为真，否则为假 */
    string str("Hello!World");
    for(auto &c : str)
    {   if (!(ispunct(c)))
        {
            cout << c;
        }
    }
    cout << endl;
#else       // 练习3.11：判断下面程序是否合法.答案：合法，且c为char类型
    const string s="keep out!";
    for(auto &c : s )
    {
        /**/
    }

#endif

}