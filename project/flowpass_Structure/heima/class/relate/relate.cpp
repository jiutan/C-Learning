#include"relate.hpp"
#include<iostream>

using std::cout;
using std::endl;

// 判断 点 和 圆 的关系
void is_inside(Circle &c,Point &p){

    double distance;        // 存储 距离
    // c.get_center().get_x() 因为 get_center()为Point类，可继续使用 成员函数
    distance = (c.get_center().get_x() - p.get_x())*(c.get_center().get_x() - p.get_x())        // 获取 圆心 和 点 的 x轴坐标
                + (c.get_center().get_y() - p.get_y())*(c.get_center().get_y() - p.get_y());

    // 计算半径的平方
    double circle_r = c.get_radius();

    // 判断关系
    if(circle_r == distance){
        cout << "点在 圆上" << endl;
    }else if (circle_r > distance)
    {
        /* code */
        cout << "点在 圆外" << endl;
    }else{
        cout << "点在 园内" << endl;
    }
    


}