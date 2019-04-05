
#include "csapp.h"

int main(int argc, char **argv) {
  int clientfd;
  int bufsize;
  char *host, *port, buf[MAXLINE];
  char res[MAXLINE];

  if (argc != 3) {
    fprintf(stderr, "usage: %s <host> <port>\n", argv[0]);
    exit(0);
  }

  host = argv[1];
  port = argv[2];

  clientfd = Open_clientfd(host, port);

  printf("write an op. like 2 + 5 \n");
  do {
    bufsize = read(STDIN_FILENO, buf, MAXLINE);
    write(clientfd, buf, bufsize);
    memset(res, 0, sizeof res);
    printf("the result is : ");
    read(clientfd, res, MAXLINE);
    printf("%s\n", res);

  } while (1);

  Close(clientfd);
  exit(0);
}
