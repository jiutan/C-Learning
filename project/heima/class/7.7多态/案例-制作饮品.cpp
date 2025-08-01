#include<iostream>

/*      制作饮品        
*   大致流程：煮水 -> 冲泡 -> 倒入杯中 -> 加入辅料
*   利用 多态 实现 ：提供抽象 制作 饮品 基类，提供 子类 制作 咖啡和茶叶
*/
class AbstractDrink
{
private:
    /* data */
public:

    // 提供 纯虚函数
    virtual void BoilWater() = 0;       // 煮水

    virtual void Brew() = 0;            // 冲泡

    virtual void PourCup() = 0;         // 倒入杯中

    virtual void PutThing() = 0;        // 加入辅料

    // 制作饮品
    void MakeDrink(){           // 若 调用 该函数，则 走 这 四个步骤

        BoilWater();
        Brew();
        PourCup();
        PutThing();

    }
    
};

// 咖啡类
class Coffee:public AbstractDrink
{
private:
    /* data */
public:
    /*      重写 父类的纯虚函数     */
    virtual void BoilWater(){
        std::cout << "煮 农夫山泉 " << std::endl;
    }

    virtual void Brew(){
        std::cout << "冲泡 咖啡 " << std::endl;
    }            

    virtual void PourCup(){
        std::cout << "倒入 杯中 " << std::endl;
    }         

    virtual void PutThing(){
        std::cout << "加入 糖 和 牛奶 " << std::endl;
    }       
};

// 茶叶类
class Tea:public AbstractDrink
{
private:
    /* data */
public:
    /*      重写 父类的纯虚函数     */
    virtual void BoilWater(){
        std::cout << "煮 山泉水 " << std::endl;
    }

    virtual void Brew(){
        std::cout << "冲泡 龙井 " << std::endl;
    }            

    virtual void PourCup(){
        std::cout << "倒入 玻璃杯 中" << std::endl;
    }         

    virtual void PutThing(){
        std::cout << "什么 都 不加" << std::endl;
    }       
};

/*          具体 实现（使用 指针）       */
// 创造 制作饮品 的 函数。（需 传入 抽象类 指针/引用）
void doWork(AbstractDrink* abd){                // 接收的实参 需 为 指针
    abd -> MakeDrink();
    delete abd;                 // 释放内存
}

int main(){
    /*      常规 写法       */
    // 制作咖啡
    // Coffee c;
    // doWork(&c);             // 传入 子类 入口地址        

    /*      开辟 堆区 写法      */
    // 制作 茶
    doWork(new Tea);        // new 一个类 == 在 堆区 开辟 子类 的 内存空间，并 返回 对象指针


    return 0;
}
