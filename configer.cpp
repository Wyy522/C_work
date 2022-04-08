//
// Created by wyy on 2022/4/8.
//

#include <stdio.h>
#include <string.h>
#include "my_source.h"

char o[10];
char p[10];
void write_txt(char b[]){
    FILE *file = fopen("/home/wyy/CLionProjects/FristTest/my_source.txt", "w");
    if(file == NULL)
    {
        printf("open error!\n");
    }
    int i;
    for(i = 0; i < strlen(b); i++)
    {
        fputc(b[i], file);
    }
    fputc('\n', file);
    fclose(file);
}
char read_txt()
{
    FILE *file = fopen("/home/wyy/CLionProjects/FristTest/my_source.txt", "r");
    if(file == NULL)
    {
        printf("open error!\n");
        return 0;
    }
    char c;
    int i=0,j=0,x=0;
    while((c = fgetc(file)) != EOF)
    {

        if(c=='='){i=1;continue;}
        if(i==0)o[j++]=c;
        if(i==1)p[x++]=c;
    }
    fclose(file);
    return 0;
}
void write_h(){
    FILE *file = fopen("/home/wyy/CLionProjects/FristTest/my_source.h", "w");
    if(file == NULL)
    {
        printf("open error!\n");
    }
    int i;
    char c[]={"#define"};
    for(i = 0; i < strlen(c); i++)
    {
        fputc(c[i], file);
    }
    fputc(' ', file);
    for(i = 0; i < strlen(o); i++)
    {
        fputc(o[i], file);
    }
    fputc(' ', file);
    for(i = 0; i < strlen(p); i++)
    {
        fputc(p[i], file);
    }
    fputc('\n', file);
    fclose(file);
}



int main()
{
//    char a[]="xxx=1";
//    write_txt(a);
    read_txt();
    write_h();

#if xxx == 0
    printf("xxx是0");
#elif xxx == 1
    printf("xxx啥也不是");
#endif
    return 0;
}

