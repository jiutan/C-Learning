#include<iostream>

using namespace std;

/**
 * 题目：6.11 编写并验证reset函数，使其作用于 引用类型的参考
 * 
 */
void reset(int &num){
    num = 0;
}

/**
 * 题目：6.12 使用 引用而非指针 来交换证书的值
 * 
 */
void swap1(int &num1,int &num2){
    int temp=0;
    temp = num1;
    num1 = num2;
    num2 = temp;
}

int main(){

    int a = 10;

    // 题目6.11
    reset(a);
    cout << a << endl;

    // 题目6.12
    int b = 20;
    int c = 10;
    swap1(b,c);
    cout << b << c << endl;

    // 题目6.13
    // void f(T):无法更改 T的内容，且不返回任何值
    // void f(&T): 不返回任何值，但是 会改变外部传入的变量

    // 题目6.14
    // 形参 应该是引用的例子： swap1
    // 形参 不应该是引用的例子： 单纯计算值，不需要更改实参

    // 题目6.15
    

    return 0;
}
