#include<iostream>

/**
 * 练习6.21：编写函数：令其 一个是int类型，一个是int指针。函数比较int的值和指针所值的值，并返回较大的那个
 */
int bigger(const int a,const int *b){

    if( a >= *b){
        return a;
    }else{
        return *b;
    }
}

/**
 * 练习6.22：编写一个函数，令其交换两个int指针
 */
// 方法一：使用 指针的引用（使用引用 能修改 指针变量）
void swap_pointer1(int* &a,int* &b){

    int *temp;
    temp = a;
    a = b;
    b = temp;
}
// 方法二：使用 指针的指针
void swap_pointer2(int* *a,int* *b){
    int *temp;  
    temp = *a;             // 此时 *a 为 a的指针,temp也为指针
    *a = *b;
    *b = temp;              // 此时 *b 为 b的指针
}

int main(int argc,char *argv[]){

#if 0           //练习6.21
    int num1 = 10;
    int i = 20;
    int *num2 = &i;                 // int *num 无法初始化数值，只能使用 &i来过渡

    std::cout << bigger(num1,num2) << std::endl;

#elif 1
    int a = 10;
    int *num1 = &a;
    int b = 20;
    int *num2 = &b;

    // swap_pointer1(num1,num2);       // 实参 需要为 指针

    swap_pointer2(&num1,&num2);     // 实参 需要为 指针的地址/指针的指针

    std::cout << *num1<< " " << *num2 << std::endl;


#endif

}