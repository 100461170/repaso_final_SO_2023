//
// Created by tomas on 23/05/23.
//
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <pthread.h>

void imprimir(){
    for (int i = 0; i < 3; i++) {
        printf("thread says hi\n");
        sleep(1);
    }
    pthread_exit(0);
}

int main(int argc, char * argv[]){
    pthread_t th1;
    // crear thread
    pthread_create(&th1, NULL, (void *) imprimir, NULL);
    pthread_join(th1, NULL);


    return 0;
}