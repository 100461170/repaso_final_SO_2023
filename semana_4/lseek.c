//
// Created by tomas on 23/05/23.
//
# include <stdio.h>
#include <unistd.h>
# include <fcntl.h>

int main(int argc, char *argv[]){
    int file = open("aux", O_RDONLY);
    if (-1 == file){
        printf("error opening file\n");
        return -1;
    }
    char buffer [1000];
    char buffer2 [1000];
    int read_f;
    read_f = read(file, &buffer, 1);
    printf("lo leido es: %s\n", buffer);
    // lseek
    printf("hacer lseek \n");
    int seek = lseek(file, 100, SEEK_END);
    if (-1 == seek){
        printf("lseek error\n");
        return -1;
    }
    read_f = read(file, &buffer2, 1);
    printf("despues de hacer lseek \n");
    printf("lo leido es: %s\n", buffer2);
    close(file);







    return 0;
}