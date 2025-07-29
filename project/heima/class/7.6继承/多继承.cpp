#include<iostream>

// 多继承语法
class Base1
{
private:
    /* data */
public:
    Base1(/* args */);

    int m_A;

};

Base1::Base1(/* args */)
{
    m_A = 100;
}

class Base2
{
private:
    /* data */
public:
    Base2(/* args */);

    int m_A;

};

Base2::Base2(/* args */)
{
    m_A = 500;
}

// 子类 (多继承)
class Son:public Base1,public Base2
{
private:
    /* data */
public:
    Son();

    int m_C;
    int m_D;
};
Son::Son(){
    m_C = 300;
    m_D = 400;
}

int main(){

    Son s;

    std::cout << sizeof(s) << std::endl;

    std::cout << s.Base1::m_A << std::endl;


    return 0;
}





