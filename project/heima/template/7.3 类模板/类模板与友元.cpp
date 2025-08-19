#include<iostream>
#include<string>
using namespace std;

// 提前让 编译器 知道 Person类 存在
template<class T1,class T2>
class Person;

// 全局函数 类外实现（需 类内声明）
// 全局函数 不需要 加 作用域；但 需要 模板参数
template<class T1,class T2>
void printPerson2(Person<T1,T2> &p){                // 这是一个 函数模板 的 实现
    cout << "类外实现 " << endl;
    cout << p.Name_ << endl;
    cout << p.Age_ << endl;
}


template<class T1,class T2>
class Person
{
private:
    T1 Name_;
    T2 Age_;

    // 全局函数 类内实现：
    friend void printPerson(Person<T1,T2> &p){                 // 加上 friend 就为 友元 ，全局函数
        cout << p.Name_ << endl;
        cout << p.Age_ << endl;
    }

    // 全局函数 类外实现，类内声明
    // friend void prientPerson2(Person<T1,T2> &P);        // 这是一个 普通函数的 声明
    // 如果 全局函数 是 类外实现，需要让 编译器 提前知道 这个函数的 存在
    friend void printPerson2<>(Person<T1,T2> &P);         // 需 声明 这是一个 模板函数： 加 空模板 的 参数列表

public:
    Person(T1 name,T2 age);
    
};

template<class T1,class T2>
Person<T1,T2>::Person(T1 name,T2 age)
{
    this -> Age_ = age;
    this -> Name_ = name;
}



int main(){

    Person<string,int> p("zyx",20);

    printPerson2(p);

    return 0;
}

