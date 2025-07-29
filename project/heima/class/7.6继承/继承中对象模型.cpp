#include<iostream>

// 继承中 的 对象模型
class Father
{
private:
    int a;
protected:
    int b;
public:
    int c;
};

class Son:public Father
{
public:
    int d;
};

int main(){

    // 查看 子类 中的 内存大小： 4*4 = 16
    std::cout << "size of Son = " << sizeof(Son) << std::endl;      // 继承了 4个 属性

    return 0;
}

