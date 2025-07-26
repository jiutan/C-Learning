#include <iostream>

// 赋值 运算符 重载
class Person
{
private:
    /* data */
    
public:
    Person(int age);
    ~Person();

    int *m_Age;     // 待 开辟到 堆区

    // 重载 赋值运算符
    Person& operator=(Person &p){               // 返回引用，才是 真的 自身
        
        // 编译器 提供的 前拷贝：m_age = p.m_age

        // 应该 先判断 该对象 是否 有属性 在堆区：如果有 则 先释放干净，然后 再进行 深拷贝
        if(m_Age != NULL){
            delete m_Age;               // 先将 自身 属性 释放干净
            m_Age = NULL;
        }

        // 深拷贝操作
        m_Age =  new int(*p.m_Age);     // 在堆区 开辟出 新的 空间，并用 自身 去 管理它

        // 增加 返回值，为了 链式 连接
        return *this;                   // 返回 对象的本身： 指向自身的指针 为 this，找回自身本体 为 *this
        
    }
};

// 构造函数 时：将 数据 开辟到 堆区
Person::Person(int age)
{
    m_Age = new int(age);                   // 用 m_age 来 维护/管理 堆区age数据
}

// 析构函数：释放 堆区 的数据
Person::~Person(){

    if(m_Age != NULL){
        delete m_Age;                       // 释放 内存
        m_Age = NULL;
    }

}

void test01(){
    Person p1(18);
    Person p2(20);
    Person p3(30);

    p3 =p2 = p1;                            // 会使：堆区内存重复释放，程序崩溃。（因为：p2与p1 都指向 一块 堆区 内存）

    std::cout << *p1.m_Age << "  " << *p2.m_Age << "  " << *p3.m_Age << std::endl;
}

int main(){

    test01();

    return 0;
}
