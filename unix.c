#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 100

int main() {
    char command[MAX_COMMAND_LENGTH];
    char *prompt = "simple_shell$ ";

    while (1) {
        printf("%s", prompt);

        if (fgets(command, sizeof(command), stdin) == NULL) {
            // Handle end of file (Ctrl+D)
            printf("\nGoodbye!\n");
            break;
        }

        // Remove the newline character
        command[strlen(command) - 1] = '\0';

        pid_t pid = fork();

        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process
            if (execlp(command, command, (char *)NULL) == -1) {
                perror("execlp");
                exit(EXIT_FAILURE);
            }
        } else {
            // Parent process
            int status;
            waitpid(pid, &status, 0);
            if (WIFEXITED(status)) {
                // Child process exited normally
                printf("Child process exited with status %d\n", WEXITSTATUS(status));
            }
        }
    }

    return 0;
}
