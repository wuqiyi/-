#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>

int Count(char *str)
{
	int tmp = 0;
	int i;

	for(i=0;str[i]!='\0';i++)
	{
		if(isalpha(str[i]) && !isalpha(str[i+1]))
		{
			tmp++;
		}
	}

	return tmp;
}

int main()
{
	char buff[128] = {0};
	int fd = open("FIFO",O_RDONLY);
	int count = 0;
	
	while(read(fd,buff,sizeof(buff)/sizeof(buff[0])-1) > 0)
    {	
		count+=Count(buff);
	}

	printf("count == %d\n",count);
	close(fd);

	return 0;
}

