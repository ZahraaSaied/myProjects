#include "unp.h"
using namespace std;
int main()
{
int listenfd, connfd;
int buffsize = 1024;
char buffer[buffsize];
struct sockaddr_in servaddr;
if((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 )
{
cout<<"Socket establishing error"<<endl;
exit(1);
}
servaddr.sin_family = AF_INET;
servaddr.sin_port = 1500;
servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
bind(listenfd, (sockaddr* )&servaddr, sizeof(servaddr));
listen(listenfd, LISTENQ);
for(;;)
{
connfd = accept(listenfd, (sockaddr* )NULL, NULL);
cout<<"press '#' to end connection"<<endl;
do
{
cout<<"client: ";
do
{
read(connfd, buffer, buffsize);
cout<< buffer<<" ";
if(*buffer == '#')
{
close(listenfd);
return 0 ;
}
}while(*buffer != '*');
cout<<"server: ";
do
{
cin>>buffer;
write(connfd, buffer, buffsize);
if(*buffer == '#')
{
close(connfd);
return 0 ;
}
}while(*buffer != '*');
}while(true);
}
close(connfd);
return 0 ;
}
