#include<iostream>
#include<string>

// 重载 关系运算符

class Person
{
private:
    /* data */
public:
    Person(std::string name,int age);

    int m_age;
    std::string m_name;

    /*      重载 == 关系运算符     */
    bool operator==(const Person &p){
        if(this->m_age == p.m_age && this->m_name == p.m_name)
            return true;
        else
            return false;
    }
    /*      重载 ！= 关系运算符     */
    bool operator!=(const Person &p){
        if(this->m_age == p.m_age && this->m_name == p.m_name)
            return false;
        else
            return true;
    }

};

Person::Person(std::string name,int age)
{
    m_name = name;
    m_age = age;
}


void test(){
    Person p1("zyx",18);
    Person p2("xsb",18);

    if(p1==p2){
        std::cout << "p1与p2相等" << std::endl;
    }else{
        std::cout << "p1与p2不相等" << std::endl;
    }

    if(p1!=p2){
        std::cout << "p1与p2不相等" << std::endl;
    }else{
        std::cout << "p1与p2相等" << std::endl;
    }
}

int main(){

    test();

    return 0;
}
