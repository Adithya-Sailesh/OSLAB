#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
void main(){
    int shmid;
    void *share;
    shmid=shmget((key_t)1222,1024,0666);
    printf("SHM ID=%d",shmid);
    share=shmat(shmid,NULL,0);
    printf("data is: %s",(char *)share);
}
