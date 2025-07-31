#include <iostream>

// 多态
class Animal
{
private:
    /* data */
public:

    void speak(){
        std::cout << "动物在说话" << std::endl;
    }
    
    // 使用 虚函数 进行 动态多态
    // 为 虚函数表 指针
    virtual void speak1(){
        std::cout << "动物在说话" << std::endl;
    }

};

// 派生类
class Cat:public Animal
{
private:
    /* data */
public:

    void speak(){
        std::cout << "miao miao miao " << std::endl;
    }
    void speak1(){
        std::cout << "miao miao miao " << std::endl;
    }

};

class Dog:public Animal
{
private:
    /* data */
public:
    
    virtual void speak1(){
        std::cout << "wang wang wang" << std::endl;
    }

};



// 执行 说话的函数: 形参 为 Animal类对象（使用 引用：只有一个 对象）
// 地址 早绑定 - 在 编译阶段 确定 函数地址
void doSpeak(Animal &animal){                   // Animal类 的 引用

    animal.speak();             // 无论 传谁，都是 Animal中的speak函数（因为 地址 已经确定好了）
}

// 如果 想执行 猫说话，那么这个函数地址 就不能早绑定，需要 晚绑定 - 运行阶段 确定函数地址
void doSpeak1(Animal &animal){                   // Animal类 的 引用

    animal.speak1();                            // 虚函数 ： 则会 晚绑定
}

int main(){

    Cat cat;
    Dog dog;

    // C++允许 父类 与 子类 之间的类型转换
    doSpeak(cat);                    // 早绑定：输出的时 Animal的speak      Animal& animal = cat：父类的引用 指向 子类对象

    doSpeak1(cat);                   // 晚绑定：输出的是 cat的speak1
    doSpeak1(dog);                   // 晚绑定：输出的是 dog的speak1

    return 0;
}



