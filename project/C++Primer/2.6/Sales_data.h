#ifndef SALES_DATA_H
#define SALES_DATA_H

#include<string>

/**
 * 注意：这里的 Sales_data类 还不是一个 抽象数据类型
 *      其允许 类的用户 直接访问它的数据类型
 *      没有 接口
 */


// 在 头文件中 定义 类对象
struct Sales_data
{
    /* data */
    std::string BookName;           // 书的 ISBN号码
    unsigned sale_num = 0;          // 书的 销售数量
    double revenue = 0.0;           // 书的 销售输入
}book1,book2;                       // 定义了 Sales_data类 的对象变量
//或者用 Sales_data book1,book2;



#endif