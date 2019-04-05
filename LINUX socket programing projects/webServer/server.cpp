#include "unp.h"
int main()
{
int listenfd, connfd;
char data[1024];
FILE* html_data;
html_data = fopen("index.html", "r");
fgets(data, 1024, html_data );
struct sockaddr_in servaddr;
if((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 )
{
cout<<"socket error !";
exit(1);
}
bzero(&servaddr, sizeof(servaddr));
servaddr.sin_family = AF_INET;
servaddr.sin_port = htons(80);
servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
if((bind(listenfd, (sockaddr* )&servaddr, sizeof(servaddr))) < 0)
{
cout<<"bind error !";
exit(1);
}
if((listen(listenfd, LISTENQ)) < 0)
{
cout<<"listen error !";
exit(1);
}
for(;;)
{
if((connfd = accept(listenfd, (sockaddr* )NULL, NULL)) < 0)
{
cout<<"accept error !";
exit(1);
}
write(connfd, data, sizeof(data));
close(connfd);
}
return 0 ;
}
