//
// Created by tomas on 23/05/23.
//
#include <unistd.h>
#include <stdio.h>
# include <stdio.h>
#include <unistd.h>
# include <fcntl.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char * argv[]){
    pid_t pid;
    pid = fork();
    switch (pid) {
        case -1:
            perror("error al hacer el pid");
            exit(-1);

        case 0:
            sleep(3);
            printf("soy el hijo\n");
            printf("pid: %d y mi padre es %d\n", getpid(), getppid());
            exit(0);

        default:
            printf("soy el padre\n");
            printf("pid: %d\n", getpid());
            wait(NULL);
            exit(0);
    }




    return 0;
}