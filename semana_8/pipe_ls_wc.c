//
// Created by tomas on 25/05/23.
//
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


int main(int argc, char * argv[]){
    int p1[2];

    if (-1 == pipe(p1)){
        printf("error al hacer pipe\n");
        return -1;
    }
    pid_t pid;
    pid = fork();
    switch (pid){
        case -1:
            printf("error al hacer fork\n");
            return -1;

        default:
            close(p1[0]); // delete input
            close(STDOUT_FILENO); //cierro salida estandar
            dup(p1[1]); // duplico mi salida al 0
            close(p1[1]); // cierro desc output
            execlp("ls", "ls", NULL);

        case 0:
            close(STDIN_FILENO); // cierro entrada estandar
            close(p1[1]); // cierro salida
            dup(p1[0]); // pongo entrada en la salida
            close(p1[0]); // cierro entrada
            execlp("wc", "wc", NULL);


    }

    return 0;
}