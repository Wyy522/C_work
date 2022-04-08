//
// Created by wyy on 2022/4/8.
//
#include <stdio.h>
#define CONTIANOF(tmp,tpye,node) (tpye *)((char*)tmp-(char*)(&((tpye *)0)->node))

struct list{
    struct  list *next;
};

struct obj{
    int id;
    list node;
};

//int main(){
//    struct list head;
//
//    struct  obj obj_1 ;
//    obj_1.id=1;
//    struct  obj obj_2 ;
//    obj_2.id=2;
//
//    head.next=&obj_1.node;
//    obj_1.node.next=&obj_2.node;
//    obj_2.node.next=0;
//
//    struct list *tmp;
//    tmp=head.next;
//    while(tmp!= nullptr){
//        //struct obj *n=CONTIANOF(tmp,struct obj,node);
//        struct obj *n=(struct obj *)((char *)((struct obj *)tmp)-(char *)(&((struct obj *)0)->node));
//        printf("id=%d\n",n->id);
//        tmp=tmp->next;
//    }
//
//    return  0;
//}
