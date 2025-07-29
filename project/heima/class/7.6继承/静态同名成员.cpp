#include <iostream>

// 继承中 的 同名静态成员 处理方式

class Base
{
private:
    /* data */
public:

    static int m_A;         // 静态成员属性 【类内声明，类外 初始化】

    static void func(){

        std::cout << "base func" << std::endl;

    }

};

int Base::m_A = 100;        // 类外 初始化

class Son:public Base
{
private:
    /* data */
public:

    static int m_A;

    static void func(){

        std::cout << "son func" << std::endl;

    }

};

int Son::m_A = 200;



int main(){

    Son s;

    /*      通过 对象 来访问        */
    std::cout << s.m_A << std::endl;        // 访问 子类的
    s.func();

    std::cout << s.Base::m_A << std::endl;        // 访问 父类的
    s.Base::func();

    /*      通过 类名 来访问        */
    std::cout << Son::m_A << std::endl;        // 访问 子类的
    Son::func();

    std::cout << Son::Base::m_A << std::endl;        // 访问 子类对象中父类的
    Son::Base::func();

    return 0;
}