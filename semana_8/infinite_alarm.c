//
// Created by tomas on 25/05/23.
//
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int number = 1;
void alarma(){
    printf("se captura la alarma numero %d\n", number);
    number ++;

}

void terminate(){
    printf("se tecleo control-c. Se procede a terminar el programa\n");
    signal(SIGINT, SIG_DFL);
    kill(getpid(), SIGINT);

}


int main(int argc, char * argv[]){
    // crear seniales
    struct sigaction sig_alarm, sig_control_z;
    sig_alarm.sa_flags = 0;
    sigemptyset(&sig_alarm.sa_mask);
    sig_alarm.sa_handler = alarma;
    sig_control_z.sa_flags = 0;
    sigemptyset(&sig_control_z.sa_mask);
    sig_control_z.sa_handler = terminate;
    sigaction(SIGINT, &sig_control_z, NULL);
    sigaction(SIGALRM, &sig_alarm, NULL);

    while (1){
        alarm(3);
        pause();


    }




    return 0;
}