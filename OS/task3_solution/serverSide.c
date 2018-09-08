
#include "csapp.h"

void computeOperation(int connfd);

int main(int argc, char **argv) {
  int listenfd, connfd;

  if (argc != 2) {
    printf("usage: %s <port>\n", argv[0]);
    exit(0);
  }

  listenfd = Open_listenfd(argv[1]);
  while (1) {
    connfd = Accept(listenfd, NULL, NULL);

    while (1) {
      /**
      Fork code
          // on child of fork
          if (Fork() == 0) {
            close(listenfd);
            computeOperation(connfd);
          }else{
          close(connfd);
          break;
        }
          // if you used the Fork code comment the next line (
      computeOperation(connfd); )
      **/
      computeOperation(connfd);
    }
  }
  Close(connfd);
  exit(0);
}
