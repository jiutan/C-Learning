#include<iostream>
#include<string>
using namespace std;

// 类模板
template<class TypeName,class Typeage = int>      // 模板参数列表：设置 默认参数
class Person
{
private:
    /* data */
public:
    Person(TypeName name,Typeage age){
        this->name = name;
        this->age = age;
    }

    void display() {
        cout << "Name: " << this->name << ", Age: " << this->age << endl;
    }

    TypeName name;
    Typeage age;
};
// 1. 指定 传入类型
void printPerson1(Person<string,int> &p){           // 将 完整的类模板 作为 参数
    p.display();
}

void test1() {
    Person<string, int> p("hjs", 20); 
    printPerson1(p);  // 调用函数，传入类模板实例
}

// 2. 将 参数 模板化
template<class T1,class T2>
void printPerson2(Person<T1, T2> &p){
    p.display();
    cout << "T1的数据类型为：" << typeid(T1).name() << endl;
}

void test2() {
    Person<string, int> p("zyx", 25); 
    printPerson2(p);  // 调用函数，传入类模板实例
}

// 3. 将 整个类 模板化
template<class T>
void printPerson3(T &p){
    p.display();
    cout << "T的数据类型为：" << typeid(T).name() << endl;
}

void test3() {
    Person<string, int> p("xsb", 30); 
    printPerson3(p);  // 调用函数，传入类模板实例
}

int main(){

    test3();

    return 0;
}