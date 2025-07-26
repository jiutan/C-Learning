#include<iostream>
#include<string>

// 函数调用运算符 重载 / 仿函数

// 打印 输出类
class MyPrint
{
private:
    /* data */
public:
    MyPrint(/* args */);
    ~MyPrint();

    /*      重载 函数调用运算符     */
    void operator()(std::string test){

        std::cout << test << std::endl;

    }
};

MyPrint::MyPrint(/* args */)
{
}

MyPrint::~MyPrint()
{
}

// 加法类
class MyAdd
{
private:
    /* data */
public:
    MyAdd(/* args */);
    ~MyAdd();

    int operator()(int num1,int num2){
        return num1+num2;
    }
};

MyAdd::MyAdd(/* args */)
{
}

MyAdd::~MyAdd()
{
}


void test(){
    MyPrint myprint;

    myprint("helloworld");      // 由于 使用起来 非常像 函数调用，因此称为 仿函数
}

void test02(){
    MyAdd m1;
    
    // std::cout << m1(10,20) << std::endl;

    // 匿名函数对象
    std::cout << MyAdd()(10,20) << std::endl;           // 创建匿名对象：类型()
}


int main(){

    test();
    test02();

    return 0;
}