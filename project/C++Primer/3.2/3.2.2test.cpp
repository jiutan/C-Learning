#include<iostream>
#include<string>
using namespace std;

/**
 * 项目：这是第3.2.2节string的练习题
 */
int main(){

#if 0       // 练习3.2
    // 一次读入一行
    string s1;
    getline(cin,s1);
    cout << s1 << endl;
    // 一次读入一个
    string s2;
    cin >> s2;
    cout << s2 << endl;

#elif 0     // 练习3.3：说明string类的输入运算符和getline函数分别是如何处理空白字符
    // 字符串字面值
    cout << "输入运算符 是 从第一个非空白字符开始，到第一个空白字符结束" << endl;

    // string类对象
    string str("getline()函数 是 从第一个非空白字符开始，到 回车换行符结束。（中间可以有空格）");
    cout << str << endl;

#elif 0     // 练习3.4：编写比较程序
    // 比较两个字符串是否想等，并输出结果。若不相等，则输出较大的那个字符串。
    string s1,s2;
    cin >> s1 >> s2;
    if (s1==s2)
    {
        cout << "two strings are equality" << endl;
    }else{
        if (s1>s2)
        {
            cout << "the bigger string is " << s1 << endl;
        }else{
            cout << "the bigger string is " << s2 << endl;
        }
    }
    // 比较两个字符串是否等长（使用s.size）,若不等长，则输出长度较大的。
    if (s1.size() == s2.size())
    {
        cout << "two strings have same length" << endl;
    }else{
        if (s1.size()>s2.size())
        {
            cout << "the longer string is " << s1 << endl;
        }else{
            cout << "the longer string is " << s2 << endl;
        }
        
    }

#else      // 练习3.5：输入多个字符串，并将其串联。
    string s1,s2,s3;
    cin >> s1 >> s2 >> s3;
    cout << s1 + s2 + s3 << endl;
    // 使用空格隔开（string类+字符串字面值 是可以的）
    cout << s1 + " " + s2 + " " + s3 << endl;
#endif
}