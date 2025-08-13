#include<iostream>
using namespace std;

//实现 交换 两个整型 的函数
void swapInt(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

//实现 交换 两个浮点型 的函数
void swapDouble(double &a, double &b){
    double temp = a;
    a = b;
    b = temp;
}

/*          使用 函数模板        */
// 类型不同，但是 编程逻辑相同
template<typename T>      // 声明一个 模板，告诉 编译器 后面代码中 T 是一个 通用的数据类型，T 可以理解为 占位符(不要报错)

// 定义一个 通用的 交换函数
void mySwap(T &a,T &b){

    T temp = a;
    a = b;
    b = temp;   
}

int main(){

    int a = 10;
    int b = 20;

    // 使用 函数模板 进行 交换数据
    // 有 两种方式 来 使用 函数模板
    // 1. 自动类型推导
    mySwap(a,b);                        // 编译器会自动推导出 T 是 int 类型

    cout << "a = " << a << ", b = " << b << endl;

    // 2. 显式指定类型: 函数名<模板的参数类型>(实参)
    mySwap<int>(a,b);                   // 显式指定 T 是 int 类型

    return 0;
}