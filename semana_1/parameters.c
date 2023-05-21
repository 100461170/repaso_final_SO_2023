//
// Created by tomas on 21/05/23.
//
#include <stdio.h>

int main(int argc, char *argv[]){

    printf("the number of parameters is: %d\n", argc);

    for (int i=0; i < argc; i++){
        printf("The %d parameter is %s\n", i, argv[i]);
    }

    return 0;
}