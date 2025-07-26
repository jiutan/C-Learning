#include<iostream>
using namespace std;
/********  
 * 名称：这是一个水仙花数 的 程序
 * 内容：一个数 = 个位的三次方+十位的三次方+百位的三次方 
*/
int main(){

  // 1.先打印所有的三位数字
  int num = 100;
  int units = 0;  // 个位数
  int dec = 0;  // 十位数
  int hundred = 0;  //百位数
  int sum = 0;
  do
  {
    /* code */
    // cout << num << endl;
    // 2.计算十位个位百位
    units = num % 10;
    dec = (num / 10) % 10;
    hundred = num / 100;
    sum = (units*units*units)+(dec*dec*dec)+(hundred*hundred*hundred);  // 不能用^符号
    // 2.从所有数字中，找到水仙花数
    if (num==sum)
    {
    /* code */
      cout << " 水仙花数是： " << num << endl;
    }
    num++;
  } while (num<1000);
  



  return 0;
}