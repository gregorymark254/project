#include "shell.h"

/**
 * parse_shell - Parse input node
 * @input: input to node
 * Return: null or address
*/

char **parse_shell(char *input)

{
	char **tkns;
	char *t;
	int i, buffsize = BUFFER_SIZE;

	if (input == NULL)
		return (NULL);
	tkns = malloc(sizeof(char *) * buffsize);
	if (!tkns)
	{
		perror("hsh");
		return (NULL);
	}

	t = _strtok(input, "\n ");
	for (i = 0; t; i++)
	{
		tkns[i] = t;
		t = _strtok(NULL, "\n ");
	}
	tkns[i] = NULL;

	return (tkns);
}

