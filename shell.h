#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>

int begin(int argc, char **argv, char **env);
char *prompt_input(char **argv);
char **store_data(char *input, char **argv);
int _nmbr_value(char *input);
void run_cmd(char **value, char **argv, char **env);

#endif
