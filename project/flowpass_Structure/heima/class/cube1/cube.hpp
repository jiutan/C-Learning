#ifndef _CUBE_H
#define _CUBE_H

#include<iostream>
#include<string>

class Cube{

private:
    double _m_L;             // 长
    double _m_w;             // 宽
    double _m_H;             // 高

public:
    void set_lwh(double length,double width,double high){   // 设置 长宽高
        _m_L = length;
        _m_w = width;
        _m_H = high;
    }

    double get_volume(){                // 求 体积
        return _m_L * _m_w * _m_H;
    }

    double get_square(){                // 求 面积
        return 2*(_m_L * _m_w +_m_L * _m_H + _m_w *_m_H);
    }

    // 使用 成员函数 判断 两个立方体 体积 是否相等
    bool is_equal(Cube &c){                     // 用 已知的 成员函数 与 未知的成员函数 进行比较，所以 只需 传入一个参数

        if(get_square() == c.get_square()){     // 已知的成员函数 get_suqare()【在 类内】 与 未知的 c.get_square() 来判断
            return true;
        }else{
            return false;
        }

    }
};







#endif