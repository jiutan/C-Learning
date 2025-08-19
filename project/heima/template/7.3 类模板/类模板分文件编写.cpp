#include<iostream>
#include<string>
using namespace std;

#include"Person.hpp"


int main(){

    Person<string,int> p("zyx",18);

    p.showPerson();

    return 0;
}