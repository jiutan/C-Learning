#include<iostream>

/*      +号 运算符 重载     */

/*  1. 通过 成员函数 重载 + 号  */
class Person
{
public:
    Person(){
        m_A = 0;
        m_B = 0;
    }

    int m_A;
    int m_B;

    // 通过成员函数 重载+号
    // Person operator+(const Person &p){

    //     std::cout << "尝试进行 加法运算" << std::endl;

    //     Person temp;
    //     temp.m_A = this->m_A + p.m_A;       // this 指向 使用该成员函数的 对象
    //     temp.m_B = this->m_B + p.m_B;
    
    //     return temp;                         // 别忘了 返回值 
    // }
};


/*  2. 全局函数 重载 + 号*/
Person operator+(Person &p1,Person &p2){

    Person temp;
    temp.m_A = p1.m_A + p2.m_A;
    temp.m_B = p1.m_B + p2.m_B;

    return temp;
}

/*      函数 重载 的 版本   */
Person operator+(Person &p,int a){

    Person temp;
    temp.m_A = p.m_A + a;

}


void test1(){

    Person p1;
    p1.m_A = 10;
    p1.m_B = 10;
    
    Person p2;
    p2.m_A = 20;
    p2.m_B = 10;

    // 调用 成员函数重载 的 本质：Person p3.operator+(p2);

    // 调用 全局函数重载 的 本质：Person p3 = operator+(p1,p2); 
    Person p3 = p1 + p2;        // 重载后，可用

    std::cout << "p3.m_A = " << p3.m_A << std::endl;
    std::cout << "p3.m_B = " << p3.m_B << std::endl;

    // 运算符 重载 也可以发生 函数重载
    Person p4 = p1 + 300;
    std::cout << "p4.m_A = " << p4.m_A << std::endl;
}

int main(){

    test1();

    return 0;
}