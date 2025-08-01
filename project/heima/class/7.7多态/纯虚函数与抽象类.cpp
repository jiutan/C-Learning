#include<iostream>

// 抽象类
class Base
{
private:
    /* data */
public:

    // 写成 纯虚函数
    virtual void func() = 0;            // 必须要写 virtual

};

// 子类
class Son:public Base
{
private:
    /* data */
public:

    // 子类 必须 重写 父类的 纯虚函数,否则 也 属于 抽象类(无法 实例化 对象)
    virtual void func(){
        std::cout << "function" << std::endl;
    } 

};

int main(){

    // Base b;                  // 抽象类 不允许 实例化对象
    // new Base;                // 抽象类 不允许 实例化对象

    // 使用 多态技术(指针方法) 调用
    Base *b;
    b = new Son;

    b -> func();
    delete b;       // 记得 删除

    return 0;
}



