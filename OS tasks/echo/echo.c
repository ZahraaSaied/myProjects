/*
 * echo - read and echo text lines until client closes connection
 */
/* $begin echo */
#include "csapp.h"

void echo(int connfd)
{
    size_t n;
    char buf[MAXLINE];


    while((n = read(connfd, buf, MAXLINE)) != 0) { //line:netp:echo:eof
	printf("server received %d bytes\n", (int)n);
	write(connfd, buf, n);
    }
}
/* $end echo */

