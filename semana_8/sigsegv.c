//
// Created by tomas on 23/05/23.
//
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void captura_senial(){
    printf("se capturo la senial y se porcede a ponerla por defecto de nuevo\n");
    signal(SIGSEGV, SIG_DFL);


}



int main(int argc, char * argv[]){

    struct sigaction s1;
    s1.sa_flags = 0;
    sigemptyset(&(s1.sa_mask));
    s1.sa_handler = captura_senial;
    sigaction(SIGSEGV, &s1, NULL);

    int *ptr;
    ptr = 0;
    *ptr = 10;



    return 0;
}