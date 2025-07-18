#ifndef _RELATE_HPP
#define _RELATE_HPP

#pragma once        // 防止 头文件 重复包含
#include<iostream>
/**
 * 内容：设计一个 点类
 */
class Point{

private:
    double _x;
    double _y;

public:
    void set_xy(double p_x,double p_y){
        _x = p_x;
        _y = p_y;
    }
    double get_x(){
        return _x;
    }
    double get_y(){
        return _y;
    }

};

/**
 * 内容：设计一个 圆形类
 * 
 */
class Circle{

private:
    double _radius;                 // 半径的大小
    Point _center;                  // 原点 位置（x，y）

public:
    void set_radius(double radius){
        _radius = radius;
    }

    void set_center(Point center)                    // 设置 圆心
    {
        _center = center;
    }

    double get_radius(){
        return _radius;
    }
    // 获取 圆心 【在类中 可以让 另一个类 作为 本类的成员】
    Point get_center(){                         // 返回的 是一个 Point类
        return _center;
    }

};






#endif