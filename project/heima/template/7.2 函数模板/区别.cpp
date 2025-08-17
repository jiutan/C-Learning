#include<iostream>

/**
 *  1. 普通函数调用时，可以发生 **自动类型转换（隐式类型转换）**
    2. 函数模板 调用时，如果利用 自动类型 推导，不会发生 隐式类型转换
    3. 如果利用 显示指定类型的方式，可以发生 隐式类型转换。
 */

// 普通函数
int Add(int a, int b) {
    return a + b;
}

// 




void test(){
    int a = 10;
    int b = 20;

    std::cout << Add(a,b) << std::endl;        

    char c = 'a';
    // 将 字符型 A 转化成 ASCII 码为 97，进行 计算
    std::cout << Add(a,c) << std::endl;       // 正常 调用，发生了 自动类型转换（隐式类型转换）
}

// 函数模板
template<typename T>
T Add2(T a,T b){
    return a + b;
}

void test2(){
    int a = 10;
    int b = 20;

    // 第一种 调用方式： 自动类型推导
    std::cout << Add2(a,b) << std::endl;

    char c = 'A';
    // std::cout << Add2(a,c) << std::endl;        // 调用失败。调用 函数模板 不会发生 隐形类型推导

    // 第二种 调用方式： 显式 指定类型
    std::cout << Add2<int>(a,c) << std::endl;   // 正常调用，发生了 隐式类型转换
}

int main(){
    test2();
    return 0;
}