#include<iostream>

using namespace std;

// 利用 指针来访问数组
int main(){
    // 创建 数组：arr为数组名，其中 数组名就为数组的首地址
    // 数组的本质 是 地址
    int arr[10]={1,2,3,4,5,6,7,8,9,10};

    // 打印数组元素
    // cout << "第一个元素为：" << arr[0] << endl;

    // 使用指针
    int * ptr = arr;     // arr为数组名，其中 数组名就为数组的首地址

    cout << "利用指针来访问第一个元素："  << *(ptr+1) << endl;

    // 利用指针来 遍历数组
    int * ptr2 = arr;
    // for (auto i : arr)
    // {
    //     /* code */
    //     cout << arr[i] << endl;
    // }
    for (int i = 0; i < 10; i++)
    {
        /* code */
        cout << *ptr2++ << endl;
    }
    

}