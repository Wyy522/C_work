
#include "read_properties.h"
#include <stdio.h>
#include "utils.h"

void read_properties(char *pathname, char names[100][100], char values[100][100]) {

    FILE *file;
    char line[100];
    int i = 0;

    file = fopen(pathname, "r");
    while (fgets(line, 100, file)) {
        //printf("%s", line);                             //just for test, delete it later.
        parseline(line, names[i], values[i]);
        i++;
    }
    fclose(file);
}