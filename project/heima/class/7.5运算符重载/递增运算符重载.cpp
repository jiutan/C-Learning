#include<iostream>

// 自定义 整型
class MyInteger
{
    // 设置 友元
    friend std::ostream &operator<<(std::ostream &out,MyInteger &i);

private:
    /* 私有成员 */
    int m_Num;

public:
    MyInteger(){
        m_Num = 0;
    }


/*      重载 ++ 运算符      */
    /** 重载 前置递增
      * 目的：使 m_Num++ 
      * 返回类型：MyInteger&
    */
    // 【前置 返回 引用】。原因：为了 一直对一个数据 进行递增操作
    MyInteger& operator++(){
        // 先进行++运算
        m_Num++;
        // 再 进行返回
        return *this;       // 返回 自身：自身为this，解引用*this为 自身的值。返回值 为：MyInteger& ，把自身作为一个返回
    }
    // 重载 后置递增 【后置 返回 值】原因：temp为临时变量，执行完就 释放掉了，若再返回引用，则非法操作
    MyInteger operator++(int){   // int 代表 占位参数，用于 区分 前置与后置递增。【重点：int！！！】

        // 先 返回 结果（先 记录下 当时的结果）
        MyInteger temp = *this;             // *this 为 自身现在的结果
        // 再 递增
        m_Num++;
        // 最后 将 记录的结果，做为返回
        return temp;
    }
};

// 重载 左移运算符：输出 自定义
std::ostream &operator<<(std::ostream &out,MyInteger &i){

    std::cout << i.m_Num ;  // 私有化

    return out;
}

// void

int main(){

    // 实例化对象
    MyInteger myint;

    std::cout << ++myint << std::endl;
    std::cout << myint << std::endl;

    // std::cout << myint++ << std::endl;
    // std::cout << myint << std::endl;

    // // 若返回的不是引用&,则
    // std::cout << ++(++myint) << std::endl;  // 输出 为 2
    // std::cout << myint << std::endl;        // 输出 则为 1（没有传递给 myint对象）

    return 0;
}

