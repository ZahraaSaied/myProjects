#include "unp.h"
using namespace std;
int main()
{
int listenfd, newconnfd, pid;
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
newconnfd = accept(listenfd, (sockaddr* )NULL, NULL);
if(fork() == 0)
{
close(listenfd);
cout<<"press '#' to end connection"<<endl;
do
{
cout<<"client: ";
do
{
read(newconnfd, buffer, buffsize);
cout<< buffer<<" ";
if(*buffer == '#')
{
close(newconnfd);
return 0 ;
}
}while(*buffer != '*');
cout<<endl<<"server: ";
do
{
cin>>buffer;
write(newconnfd, buffer, buffsize);
if(*buffer == '#')
{
close(newconnfd);
return 0 ;
}
}while(*buffer != '*');
}while(true);
}
close(newconnfd);
}
close(listenfd);
return 0 ;
}
