#include<iostream>
#include<string>
using namespace std;

// 类模板
template<class T1,class T2>
class Person
{
private:
    /* data */


public:
    Person(T1 name,T2 age);

    void showPerson();

    T1 Name_;
    T2 Age_;
};
// 构造函数 类外实现（需要 模板参数列表）
template<class T1,class T2>
Person<T1,T2>::Person(T1 name,T2 age)
{
    this->Age_ = age;
    this->Name_ = name;
}
// 类模板的 成员函数 的 类外实现（需要 模板参数列表）
template<class T1,class T2>
void Person<T1,T2>::showPerson(){
    cout << this->Age_ << endl;
}



int main(){

    Person<string,int> p("Tom",20);

    p.showPerson();

    return 0;
}