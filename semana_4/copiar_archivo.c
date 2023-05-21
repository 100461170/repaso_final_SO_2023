//
// Created by tomas on 21/05/23.
//
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int copiar(char origen[1000], char destino[1000]){
    // abrir archivo origen
    int entrada = open(origen, O_RDONLY);
    if (-1 == entrada){
        printf("error al abrir el fichero\n");
        return -1;
    }
    // crear archivo salida
    int salida = creat(destino, 438);
    if (-1 == salida){
        printf("error al crear fichero salida\n");
        return -1;
    }
    // variables para leer
    char buffer[10];
    // lectura
    int lectura = read(entrada, &buffer, 1);
    if (-1 == lectura){
        printf("error al leer\n");
        return -1;
    }
    // bucle de copia
    while (0 != lectura){
        // escritura
        write(salida, &buffer, 1);
        // lectura
        lectura = read(entrada, &buffer, 1);
    }
    // cerrar los archivos
    close(entrada);
    close(salida);
    return 0;
}




int main(int argc, char * argv[]){
    if (3 > argc){
        printf("missing arguments\n");
        return -1;
    }

    char origen[1000] = "";
    char destino[1000] = "";
    stpcpy(origen, argv[1]);
    strcpy(destino, argv[2]);
    copiar(origen, destino);


    return 0;
}