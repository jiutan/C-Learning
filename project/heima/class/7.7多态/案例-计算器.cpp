#include<iostream>
#include<string> 
using namespace std;

/*      利用 普通写法 和 多态技术 实现 计算器       */

// 普通写法
class Calculator
{
private:
    /* data */
public:

    int getResult(string oper){                 // 形参 为 操作符（string类）

        if (oper == "+")
        {
            return m_Num1 + m_Num2;
        }else if(oper == "-"){
            return m_Num1 - m_Num2;
        }else if (oper == "*")
        {
            return m_Num1 * m_Num2;
        }
        /*      如果 想 扩展新的功能，需要 修改源码     */
        // 在 真实开发 中，提倡 开闭原则
        // 开闭原则：对 扩展 进行 开放 ， 对 修改 进行 关闭  【尽量 不要 修改 源码】
    }

    int m_Num1;     // 操作数1
    int m_Num2;     // 操作数2

};

// 利用 多态 实现
// 1. 先实现 计算器 的 抽象类 【什么 功能 都不写，把 功能抽象出来】
class AbstractCalculator
{
private:
    /* data */
public:
    // 写 成员属性
    int m_num1;    
    int m_num2;

    // 将 功能 成员函数 写成 虚函数
    virtual int getResult(){            // 抽象类 必须是 虚函数

        // 注意： 这里 什么功能 都不写
    
        return 0;
    }
};

// 2. 将 各个计算 封装成 单独的类
class AddCalculator:public AbstractCalculator   // 加法
{
private:
    /* data */
public:
    
    // 实现 加法 功能
    int getResult(){
        return m_num1 + m_num2;
    }
};

class SubstractCalculator:public AbstractCalculator    // 减法
{
private:
    /* data */
public:
    int getResult(){
        return m_num1 - m_num2;
    }
};

class MultiCalculator:public AbstractCalculator         // 乘法
{
private:
    /* data */
public:
    int getResult(){
        return m_num1 * m_num2;
    }
};

// 普通 使用
void test01(){
    // 创建 计算器对象
    Calculator c;

    c.m_Num1 = 10;
    c.m_Num2 = 20;

    cout << c.getResult("+") << endl;
}

/*      多态 使用 条件      */
// 父类 指针/引用 指向 子类 对象
void test02(){

    // 1. 创建一个 父类 指针 对象
    AbstractCalculator *abc;        

    // 使用 加法运算
    abc = new AddCalculator;        // 在 堆区 开辟了 一个 加法子类对象 的 指针地址，并用 父类的指针 去 指向 堆区中的内存：发生多态
    abc -> m_num1 = 30;
    abc -> m_num2 = 10;
    cout << abc -> getResult() << endl;                 // 进行 加法运算
    delete abc;                                         // 在堆区创建， 用完后 需 销毁堆区内存。（但 父类 指针还在）

    // 使用 减法运算
    abc = new SubstractCalculator;
    abc -> m_num1 = 30;                                 // 注意：delete销毁后，成员属性 就 清0了
    abc -> m_num2 = 20;
    cout << abc -> getResult() << endl;
    delete abc;                                         // 每次 使用完 记得 销毁 堆区内存

    // 使用 乘法运算
    abc = new MultiCalculator;
    abc -> m_num1 = 30;                                 // 注意：delete销毁后，成员属性 就 清0了
    abc -> m_num2 = 10;
    cout << abc -> getResult() << endl;
    delete abc;
}

int main(){

    // test01();

    test02();

    return 0;
}
