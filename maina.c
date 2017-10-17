#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main()
{
	char buff[128] = {0};
	int fd = open("FIFO",O_WRONLY);

	while(1)
    {
		fgets(buff,sizeof(buff)/sizeof(buff[0]),stdin);

		if(strncmp(buff,"end",3) == 0)
		{
			break;
		}

		buff[strlen(buff) - 1] = '\0';
		write(fd,buff,sizeof(buff)/sizeof(buff[0])-1);
	}

	close(fd);

	return 0;
}

