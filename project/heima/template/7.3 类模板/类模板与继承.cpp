#include<iostream>
using namespace std;

// 类模板
template<class T>
class Base
{
private:
    /* data */
public:
    T m;
};

class Son:public Base<int>           // 如果 继承父类模板，必须指定父类模板的类型
{
private:
    /* data */
public:
    
};

// 如果想 灵活指定 父类中T的类型，子类 也需要变为 类模板
template<class T1,class T2>
class Son2:public Base<T2>          // Base类 的 类型为 T2
{
private:
    /* data */
public:
    T1 obj;
};


int main()
{
    Son s1;

    Son2<int,char> s2;          // T1为 int，T2为char

    return 0;
}
