#include <iostream>
#include <string>

// 多态
class Animal
{
private:
    /* data */
public:

    Animal(){
        std::cout << "Animal构造函数" << std::endl;
    }
    /*      虚析构： 可以解决 父类指针释放子类对象时 不彻底 的问题      */ 
    // virtual ~Animal(){
    //     std::cout << "Animal 虚析构函数" << std::endl;
    // }

    /*      纯虚析构：纯虚析构 需要有 声明 和 具体实现 的（有可能 父类 有 些属性 要 开辟到 堆区）          */
    // 注意：纯虚析构 需要 代码实现 定义
    // 有了 纯虚析构 ，这个 类 也为 抽象类，无法 实例化对象
    virtual ~Animal() = 0;

    // 使用 纯虚函数 进行 动态多态
    // 为 虚函数表 指针
    virtual void speak() = 0;

};
// 纯虚析构 需要 代码定义
Animal::~Animal(){
    std::cout << "Animal 纯虚析构函数" << std::endl;
}

// 派生类
class Cat:public Animal
{
public:
    // 构造函数
    Cat(std::string name);

    /*      提供 析构函数 在使用完后 释放内存   */
    ~Cat();

    // 子类 必须重写
    void speak(){
        std::cout << "Cat构造函数" << std::endl;
        std::cout << *m_Name <<"：miao miao miao " << std::endl;
    }
    // 给猫 起名字
    std::string* m_Name;         // 做成 指针，想让 小猫名字 创建在 堆区，用该指针去维护
};
// 定义 构造函数
Cat::Cat(std::string name){
    // 将 数据 创建在 堆区
    m_Name = new std::string(name);  // 在 堆区 创建一个 string类型 的 name，并用 m_name 指向它

}
// 定义 析构函数
Cat::~Cat(){
    if(m_Name != NULL){
        std::cout << "Cat析构函数" << std::endl;
        delete m_Name;          // 应该 释放掉
        m_Name = NULL;
    }
}

class Dog:public Animal
{
public:
    // 子类 必须重写
    virtual void speak(){
        std::cout << "wang wang wang" << std::endl;
    }

};


int main(){

    // 开辟堆区 ，创建 父类指针 指向 子类对象
    Animal* animal = new Cat("Tom");

    animal -> speak();
    // 父类 指针 在 析构时，不会调用 子类的析构函数，将 导致 内存泄漏
    // 解决方法：将 父类的析构 变为 虚析构
    delete animal;

    return 0;
}



