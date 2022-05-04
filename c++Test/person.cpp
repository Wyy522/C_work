//
// Created by andilyliao on 2022/4/9.
//

#include"person.h"
#include<iostream>
using namespace std;
int person::x=0;
person::person(int id) :id(id){
}
void person::dis() {
    cout<<this->id<<endl;
}
void person::yyy() {
    cout<<"yyy"<<endl;
}