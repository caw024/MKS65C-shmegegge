#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>

int main(){
  int shmid;
  char *data;

  // "Well, since the type key_t is actually just a long, you can use any number you want."
  //Creates memory
  shmid = shmget(21135, 1024, 0644 | IPC_CREAT);
  printf("shmid: %d\n", shmid);
  data = shmat(shmid, (void *)0, 0);
  printf("data: %s\n", data);
  if (data == (char *)-1){
    printf("%s\n", strerror(errno));
    exit(1);
  }


  //Add/edit memory
  printf("Enter a string to change data: ");

  fgets(data,200,stdin);
  printf("new data: %s\n", data);
  

  //clears memory
  if (shmdt(data) == -1){
    printf("%s\n", strerror(errno));
    exit(1);
  }

  //delete memory
  shmctl(shmid, IPC_RMID, NULL);
  printf("memory deleted\n");
  
}
