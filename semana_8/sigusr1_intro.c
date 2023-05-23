//
// Created by tomas on 23/05/23.
//


#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void captura_senial(){
    printf("se ha capturado una senial\n");

}

int main(int argc, char * argv[]){
    pid_t pid;
    pid = fork();


    switch (pid) {
        case -1:
            perror("error al hacer el fork");

        case 0:
            struct sigaction s1;
            s1.sa_flags = 0;
            sigemptyset(&(s1.sa_mask));
            s1.sa_handler = captura_senial;
            sigaction(SIGUSR1, &s1, NULL);
            pause();
            exit(0);


        default:
            sleep(1);
            kill(pid, SIGUSR1);
            wait(NULL);
            exit(0);


    }

    return 0;
}