#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char txt[100], txt2[100];
	int fd, size, index, flag=0;

	// read from the screen
	size = read(0, txt, 100);
	txt[size]='\0';
	
	// open file one 
	fd = open("file1.txt",O_RDWR | O_CREAT);	
	if ( 0>fd )
	{
		printf("file1 error in file1 openning \n");
		exit(1);
	}

	// write to file 1;
	size = write (fd,txt,size-1 );
	
	//set file pointer to the start of the file and read from it
	lseek(fd,0,SEEK_SET);
	size = read(fd,txt,size);
	txt[size]='\0';
	close(fd);

	for (int i = 0; i < strlen(txt) || txt[i]=='#'; ++i){
		if(txt[i]=='*')
		{
			flag = !flag;
			continue;
		}
		if (1 == flag)
		{
			txt2[index++]=txt[i];		
		}
	}
	
	txt2[index]='\0';

	fd = open("file2.txt",O_RDWR | O_CREAT);	
	if ( 0>fd )
	{
		printf("file1 error in file1 openning \n");
		exit(1);
	}
	size = write (fd, txt2, index);

	//set the file pointer to the start of the file and read from it
	lseek(fd,0,SEEK_SET);
	size = read(fd,txt,index);
	close(fd);

	//write to the screen
	size = write(1,txt,size);
	return 0;
}