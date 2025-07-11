#include<iostream>
using namespace std;

/**
 * 题目:编写一个函数,使用指针形参 交换两个整数的值
 */

void swap(int *ptr1,int *ptr2){
    int a=0;
    a = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = a;
}
int main(){
    int num1 = 10;
    int num2 = 20;
    swap(num1,num2);

    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
}