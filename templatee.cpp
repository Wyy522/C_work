//
// Created by wyy on 2022/4/16.
//

#include <iostream>

using namespace std;

template <class T,int size>
void xxx(T (&t)[size]){
    for(T x:t){
        cout<<x<<endl;
    }
    cout<<size<<endl;
}
int main(){
//    int array[5]={1,2,3,4,5};
//    xxx(array);

int &&b=static_cast<int &&>(0x61);
cout<<b<<endl;
    return  0;
}