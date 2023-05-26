//
// Created by tomas on 25/05/23.
//
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void alarma(){
    printf("no se puso nada se procede a a acabar el programa\n");
    kill(getpid(), SIGKILL);

}

void pulsado(){
    printf("se capturo una tecla!!!\n");
    kill(getpid(), SIGKILL);

}

int main(int argc, char *argv[]){
    struct sigaction sig_alarm, sig_pulsado;
    // primera alarma
    sig_alarm.sa_flags = 0;
    sigemptyset(&sig_alarm.sa_mask);
    sig_alarm.sa_handler = alarma;
    sigaction(SIGALRM, &sig_alarm, NULL);
    //crear alarma
    alarm(3);
    // alarma en caso de que se pulso algo
    sig_pulsado.sa_flags = 0;
    sigemptyset(&sig_pulsado.sa_mask);
    sig_pulsado.sa_handler = pulsado;
    sigaction(SIGUSR1, &sig_pulsado, NULL);
    // bucle para leer caracter
    int c;
    // funcion que revisa si se ha puesto una tecla
    while (1) {
        c = getchar();
        // la funcion retorna -1 si no se pulso ninguna tecla
        if (-1 != c) {
            kill(getpid(), SIGUSR1);
        }
    }



    return 0;
}