#include<iostream>
using namespace std;
/**
 * 这是一个关于 引用 知识点的习题
 */
/**
 * 章节：引用
 * 练习2.16：
 *
int main(){
  int i = 0 ,&r1 = i;
  double d = 0,&r2 = d;       // 将 r2 与 d 绑定
  // r2 = 3.14159;               // 对 r2 赋值，相当于对 d 赋值      
  // r2 = r1 ;                       // 将 r1的值，赋给了 r2
  // i = r2;
  r1 = d;
  cout << "r1 = " << r1 << endl;
  cout << "i = " << i << endl;
  cout << "r2 = " << r2 << endl;
  cout << "d = " << d << endl;
}
*/

/**
 * 章节：引用
 * 练习2.17：
 */
int main(){
  int i,&ri = i;
  i=5;ri = 10;
  cout << i << " " << ri << endl;
}