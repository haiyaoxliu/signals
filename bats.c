#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>


static void sigh(int sign) {

  if(sign == SIGINT) {  
    int fd;
    char *o = "\nSIGINT signal exit\n";
    fd = open("./out.txt",O_WRONLY,0600);
    lseek(fd,0,SEEK_END);
    write(fd,o,sizeof(*o));
    printf("\n");
    exit(1);
  }

  if(sign == SIGUSR1) {
    printf("\n*pid:\t%d", getpid());
  }
}

int main() {

  //tie
  signal(SIGINT, sigh);
  signal(SIGUSR1, sigh);

  while(1) {
    printf("\npid:\t%d", getpid());
    sleep(1);
  }

  return 0;

}
