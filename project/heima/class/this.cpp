#include<iostream>
using namespace std;

class Person
{
private:
    /* data */
public:
    // 构造函数
    Person(int age){
        // age = age;          // 会认为 三个 age 为 同一个。而不是 成员属性

        // 使用 this指针，与 同名 形参 进行区分
        this -> age = age;                      // this指针，指向的是 被调用的成员函数 所属的对象

    }

    // 成员函数
    // 若要 返回 类对象本体，需要使用 引用的方式 来 返回。（若不用引用，则对象变了）
    Person& PersonAddAge1(Person &p){

        this->age += p.age;             // 将 p.age 加到 自身 age中

        // 通过 return *this 来 返回 类对象
        return *this;                   // this 为 指向 p2的 指针，*this 指向的是 p2这个对象本体

    }

    // 不用 引用&：会 创建出 新对象来 接受 返回值，而不是 原对象本身【引用 指向 本身，非引用 则为 拷贝】
    Person PersonAddAge2(Person &p){

        this->age += p.age;             // 将 p.age 加到 自身 age中

        // 通过 return *this 来 返回 类对象
        return *this;                   // this 为 指向 p2的 指针，*this 指向的是 p2这个对象本体

    }

    int age;

};

// 1. 解决 名称冲突
void test01(){
    Person p1(18);                  // this 指向 p1

    cout << "p1 的 年龄 为 :" << p1.age << endl;


}

// 2. 返回对象 本身 用 *this
void test02(){

    Person p1(10);

    Person p2(10);              // 希望 将p1上的 age 加到 p2 上

    Person p3(10);              // 希望 将p1上的 age 加到 p3 上

    // p2.PersonAddAge(p1);

    /*      链式 编程 思想      */
    p2.PersonAddAge1(p1).PersonAddAge1(p1).PersonAddAge1(p1);          // 可以 无限的追加

    // 非引用：相当于 每一个返回都为 新对象p3‘、p3’‘等，不是 对p3对象的叠加 ，所以 永远为20
    p3.PersonAddAge2(p1).PersonAddAge2(p1).PersonAddAge2(p1);          

    cout << "p2的年龄为" << p2.age <<endl;

    cout << "p3的年龄为" << p3.age <<endl;
}

int main(){

    // test01();

    test02();

}
