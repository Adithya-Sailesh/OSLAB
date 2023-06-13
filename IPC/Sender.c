#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
void main(){
    int shmid;
    void *sharedmem;
    char buffer[100];
    shmid=shmget((key_t)1222,1024,0666|IPC_CREAT);
    printf("hello\n");
    printf("SHMID = %d\n",shmid);
    sharedmem=shmat(shmid,NULL,0);
    printf("sharedmem is %p\n",sharedmem);
    printf("Enter the text to write");
    read(0,buffer,100);
    strcpy(sharedmem,buffer);
    printf("ITEM WROTE IS - %s",(char *)sharedmem);
}
