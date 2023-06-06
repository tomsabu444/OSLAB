#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
void main()
{
int shmid;
void *sharedmemory;
shmid=shmget((key_t)1234,100,0666);
printf("sharedmemory id is %d \n",shmid);
sharedmemory=shmat(shmid,NULL,0);
printf("sharedmemory address is %p \n",sharedmemory);
printf("receive the message %s \n",(char*)sharedmemory);
}
