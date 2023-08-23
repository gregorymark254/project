#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE 80

int main(void) {
    char *args[MAX_LINE/2 + 1];
    int should_run = 1;
    char cmd[MAX_LINE];
    char *token;
    int i;
    pid_t child_pid;
    int status;

    while (should_run) {
        printf("#cisfun$ ");
        fflush(stdout);

        if (fgets(cmd, MAX_LINE, stdin) == NULL) {
            break; 
        }
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

        child_pid = fork();
        if (child_pid == 0) {
            execve(args[0], args, NULL);
            perror(args[0]);
            _exit(1);
        } else if (child_pid < 0) {
            perror("fork");
        } else {
            waitpid(child_pid, &status, 0);
        }
    }

    return 0;
}

