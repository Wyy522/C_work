
/*
./myetl /home/wyy/CLionProjects/c++Test/MyCsv.csv /home/wyy/CLionProjects/c++Test/sqlconf.properties 10
0                                          1                              2
*/

#include "read_properties.h"
#include "cppprocess.h"
#include <stdlib.h>


int main(int argc,char * args[]) {
    char names[100][100], values[100][100];
    char* properties_path=args[2];
    char* csv_path=args[1];
    int n= atoi(args[3]);
    read_properties(properties_path, names, values);
    process(n,names,values,csv_path);
    return 1;
}