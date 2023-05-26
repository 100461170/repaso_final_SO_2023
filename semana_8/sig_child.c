//
// Created by tomas on 25/05/23.
//
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void sig_child(){
    printf("murio el hijo\n");
}

void sigurs1(){
    printf("senial sigurs1 del hijo\n");
}


int main(int argc, char * argv[]){
    pid_t pid;
    pid = fork();

    switch(pid){
        case -1:
            printf("error in fork\n");
            return -1;

        case 0:
            sleep(2);
            kill(getppid(), SIGUSR1);
            sleep(2);
            exit(0);




        default:
            struct sigaction s1;
            s1.sa_flags = 0;
            sigemptyset(&(s1.sa_mask));
            s1.sa_handler = sigurs1;
            sigaction(SIGUSR1, &s1, NULL);
            struct sigaction s2;
            s2.sa_flags = 0;
            sigemptyset(&(s2.sa_mask));
            s2.sa_handler = sig_child;
            sigaction(SIGCHLD, &s2, NULL);
            pause();
            pause();
            exit(0);

    }


    return 0;
}