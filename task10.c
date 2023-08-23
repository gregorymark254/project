#include "shell.h"

int execute(char **args);
int tokenize(char *text);
void printenv(void);
char **args;
/*extern char **environ;*/
/**
 * main - Entry point of the program
 * Return: 0 indicating success
 */
int main(void)
{
        int forked, waiting;
        int checker;
        char *text = NULL;
       size_t len = 0;
	char *ex, *env, *unset, *set, *chdir;

        while (0 < 1)
        {
                printf("$ ");
                checker = getline(&text, &len, stdin);
                if (checker == EOF)
                {
                        printf("\n");
                        break;
                }
                if (checker == -1)
                {
                        perror("Line not read\n");
                }
		ex = strstr(text, "exit");
		set = strstr(text, "setenv");
		unset = strstr(text, "unsetenv");
		chdir = strstr(text, "cd");
		if (chdir != NULL)
		{
			cd(text);
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
		env = "env";
		if (text == env)
		{
			printenv();
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
 * printenv - prints env var
 * Return: void
 */
void printenv(void)
{
	extern char **environ;
	int x;

	for (x = 0; environ[x] != NULL; x++)
	{
		printf("%s", environ[x]);
	}
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
                args = malloc(sizeof(char*) * 10);
        if (args == NULL)
        {
                perror("Memory allocation failed\n");
                return (-1);
        }
        
        args[0] = strtok(text, delim);
        
        while (args[y] != NULL)
        {
                y++;
        
                if (y == 10)
                {
                        printf("Too many arguments\n");
                        return (-1);
                }
        
                args[y] = strtok(NULL, delim);
        }
        
        args[y] = NULL;
        return (0);
}


/**
 * execute - Execute a command using execve
 * @text: The command to execute
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
