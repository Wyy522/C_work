#include <stdio.h>
#include <iostream>
#include <string.h>
void set_teacher(char* id, char *gender);
void set_student(char* num,char *name);
void show_all();

char *ptr=(char *)malloc(100000 * sizeof(char));
char i=0;

//int main() {
//    set_teacher("26","women");
//    set_student("191417","xiaowei");
//    set_student("191103","xiaozhang");
//    show_all();
//    return 0;
//}

void set_teacher(char* id,char *gender){

    char head ='t';
    *(ptr+i++)=head;

    char m=i++;
    char n='0';

    char *c1=id;
    char *c2=gender;
    do
    {
        *(ptr+i++)=*(c1++);
        n++;
    }while(*c1!='\0');
    *(ptr+m)=n;

    m=i++;
    n='0';
    do{

        *(ptr+i++)=*(c2++);
        n++;
    }while(*(c2)!='\0');
    *(ptr+m)=n;
}
void set_student(char* num,char *name){

    char head ='s';
    *(ptr+i++)=head;

    char m=i++;
    char n='0';

    char *c1=num;
    char *c2=name;
    do
    {
        *(ptr+i++)=*(c1++);
        n++;
    }while(*c1!='\0');
    *(ptr+m)=n;

     m=i++;
     n='0';
    do{
        *(ptr+i++)=*(c2++);
        n++;
    }while(*(c2)!='\0');
    *(ptr+m)=n;
}
void show_all() {

    while (*ptr != '\0') {

        if (*ptr == 't') {
            char n='0';
           char s=*(++ptr);
            printf("老师年龄:");
            while((n++!=s)){
                printf("%c", *(++ptr));
            }
            n='0';
            char m=*(++ptr);
            printf("\t老师性别:");
            while((n++!=m)){
                printf("%c", *(++ptr));
            }
        }
        printf("\n");
        if (*ptr == 's') {
            char n='0';
            char s=*(++ptr);
            printf("学生学号:");
            while((n++!=s)){
                printf("%c", *(++ptr));
            }
            n='0';
            char m=*(++ptr);
            printf("\t学生姓名:");
            while((n++!=m)){
                printf("%c", *(++ptr));
            }
        }
        ptr++;
    }
}