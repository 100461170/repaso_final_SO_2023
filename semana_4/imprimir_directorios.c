//
// Created by tomas on 23/05/23.
//
# include <stdio.h>
#include <unistd.h>
# include <fcntl.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

#define PATHMAX 512

int main(int argc, char * argv[]){
    // puntero a DIR
    char nombre_directorio[2000];
    DIR * directorio;
    if (argc == 1) {
        getcwd(nombre_directorio, PATHMAX);
    }
        // En caso contrario, copiamos la ruta del directorio a nombre_directorio
    else if (argc == 2) {
        memcpy(nombre_directorio, argv[1], strlen(argv[1]));
    }
    // Si hay un error al abrir el directorio devolvemos -1
    directorio = opendir(nombre_directorio);
    if (directorio == NULL) {
        printf("El directorio no puede abrirse\n");
        return -1;
    }
    // crear estructura dirent
    struct dirent *nodo;
    nodo = readdir(directorio);
    while (NULL != nodo){
        printf("carpeta o archivo: %s\n", nodo->d_name);
        nodo = readdir(directorio);
    }
    return 0;
}