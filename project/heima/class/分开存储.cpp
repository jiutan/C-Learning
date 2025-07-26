#include<iostream>  
using namespace std;

/* 成员变量 和 成员函数 分开存储 */
// 空类
class Person
{
private:
    /* data */

public:

};

// 有 成员变量 的 类
class Phone
{
private:
    /* data */
    int m_A;        // 非 静态 成员变量，属于 类的对象 上

    static int m_B;     // 静态成员变量，不属于 类的对象 上

    void func(){}       // 非静态成员函数，不属于 类的对象 上

    static void func(){}       // 静态成员函数，不属于 类的对象 上

public:

};

int Phone::m_B = 10;     // 类外初始化



void test01(){
    Person p;

    // 查看 空类对象 占用 多少内存：1 字节
    // 因为 C++ 编译器 会给 每个 空对象 分配一个字节空间，是为了 区分 不同空对象 占内存的位置
    // 每个 空对象 应该有一个 独一无二 的内存地址
    cout << "空类对象 占用 内存大小为 " << sizeof(p) << endl;
}

void test02(){

    Phone p1;
    // 查看 非静态成员变量 占的内存大小：4个字节（不属于类对象上的，不占类的内存）
    cout << "类对象 占用 内存大小为 " << sizeof(p1) << endl;
}

int main(){

    // test01();
    test02();
}


