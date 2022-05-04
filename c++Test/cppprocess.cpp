//
// Created by wyy on 2022/5/3.
//

#include <mysql/mysql.h>
#include <thread>
#include <stdio.h>
#include <string.h>
#include <iostream>

// 每行最大长度
using namespace std;

MYSQL mysql;
MYSQL_RES *res;
MYSQL_ROW row;

int doSomething (int tid, int num1, int num2, char * path);
void output_mysql(char * buf);

int process(int n,char names[100][100], char values[100][100],char * path){

    mysql_init(&mysql);
    if (!mysql_real_connect(&mysql, values[0], values[1], values[2], values[3], values[4][0], NULL, 0)) {
        printf("Error connecting to database: %s\n", mysql_error(&mysql));
        return 0;
    } else
        printf("Connected mysql successfully!\n");

    for (int i = 1; i <=n; ++i) {
        //int i=1;
        printf("线程%d已开启\n",i);
        thread t(doSomething,i,(i-1)*100,i*(100),path);
        t.detach();
    }
    return 0;
}
int doSomething (int tid,int num1,int num2,char * path){
    int t;
    FILE *fp;

    int line_num = 0; // 文件行数
    int line_len = 0; // 文件每行的长度

    fp = fopen(path, "r");
    if (fp==NULL) {
        printf("open %s failed.\n", path);
        return -1;
    }
    fseek(fp, num1, num2);


    char buf[30] = {0};
    while(fgets(buf,30, fp) != NULL)
    {
        printf("%s", buf);
        output_mysql(buf);
    }
   // mysql_close(&mysql);
    fclose(fp);
    return line_num;
}
void output_mysql(char * buf) {
    int ret = mysql_query(&mysql, buf);
    if (ret != 0) {
        printf("error:%s\n", mysql_error(&mysql));
        getchar();
        exit(1);
    }
}

















//    char buf[1000][50] = {0}; // 行数据缓存
//    for (int i = 0; i < num2-num1; ++i) {
//        for (int j = 0; j < 50; ++j) {
//            char c = fgetc(fp);
//            if(c=='\n')
//                continue;
//            else
//            buf[i][j] = c;
//        }
//        cout<<buf[i]<<endl;
//        output_mysql(buf[i]);
//    }





//    if (mysql_query(&mysql, buf)) {    //如果查询失败
//        printf("\nmysql_query error!\n");
//    } else {
//
//        printf("mysql_query ok\n");
//        //获得结果集
//        res = mysql_store_result(&mysql);
//        //如果为空，继续
//        if (res == NULL) {
//            printf("res null\n");
//        }
//        //读取结果
//        if (mysql_num_rows(res)) {  //有记录的情况,只有有记录取数据才有意义
//            //循环获取下一行
//            while ((row = mysql_fetch_row(res))) {
//                //取出结果集中记录
//                for (t = 0; t < mysql_num_fields(res); t++) {
//                    printf("%s ", row[t]);
//                }
//                printf("\n");
//            }
//        } else {
//            printf("\nnull infomation!\n");
//        }
//}