#include<iostream>
#include<string>

/**
 * 访问权限：（三种）
 *      公共权限：public        成员 在类内可以访问，类外可以访问
 *      保护权限：protected     成员 在类内可以访问，类外不可以访问 子类可以访问父类中保护权限的内容
 *      私有权限：private       成员 在类内可以访问，类外不可以访问 子类不可访问父类中私有权限的内容
 */
class Person{

private:        // 私有权限 的成员，子类无法访问
    int card_password;        // 银行卡密码

protected:      // 保护权限 的成员，子类可以访问
    std::string car;        // 汽车


public:         // 公共权限 的成员，大家都可访问
    std::string name;       // 姓名
    void func(){
        // 在 类内 可以直接调用 私有权限和保护权限的内容
        name = "zyx";

        car = "福特";

        card_password = 123456;
    }
};

int main(int argc,char *argv[]){

    // 实例化 对象
    Person s1;

    // 调用类中的成员

}