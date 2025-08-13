#include<iostream>

/**
 * 案例描述：
 * - 利用 函数模板 封装一个 排序的函数，可以对 不同数据类型数组 进行排序
 * - 排序规则 从大到小，排序算法 为 选择排序
 * - 分别利用 char数组 和 int数组 进行测试
 */

 // 使用 数组 进行 排序
 template<typename T>
 void mySort(T arr[],int len){

    for(int i=0;i<len ; i++){
        int max = i;  // 假设 最大值 的下标为 i
        for(int j=i+1;j<len;j++){
            if(arr[max] < arr[j]){  // 如果 arr[j] 大于 arr[max]，则 说明 arr[j] 更大
                max = j;
            }
        }
        // 交换 arr[i] 和 arr[max]
        if (max!= i)  // 如果 max 不是 i，说明找到了更大的值
        {
            // 交换 arr[i] 和 arr[max]
            T temp = arr[i];
            arr[i] = arr[max];
            arr[max] = temp;
        }
    }
 }

 // 打印 数组 模板
 template<typename T>
 void printArray(T arr[],int len){

    for (int i = 0; i < len; i++)
    {
        /* code */
        std::cout << arr[i] << " " ;
    }
    std::cout << std::endl;

 }

 int main(){

    // 测试 char数组
    char charArr[] = {'d', 'a', 'c', 'b'};
    int len = sizeof(charArr) / sizeof(charArr[0]);         // 获得 数组长度
    mySort(charArr,len);
    printArray(charArr,len);

    // 测试 int数组
    int intArr[]={1,2,3,4,5,6,7};
    int len1 = sizeof(intArr) / sizeof(intArr[0]);
    mySort(intArr,len1);
    printArray(intArr,len1);

    return 0;
 }