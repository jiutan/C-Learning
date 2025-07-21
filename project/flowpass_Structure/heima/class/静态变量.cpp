#include <iostream>
using namespace std;

// 静态 成员变量
class Person
{
private:
    /* data */
public:
    // 所有对象 共享同一份 数据
    // 类内声明，类外 初始化操作
    static int m_A;             // 类内声明

};

// 类外 初始化
int Person::m_A = 100;

void test01(){
    Person p;
    cout << p.m_A << endl;

    Person p2;
    p2.m_A = 200;           // 共享 同一份 数据；m_A会被 改为 200
    cout << p.m_A << endl;
}

// 两种 访问方式
void test02(){

    // 1. 通过 对象 访问
    Person p;
    cout << p.m_A << endl;

    // 2. 通过 类名 访问
    cout << Person::m_A << endl;

}

int main(){

    test01();
    
}
