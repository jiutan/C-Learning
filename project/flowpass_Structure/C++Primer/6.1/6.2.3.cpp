#include<iostream>
#include<string>
#include<cctype>

/**
 * 练习：6.16 改善函数
 */
bool is_empty(std::string &s){

    return s.empty();

}
// 改善:使用 常量引用
bool is_empty1(const std::string &s){
    return s.empty();
}

/**
 * 练习：6.17 编写函数：判断string对象中 是否含有大写字母
 * 返回值：bool
 * 知识点：不改变字符串，用常量 const
 */
bool is_daxie(const std::string &s){
    
    // 使用 范围for循环，来遍历字符串中的字符
    for(auto c : s){
        // std::cout << isupper(c) << std::endl;
        if (isupper(c) != 0)                    // 不为0,则为真
        {
            /* code */
            return 1;
        }
    }
    return 0;
}

/**
 * 练习：6.17 编写函数：把 string对象，全部改成小写形式。
 * 返回值：string
 * 知识点: 当 需要更改字符串时,不用const
 */
std::string daxie_to_xiaoxie(std::string &s){
    
    // 使用 范围for循环 遍历字符串 每一个字符
    for(auto &c : s){                           // 注意:这里 c是引用,只有使用 引用 才能改变字符串中的 字符.
        if (isupper(c)!=0)
        {
            /* code */
            c = tolower(c);             
        }
    }
    return s;
}

/**
 * 练习:6.18 为下面的函数编写 函数声明,根据函数名猜功能
 */
// compare函数,返回布尔值,两个参数都是matrix类的引用


int main(){

    // is_empty("Hello");      // 不是const 无法直接 输入 字符串
    std::string str = "Hello";
   
#if 0   // 练习：6.16 
    std::cout << is_empty(str) << std::endl;
    使用 常量引用，可以直接引入 字符串
    std::cout << is_empty1("Hello") << std::endl;

#elif 0 // 练习:6.17
    // 判断是否 有大写字母
    std::cout << is_daxie(str) << std::endl;
    std::cout << daxie_to_xiaoxie(str) << std::endl;

#elif 1 // 练习:6.18


#endif
}