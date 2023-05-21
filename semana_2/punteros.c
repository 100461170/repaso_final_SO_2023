//
// Created by tomas on 21/05/23.
//
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int *ptr1, *ptr2;
    char string[23] = "Carlos";
    ptr1 = malloc(1*sizeof(int));
    ptr2 = malloc(10 * sizeof(int ));
    int hola = 45;
    int chao = 46;
    *ptr1 = hola;
    *ptr2 = chao;
    printf("la direccion del primer puntero es: %ld y su valor es: %d\n", ptr1, *ptr1);
    printf("la direccion del segundo puntero es: %ld y su valor es: %d\n", ptr2, *ptr2);
    printf("la dirrecion de la cadena es: %ld\n", &string);
    free(ptr1);
    free(ptr2);





    return 0;
}