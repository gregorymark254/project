#include "shell.h"

void getline_sh(char **text)
{
	int x = 0;
	char buff[1024];

	while (x >= 0)
	{
		x = read(STDIN_FILENO, buff, sizeof(buff));
		if (x == 0)
		{
			break;
		}
		if (x == -1)
		{
			perror(".hsh");
		}
		*text = malloc(x + 1);
		memcpy(*text, buff, x);
		(*text)[x] = '\n';
	}
}
