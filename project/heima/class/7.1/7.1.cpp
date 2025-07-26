#include<iostream>

/**
 * 设计一个圆类，求圆的周长
 * 圆周长公式：2 * pi * 半径
 * 
 *  */ 
const double pi = 3.14;     // 圆周率

// 设计一个类
class Circle{

public:                 // 访问权限：公共权限（可以在类外调用）    
    // 属性
    int m_r;        // 半径

    // 方法
    double perimeter(){              // 获取周长

        return 2*pi*m_r;
    }             

};


int main(){
    // 创建对象：通过 类 来实例化，创建对象
    Circle cl;
    // 对圆的对象，的 属性 进行赋值
    cl.m_r = 10;

    std::cout << "圆的周长为 " << cl.perimeter() << std::endl;
}


