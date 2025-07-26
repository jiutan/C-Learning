#ifndef _CLASS_H
#define _CLASS_H

#pragma once        // 防止 头文件 重复包含

#include<iostream>
#include<string>

/**
 * 设计一个学生类，属性有姓名和学号，可以给 姓名和学号 赋值，可以显示学生的姓名和学号
 */
// 声明一个类
class Student{

private:                // 声明 成员数据/属性 
    std::string _name;
    int _num;

public:                 // 声明 成员函数
    
    void set_name(std::string stu_name);
    void set_num(int stu_num);
    
    std::string get_name();
    int get_num();
};

#endif
