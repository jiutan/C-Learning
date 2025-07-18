#include<iostream>
#include<string>

/**
 * 将 成员属性/数据 设置为 私有
 */
class Person{

private:
    std::string name;
    int age = 18;

public:                 
    // 通过 成员函数 来写入 私有属性
    void set_name(std::string usr_name){
        name = usr_name;
    }
    // 通过 成员函数 来读取 私有属性
    std::string get_name(){
        return name;
    }

    // 设置 年龄：（ 要求 年龄在 0～150岁 之间）    [可以 自己 检测 数据有效性]
    void set_age(int usr_age){
        if(usr_age >150 || usr_age < 0){
             age = usr_age;
        }else{
            std::cout << "年龄输入有误" << std::endl;
        }
    }
};