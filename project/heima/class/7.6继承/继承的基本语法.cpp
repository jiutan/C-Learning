#include<iostream>
#include<string>
/*      继承的好处：减少重复的代码      */
// 继承 实现 页面【为 所有页面的 共同内容】
class BasePage
{
private:
    /* data */
public:
    // 头部内容
    void header(){
        std::cout << "首页、公开课、登陆、注册...（公共头部）" << std::endl;
    }
    // 底部内容
    void footer(){
        std::cout << "帮助中心、交流合作、站内地图...（公共底部）" << std::endl;
    }
    // 公共分类列表
    void left(){
        std::cout << "Java、Python、C++...（公共分类列表）" << std::endl;
    }

};

// 实现 Java页面(自己的个性)
class Java:public BasePage{

public:
    // 自己个性内容
    void content(){

        std::cout << "Java学科的视频" << std::endl;

    }

};

// 实现 Python页面(自己的个性)
class Python:public BasePage{

public:
    // 自己个性内容
    void content(){

        std::cout << "Python学科的视频" << std::endl;

    }

};

// 实现 Cpp页面(自己的个性)
class CPP:public BasePage{

public:
    // 自己个性内容
    void content(){

        std::cout << "C++学科的视频" << std::endl;

    }

};

int main(){

    Java java;
    Python py;
    CPP cpp;

    java.header();
    java.footer();
    java.left();
    java.content();

    py.header();
    py.footer();
    py.left();
    py.content();

    return 0;
}

