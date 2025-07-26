#include<iostream>
#include<string>
using namespace std;

/**
 * 项目：学习 String。需要引入string库
 */
int main(){
    // 初始化 String 对象 的方法
    string s1;          // 初始化 s1,其中 s1是一个空字符串
    
    // 输出一行 s1 的内容
    while (getline(cin,s1))
    {
        /* code */
        if (!(s1.empty()))
        {
            cout << s1 << endl;
        }

    }
    cout << "finish" << endl;
    
}