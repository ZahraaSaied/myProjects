#include "unp.h"
int main(int argc, char** argv)
{
int listenfd, connfd;
char buff[MAXLINE];
time_t ticks;
struct sockaddr_in servaddr;
listenfd = socket(AF_INET, SOCK_STREAM, 0);
bzero(&servaddr, sizeof(servaddr));
servaddr.sin_family = AF_INET;
servaddr.sin_port = htons(13);
servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
bind(listenfd, (sockaddr* )&servaddr, sizeof(servaddr));
listen(listenfd, LISTENQ);
for(;;)
{
connfd = accept(listenfd, (sockaddr* )NULL, NULL );
ticks = time(NULL);
snprintf(buff,sizeof(buff),"%.24s\r\n",ctime(&ticks));
write(connfd, buff, strlen(buff));
close(connfd);
}
exit(0);
return 0;
}
