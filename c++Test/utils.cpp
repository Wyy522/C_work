
#include <cstring>
#include <cstdio>

void parseline(char *line, char *name, char *value){

    int length = 0, equal = 1; //equal will record the location of the '='
    char *begin;

    length = strlen(line);

    for(begin = line; *begin != '=' && equal <= length; begin ++){

        equal++;
    }

    strncpy(name, line, equal - 1);
    line+=equal;
    strncpy(value, line, length - equal-1);


}