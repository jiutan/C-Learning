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
    TypeName name;
    Typeage age;
};

// 区别1：类模板 没有 自动类型推导 的 使用方式
/*
void test1(){

    Person p("hjs",20);             // 错误：没有自动类型推导，必须指定模板参数类型

}
*/

// 区别2：类模板 在 模板 参数列表中 可以有 默认参数



int main(){

    // 实例化类模板
    Person<string,int> p1("zyx",25);

    return 0;
}


