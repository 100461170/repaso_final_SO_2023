//
// Created by tomas on 21/05/23.
//
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    int vector[10];
    for (int i = 0; i < 10; i++){
        vector[i] = 10;
    }
    char string[12];
    char copia[] = "messirve";
    strcpy(string, copia);
    printf("el tamanio del vector es: %lu\n", sizeof(vector));
    printf("el tamanio de la cadena es: %lu y su longitud es %lu\n",
           sizeof(string), strlen(string));
    printf("el tamanio de la cadena es: %lu y su longitud es %lu\n",
           sizeof(copia), strlen(copia));



    return 0;
}