#include"class.h"

/**
 *  定义 类的方法
 *  使用 this -> 属性 来 给private属性 赋值
 */
/**
 * 设计一个学生类，属性有姓名和学号，可以给 姓名和学号 赋值，可以显示学生的姓名和学号
 */
void Student::set_name(std::string stu_name){
    _name = stu_name;                     
}

void Student::set_num(int stu_num){
    _num = stu_num;
}

std::string Student::get_name(){
    return _name;
}

int Student::get_num(){
    return _num;
}

// 主函数
int main(int argc,char **argv){

    // 实例化对象
    Student stu1;

    stu1.set_name("zyx");
    stu1.set_num(39);

    std::cout << "姓名： " << stu1.get_name() << "，学号：  " << stu1.get_num() << std::endl;

}