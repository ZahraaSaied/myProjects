#include "unp.h"
using namespace std;
int main()
{
int sockfd;
int buffsize = 1024;
char buffer[buffsize];
char* ip = "127.0.0.1";
struct sockaddr_in servaddr;
if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 )
{
cout<<"Socket establishing error"<<endl;
exit(1);
}
servaddr.sin_family = AF_INET;
servaddr.sin_port = 1500;
if((inet_pton(AF_INET, ip, &servaddr.sin_addr)) <= 0)
{
cout<<"inet_pton error"<<endl;
exit(1);
}
if((connect(sockfd, (sockaddr* )&servaddr, sizeof(servaddr))) < 0)
{
cout<<"connection error"<<endl;
exit(1);
}
cout<<"You can start chatting"<<endl<<"press '#' to end connection"<<endl;
do
{
cout<<"client: ";
do
{
cin>>buffer;
write(sockfd, buffer, buffsize);
if(*buffer == '#')
{
close(sockfd);
return 0 ;
}
}while(*buffer != '*');
cout<<"server: ";
do
{
read(sockfd, buffer, buffsize);
cout<< buffer<<" ";
if(*buffer == '#')
{
close(sockfd);
return 0 ;
}
}while(*buffer != '*');
}while(true);
close(sockfd);
return 0 ;
}
