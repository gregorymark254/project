#include "shell.h"

void cd(char *text)
{
	#define buffsize (sizeof(PATH_MAX))
	char *buff[2];
	char *delim = " ";
	char *buffer;

	buff[0] = strtok(text, delim);
	buff[1] = strtok(NULL, delim);
	chdir(buff[1]);
	if (buff[1] == NULL)
	{
		chdir("$HOME");
	}
	buffer = malloc(buffsize + 1);
	getcwd(buffer, buffsize);
	setenv("PWD", buffer, 1);

}
