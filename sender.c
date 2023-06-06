#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
void main()
{
char st[100];
int shmid;
void *sharedmemory;
shmid=shmget((key_t) 1234,100,0666|IPC_CREAT);
printf("shmid is %d",shmid);
sharedmemory=shmat(shmid,NULL,0);
printf("sharedmemory address is %p \n",sharedmemory);
printf("Enter the message \n");
scanf("%s",st);
strcpy(sharedmemory,st);
printf("Sender write %s in shared memory \n",(char*)sharedmemory);
printf("shmid is  %d \n ",shmid);
}
