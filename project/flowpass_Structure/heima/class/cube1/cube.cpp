#include"cube.hpp"

using std::cout;
using std::endl;

/**
 * 分别利用 全局属性 和 成员函数，判断两个立方体 体积是否想等
 * 
 *  全局属性： 形参 需要 2个参数：传入 两个 立方体
 *  成员函数： 形参 只需 1个参数：一个是 已知立方体的成员函数，输入 一个未知立方体
 * 
 */

// 利用 全局函数 判断 立方体 体积是否相等
bool is_same(Cube &c1,Cube &c2){                    // 只需要 读取数据，用 引用 可以节省内存

    if(c1.get_volume() == c2.get_volume()){
        return 1;
    }else{
        return 0;
    }

}

int main(){
    // 实例化
    Cube cube1;
    Cube cube2;

    // 设置 长宽高
    cube1.set_lwh(10,20,30);
    cube2.set_lwh(10,20,30);

    // 获取 面积 与 体积
    cout << "面积 应为 " << cube1.get_square() << endl;
    cout << "体积 应为 " << cube1.get_volume() << endl;

    // 使用 全局函数 来判断
    if (is_same(cube1,cube2))
    {
        /* code */
        cout << "两个 立方体 体积 相等 " << endl;
    }else{
        cout << "体积不相等" << endl;
    }


    // 使用 成员函数 来判断
    if (cube1.is_equal(cube2))
    {
        /* code */
        cout << "两个 立方体 体积 相等 " << endl;
    }else{
        cout << "体积不相等" << endl;
    }
    

}