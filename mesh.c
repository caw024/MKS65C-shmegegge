#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(){
  key_t key;
  int shmid;
  char *data;

  // "Well, since the type key_t is actually just a long, you can use any number you want."
  key = 21335;
  shmid = shmget(key, 1024, 0644 | IPC_CREAT);
  printf("shmid: %d\n", shmid);
  data = shmat(shmid, (void *)0, 0);
  printf("data: %s\n", data);


  printf("You want to change data: enter a string");
  gets(data);
  printf("new data: %s\n", data);


  //char * x;
  // scanf("%s", &x);

  shmdt(data);
  printf("cleared data: %s\n", data);

  shmctl(shmid, IPC_RMID, NULL);
}
