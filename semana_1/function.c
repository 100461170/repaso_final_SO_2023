//
// Created by tomas on 21/05/23.
//
#include <stdio.h>
#include <stdlib.h>

int sumar(int a, int b){

    return (a + b);
}



int main(int argc, char *argv[]){
    if (3 > argc){
        printf("missing arguments\n");
        return -1;
    }
    int a, b, suma;
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    suma = sumar(a, b);
    printf("la suma da: %d\n", suma);
}



