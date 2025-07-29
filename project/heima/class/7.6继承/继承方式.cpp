#include<iostream>

// 设置 父类
class Father
{
private:
    int a;
protected:
    int b;
public:
    int c;
};

// 公共继承 子类
class Public_Son:public Father
{
private:
    
protected:

public:
    void func(){
        c = 10;     // 父类中 公共权限成员 的 继承后 依然是 公共权限
        b = 10;     // 父类中 保护权限成员 的 继承后 依然是 公共权限
        // a = 10;     // 父类中 私有权限成员 的 继承后 无法访问
    }

};

class Protected_Son:protected Father
{
private:
    
public:
    void func(){
        c = 10;     // 父类中 公共权限成员 的 继承后 变为 保护权限，类外访问不到
        b = 10;     // 父类中 保护权限成员 的 继承后 变为 保护权限，类外访问不到
    }

};

class Private_Son:private Father
{
private:
    
public:
    void func(){
        c = 10;     // 父类中 公共权限成员 的 继承后 变为 私有权限，类外访问不到
        b = 10;     // 父类中 保护权限成员 的 继承后 变为 私有权限，类外访问不到
    }

};


int main(){

    Public_Son s1;
    // s1.b = 100;         // b为 保护权限，类外访问不到

    Protected_Son s2;
    // s2.c = 100;          // c 为 保护权限，类外访问不到

    Private_Son s3;
    // s3.c = 100 ;         // c 为 私有权限，类外访问不到
    

    return 0;
}



