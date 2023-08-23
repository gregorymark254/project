#include "shell.h"

int execute(char **args);
int tokenize(char *text);
char **args;

/**
 * main - Entry point of the program
 * @argc: no of args
 * @argv: array of commands
 * @env: environment vars
 * Return: 0 indicating success
 */
int main(int argc, char *argv[], char **env)
{
	int waiting;
	pid_t forked;
	int x11 = 0;
	int checker;
	char *text = NULL;
	size_t len = 0;
	char *ex, *envv, *unset, *set, *chdir;

	(void) argc;
	(void) argv;
	while (0 < 1)
	{
		printf("#cisfun$ ");
		checker = getline(&text, &len, stdin);
		if (checker == EOF)
		{
			break;
		}
		if (checker == -1)
		{
			perror("Line not read\n");
			continue;
		}
		ex = strstr(text, "exit");
		set = strstr(text, "setenv");
		unset = strstr(text, "unsetenv");
		chdir = strstr(text, "cd");
		if (chdir != NULL)
		{
			cd(text);
			continue;
		}
		if (set != NULL)
		{
			sett(text);
			continue;
		}
		if (unset != NULL)
		{
			unsett(text);
			continue;
		}
		envv = "env";
		if (text == envv)
		{
			while (env[x11] != NULL)
			{
				printf("%s\n", env[x11]);
				x11++;
			}
			continue;
		}
		if (ex != NULL)
		{
			exit(0);
		}
		text[strcspn(text, "\n")] = '\0';
		forked = fork();
		if (forked == 0)
		{
			tokenize(text);
			execute(args);
		}
		wait(&waiting);
	}
	return (0);
}

/**
 * tokenize - tokenizes the user commands
 * @text: arguments
 * Return: 0 indicating success
 */
int tokenize(char *text)
{
	int y = 0;
	char *delim = " ";

	args = malloc(sizeof(char *) * 10);
	if (args == NULL)
	{
		perror("./hsh");
		return (-1);
	}
	args[0] = strtok(text, delim);
	while (args[y] != NULL)
	{
		y++;
		if (y >= 10)
		{
			args = realloc(args, (y + 1));
		}
		args[y] = strtok(NULL, delim);
	}
	args[y] = NULL;
	return (0);
}

/**
 * execute - Execute a command using execve
 * @args: The command to execute
 * Return: 0 on success, -1 on error
 */
int execute(char **args)
{
	if (execvp(args[0], args) == -1)
	{
		perror("./hsh");
	}
	return (0);
}

