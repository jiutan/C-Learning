#include<iostream>
using namespace std;
/**
 *  工程 ： 学习 拷贝构造函数 相关
 */
class Person
{
private:
    /* data */

public:
    int *m_height;          // 因为 new int() 返回的是 指针类型，所以 需要创建一个指针 来接收数据

    Person(int height){               // 默认构造函数
        cout << " 这是 默认构造函数 " << endl;
        m_height = new int(height);         // 堆区 重新 开辟存放 height
    }

    // 其中，&p 应该为 p的引用 ，用来复制一个 p,且为 常量
    Person(const Person &p){               // 拷贝 构造函数

        cout << " 这是 拷贝构造函数 " << endl;
        // m_height = p.m_height;
        // 在 堆区开辟 新的空间 存放 m_height
        m_height = new int(*p.m_height);    // ()中，应该为 数据，但是 m_height 为 地址，所以需要 解引用               

    }

    /**     析构代码         */
    ~Person(){
        // 析构代码，将 堆区 开辟数据 做释放操作
        if (m_height != NULL)                   // 判断 指针 是否为 空指针
        {
            /* code */
            delete m_height;        // 释放 内存
            m_height = NULL;
        }
        cout << "Person 的 析构函数 调用" << endl;
    }


};

int main(){

    // 使用 默认构造函数 来 创建对象
    Person p1(180);
    cout << " p1 的 身高为 " << *p1.m_height << endl;

    // 使用 拷贝构造函数 来 创建对象
    Person p2(p1);
    cout << " p2 的 身高为 " << *p2.m_height << endl;

}

