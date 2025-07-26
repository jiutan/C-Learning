#ifndef _FRIEND2_HPP
#define _FRIEND2_HPP

/**
 * 项目：类 做 友元
 */

#include<iostream>
#include<string>

class Building
{
    /*   GoodGay 类 是 友元，可以 访问 Building中的 Private类 成员   */
    friend class GoodGay;

private:
    /* data */
    std::string m_bedroom;

public:
    Building(/* args */);
    ~Building();

    std::string m_livingroom;
};

/*   类外 写 构造函数 与 析构函数   */
Building::Building(/* args */)
{
    m_livingroom = "living room";
    m_bedroom = "bed room";
}

Building::~Building()
{
}



class GoodGay
{
private:
    /* data */
public:
    GoodGay();
    ~GoodGay();

    void visit();                   //  参观函数 访问 Building中的 属性

    Building *building;             // 创建 指针，用于 指向 堆区中的 对象
};
GoodGay::GoodGay(){

    // 创建一个 building对象
    // 在 堆区 创建一个Building对象（返回的是 指针），并且 让 Building* building指针 指向 堆区新创建的 对象
    building = new Building;           

}
GoodGay::~GoodGay(){

}

// 类外 声明 成员函数
void GoodGay::visit(){ 

    std::cout << "GoodGay类 正在访问：" << building -> m_livingroom << std::endl;

    std::cout << "GoodGay类 正在访问：" << building -> m_bedroom << std::endl;

}


















#endif