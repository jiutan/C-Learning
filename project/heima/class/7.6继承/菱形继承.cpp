#include <iostream>
using namespace std;

class A
{
private:
    /* data */
public:
    A(/* args */);
    ~A();

    int age;
};


/*      利用 虚继承virtual 可以解决 菱形继承 的 问题
    *   方法：继承之前，加上 关键字 irtual 变为 虚继承
    *   则：A类 为 虚基类
    *   作用：此时，同名的成员 都变为 一个 成员 了
*/

class B:virtual public A
{
private:
    /* data */
public:
    B(/* args */);
    ~B();
};

class C:virtual public A
{
private:
    /* data */
public:
    C(/* args */);
    ~C();
};

class D:public B,public C
{
private:
    /* data */
public:
    D(/* args */);
    ~D();
};



int main(){

    D d;

    d.B::age = 18;

    d.age = 28;

    return 0;
}
