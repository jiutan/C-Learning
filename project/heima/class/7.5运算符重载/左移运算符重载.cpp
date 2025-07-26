#include<iostream>
// using namespace std;
// using std::cout;
// 左移运算符 重载
class Person
{
    // 友元 全局函数
    friend std::ostream &operator<<(std::ostream &out,Person &p);

private:
    /* data */
    int private_num;
public:
    Person(int a);

    int num;
    // 利用 成员函数 重载 左移运算符
    /*      注意：不会 利用 成员函数 重载 << 运算符  
            因为：无法 实现 cout在左侧
            所以：只能 利用 全局函数 重载 << 运算符
    */ 
    // void operator<< (){

    // }
};

Person::Person(int a)
{
    private_num = a;
}

/*      内容：全局函数 重载 左移 运算符  
        本质：operator<<(cout,p)
        简化：cout << p
*/
// cout 为 ostream输出流类 对象，且 只能有一个 使用引用&【输出流 不能 拷贝】
// 返回值 为 cout ，也为 输出流类型 ostream &(使用 引用，唯一)
// 注意：ostream 输出流类 在 std命名空间下
std::ostream &operator<<(std::ostream &out,Person &p){           

    out << "num = " << p.num << " private_num = " << p.private_num;
    return out;
}

void test01(){
    Person p(100);
    p.num = 10;
    
    std::cout << p << " helloworld "  << std::endl;
}

int main(){

    test01();
    return 0;
}

