#include <iostream>

#include "chapter6.hpp"             // 双引号 表示 自定义的头文件

using namespace std;

/**
 * 函数名：square
 * 功能： 平方 计算
 * 练习： 6.1
 */
double square(double x)
{
    return x*x;
}

/**
 * 函数名：fact
 * 功能： 阶乘 计算
 * 练习： 6.3 与 6.4
 * 
 */
int fact(int num){

    int result=1;

    for (int i = num; i >0 ; i--)
    {
        /* code */
        result *= i;
    }
    return result;
}

/**
 * 函数名：absolute
 * 功能：  输出 绝对值
 * 习题：练习6.5
 */
int absolute(int num){
    if(num >= 0){
        return num;
    }else{
        return -num;
    }
}

/**
 * 函数名：count_calls()
 * 功能：检验 局部变量和局部静态变量
 * 练习6.6
 */
size_t count_calls(){
    static size_t ctr = 0;      // 局部静态变量
    return ++ctr;
}


int main(){
    // cout << absolute(-5) << endl;

    cout << count_calls() <<endl;

    // for (size_t i = 0; i < 10; i++)
    // {
    //     /* code */
    //     cout << count_calls() <<endl;
    // }
    // return 0;

}