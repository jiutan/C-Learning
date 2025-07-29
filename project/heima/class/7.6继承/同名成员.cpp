#include<iostream>

// 继承中 同名成员处理
class Base
{
private:
    /* data */
public:
    Base(){
        m_a = 100;
    }

    void func(){
        std::cout << "base func" << std::endl;
    }

    int m_a;
};

class Son:public Base
{
private:
    /* data */
public:
    Son(){
        m_a = 200;
    }

    void func(){
        std::cout << "Son func" << std::endl;
    }

    int m_a;
};

int main(){

    Son s;

    std::cout << s.m_a << std::endl;

    // 访问父类的 成员
    std::cout << s.Base::m_a << std::endl;

    s.func();           // 调用 子类 中的 成员函数
    
    s.Base::func();     // 调用 父类 中的 成员函数

    return 0;
}

