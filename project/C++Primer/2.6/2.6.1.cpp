#include<iostream>
#include"Sales_data.h"          // 自己编写的头文件，用""引用

using std::cout;
using std::cin;

// 编写一个类
/**
 * 练习2.39:看下 分好；的作用
 */
struct Foo
{
    /* data */
};


int main(int argc,char* argv[]){        // argv为字符串数组

    // Sales_data book1,book2;

    double price;           // 书的价格

    /*           采用 点操作符，可以直接对 类对象内的成员 进行读取或写入                                */
    // 读入 第一本书的 ISBN号；销售数量；单价
    cin >> book1.BookName >> book1.sale_num >> price;
    
    // 计算 第一本书的收入  
    book1.revenue = book1.sale_num * price;

    cin >> book2.BookName >> book2.sale_num >> price;
    book2.revenue = book2.sale_num * price;

    // // 输出两个对象的和
    // if (book1.BookName == book2.BookName)
    // {
    //     /* code */
    //     unsigned
    // }
    

}
