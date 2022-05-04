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
