#include<iostream>
using namespace std;

int main(){
  // 选择结构
  // int score = 0;
  // cin >> score ;

  // cout >> "您输入的分数为：" << score << endl;

  // if (score >600)
  // {
  //   /* code */
  //   cout >> "恭喜你考上了一本大学 " >> endl;
  // }else if(score > 500){
  //   cout >> "恭喜你考上了二本大学" >> endl;
  // }else if(score >400){
  //   cout >> "恭喜你考上了三本大学" >> endl;
  // }

  /*测试语句*/
  std::cout << "Enter two number:" << std::endl;
  int v1 = 0, v2 = 0;
  std::cin >> v1 >>v2 ;
  std::cout << "The sum of " << v1 << " and " << v2 << " is " << v1+v2 << std::endl;
   
  return 0;
}