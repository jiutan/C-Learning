#include<iostream>
using namespace std;

/**
 * 习题：2.13
 *
int i = 42;
int main(){
  int i = 100;
  int j = i;
  cout <<  j << endl;
  
  return 0;
}
  */
 /**
  * 习题：2.14
  */
 int main(){
  int i = 100,sum = 0;
  for (int i = 0; i != 10; ++i)     // 这个 i 只在 for 循环内中 使用
  {
    /* code */
    sum += i;                     
  }
  cout << i <<  " " << sum << endl; // 这个 i 是 for循环外 的 i=100
 }