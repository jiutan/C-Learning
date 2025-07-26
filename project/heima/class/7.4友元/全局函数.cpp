#include<iostream>
#include<string>

/*      建筑物 类    */
class Building
{
    /*      声明 全局函数 并且 为 友元 */
    friend void GoodFriend(Building *build);        // GoodFriend函数 为 Building中的 尤元，可以访问 类中 私有属性


private:
    std::string m_SittingRoom;      // 客厅

public:
    std::string m_BedRoom;          // 卧室

    // 构造函数
    Building(){
        m_SittingRoom = "living room";

        m_BedRoom = "bed room";
    }

};

/*      定义 全局函数    */
void GoodFriend(Building *build){            // 传入的 形参 为 Building类（引用形式 或者 指针形式） 为 build 本身

    // 因为 build为指针，所以使用->取成员
    std::cout << "goodguy global function has visit : "  << build -> m_BedRoom << std::endl;      

    // 因为 友元 所以 可以访问 private 成员
    std::cout << "goodguy global function has visit : " << build ->m_SittingRoom << std::endl;

}

void test01(){

    Building building;          // 实例化
    GoodFriend(&building);      // 形参 为 指针，实参 则 需要 传入 地址

}

int main(){

    test01();


    return 0;
}
