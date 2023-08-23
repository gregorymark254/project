#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"
#define MAX_LINE 80

int main(void)
{
    char *args[MAX_LINE/2 + 1];
    int should_run = 1;
    char cmd[MAX_LINE];
    char *token;
    int i;

    while (should_run) {
        printf("#cisfun$ ");
        fflush(stdout);

        fgets(cmd, MAX_LINE, stdin);
        cmd[strcspn(cmd, "\n")] = '\0';

        if (strcmp(cmd, "exit") == 0) {
            should_run = 0;
            continue;
        }

        token = strtok(cmd, " ");
        i = 0;
        while (token != NULL) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        if (fork() == 0) {
            execve(args[0], args, NULL);
            perror(args[0]);
            exit(1);
        }
        else {
            wait(NULL);
        }
    }

    return 0;
}

