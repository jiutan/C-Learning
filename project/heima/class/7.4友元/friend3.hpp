#ifndef _FRIEND3_HPP
#define _FRIEND3_HPP
/**
 * 项目：成员函数 做 友元
 */
#include<iostream>
#include<string>

class Building;

class GoodGay
{
private:
    /* data */
public:
    GoodGay(/* args */);
    ~GoodGay();

    Building *building;

    void visit();                   // 想让 visit 成员函数 可以访问 Building 中的 私有成员
    void visit2();                  // 让 visit2 成员函数 不可以访问  Building 中的 私有成员
};

class Building
{
    // 声明 友元 成员函数
    friend void GoodGay::visit();   // 告诉 编译器 Gooday类 下的 成员函数visit 为 友元函数，可以访问 如下的 私有属性

private:
    /* data */
    std::string m_bedroom;
public:
    Building(/* args */);
    ~Building();

    std::string m_livingroom;

};

Building::Building(/* args */)
{
    m_livingroom = "客厅";
    m_bedroom = "卧室";
}

Building::~Building()
{
}


GoodGay::GoodGay(/* args */)
{
    building = new Building;            // 用 指针 维护 在堆区中创建的 对象
}

GoodGay::~GoodGay()
{
}

// 友元 函数
void GoodGay::visit(){

    std::cout << "visit 函数 正在访问：" << building -> m_livingroom << std::endl;

    std::cout << "visit 函数 正在访问：" << building -> m_bedroom << std::endl;

}

void GoodGay::visit2(){

    std::cout << "visit2 函数 正在访问：" << building -> m_livingroom << std::endl;

    // std::cout << "visit2 函数 正在访问：" << building -> m_bedroom << std::endl;     // 不能访问，因为不是 友元

}


#endif