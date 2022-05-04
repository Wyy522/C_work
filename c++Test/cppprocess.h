//
// Created by wyy on 2022/5/4.
//

#ifndef C__TEST_CPPPROCESS_H
#define C__TEST_CPPPROCESS_H

#include <mysql/mysql.h>

int process(int n, char names[100][100], char values[100][100], char *path);

int doSomething (MYSQL *mysql,int tid,int num1,int num2,char * path);

#endif //C__TEST_CPPPROCESS_H
