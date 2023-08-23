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

extern char **environ;



void getline_sh(char **text);
void sett(char *text);
void unsett(char *text);
void cd(char *text);

void prompt(char **arv, char **envp, bool flg);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *handle_path(char **rgv, char *cmd);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
void handle_exit(char *cmd);
void runcmd(char **rgv, char **arv, char **envp);
char *trim(char *cmd);
char *_strncpy(char *dest, char *src, int n);
char *get_path(char *cmd);
char *_getenv(char *name);
char **tokenize_env(char *path);
void geterror(denum *n, char **arv, char *cmd);

typedef struct denum
{
	int cnt;
} denum;

#endif
