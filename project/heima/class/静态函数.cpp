#include<iostream>
using namespace std;


class Person
{
private:
    /* data */
public:

    static int m_A;         // 静态 变量
    int m_B;                // 非 静态变量

    // 静态 成员函数
    static void func(){
        cout << "static void func 调用" << endl;

        // 静态成员函数 可以访问 静态成员变量
        m_A = 100;

        // 静态成员函数 不可访问 非静态成员变量：无法区分 到底是 哪个对象 的 变量
        // m_B = 200;
    }
};

int Person::m_A = 0;            // 类外 初始化
