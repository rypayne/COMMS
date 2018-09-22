#include "cdevlog.h"
/*
void creat_file_(char *name){
    
    char path[strlen(name)+3];
    sprintf(path, "../%s", name);

    FILE *fp;
    fp = fopen(path, "w");
    fclose(fp);

    return;
}*/

void creat_file(){
    FILE *fp;
    fp = fopen(FILE_PATH, "w");
    fclose(fp);

    return;
}

void print_file(char *message){
    FILE *fp;
    fp = fopen(FILE_PATH, "w+");
    fprintf(fp, "message");
    fclose(fp);

    return;
}

void data_file(char *data){
    return;
}