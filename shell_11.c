#include "shell.h"

/**
* get_line - reading the input
* Return: null or address
*/

char *get_line()

{
	int i, buffsize = BUFFER_SIZE, rd;
	char c = 0;
	char *buff = malloc(buffsize);

	if (buff == NULL)
	{
		free(buff);
		return (NULL);
	}

	for (i = 0; c != EOF && c != '\n'; i++)
	{
		fflush(stdin);
		rd = read(STDIN_FILENO, &c, 1);
		if (rd == 0)
		{
			free(buff);
			exit(EXIT_SUCCESS);
		}
		buff[i] = c;
		if (buff[0] == '\n')
		{
			free(buff);
			return ("\0");
		}
		if (i >= buffsize)
		{
			buff = _realloc(buff, buffsize, buffsize + 1);
			if (buff == NULL)
			{
				return (NULL);
			}
		}
	}
	buff[i] = '\0';
	handle_hash(buff);
	return (buff);
}

/**
 * handle_hash - handles all hash tags
 * @buff: inputs
 * Return: null or address
*/

void handle_hash(char *buff)

{
	int i;

	for (i = 0; buff[i] != '\0'; i++)
	{
		if (buff[i] == '#')
		{
		buff[i] = '\0';
		break;
		}
	}
}

