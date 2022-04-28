//
// Created by wyy on 2022/4/28.
//
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sys/wait.h>

using namespace std;
int execve1()
{
    char *first=(char *)"bash";
    char *secnd=(char *)"/opt";

    char *args[] = {first,secnd, NULL};

    if(execve ("/bin/ls", args, NULL) == -1) {
        perror ("execve");
        exit(EXIT_FAILURE);
    }
    return 0;
}
int execve3()
{
    char *first=(char *)"bash";
    char *secnd=(char *)"/opt";

    char *args[] = {first,secnd, NULL};

    if(execve ("/bin/exit", args, NULL) == -1) {
        perror ("execve");
        exit(EXIT_FAILURE);
    }
    return 0;
}

//int execve2(){
//    system("echo a=1");
//    setenv("a","99",1);
//    putenv("USER=test");
//    return 0;
//}

int main() {

    string str;
    pid_t pid,pr;
    getline(cin,str);
        if(str=="ls"){
            pid =fork();
            if(pid==0){
                sleep(3);
                printf("子进程输出\n");
                execve1();
            } else{

                printf("父进程等待\n");
                wait(NULL);
                printf("父进程结束\n");
            }
        }
        if(str=="ls&"){
            pid =fork();
            if(pid==0){
                sleep(10);
                printf("子进程输出\n");
                execve1();
            } else{

                printf("父进程等待\n");
                pr=waitpid(pid, NULL, WNOHANG);
                printf("父进程结束\n");
            }
        }
    if(str=="exit"){
        execve3();
//            printf("父进程等待\n");
//            pr=waitpid(pid, NULL, WNOHANG);
//            printf("父进程结束\n");

    }

    //execve1();
    return 0;
}
