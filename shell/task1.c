#include "shell.h"

int execute(char *text);
extern char **environ;

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

    while (0 < 1)
    {
        printf("#cisfun$ ");
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
        if (checker > 0)
        {
            text[checker - 1] = '\0';
        }

        forked = fork();
        if (forked == 0)
        {
            execute(text);
        }
        wait(&waiting);
    }
    return (0);
}

/**
 * execute - Execute a command using execve
 * @text: The command to execute
 * Return: 0 on success, -1 on error
 */
int execute(char *text)
{
    char *argv[2];
    argv[0] = text;
    argv[1] = NULL;

    if (execve(argv[0], argv, environ) == -1)
    {
        perror("./hsh");
    }
    return (0);
}

