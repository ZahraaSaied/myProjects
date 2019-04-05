#include "unp.h"
int main(int argc, char** argv)
{
int sockfd, n;
char recivline[MAXLINE+1];
struct sockaddr_in servaddr;
if(argc != 2)
{
cout<<"argument missing"<<endl;
exit(1);
}
if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
{
cout<<"socket error"<<endl;
exit(1);
}
bzero(&servaddr, sizeof(servaddr));
servaddr.sin_family = AF_INET;
servaddr.sin_port=htons(13);
if(inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
{
cout<<"IP conversion error"<<endl;
exit(1);
}
if(connect(sockfd, (sockaddr *)&servaddr, sizeof(servaddr)) < 0)
{
cout<<"connection error"<<endl;
exit(1);
}
while ((n = read(sockfd, recivline, MAXLINE)) > 0)
{
recivline[n] = 0;
if(fputs(recivline, stdout) == EOF)
{
cout<<"error in fputs"<<endl;
exit(1);
}
}
if(n < 0)
{
cout<<"error in reading"<<endl;
exit(1);
}
close(sockfd);
exit(0);
return 0;
}
