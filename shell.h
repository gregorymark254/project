#ifndef _SHELL_H_
#define _SHELL_H_
#define BUFFER_SIZE 1024
#define PRINTER(c) (write(STDOUT_FILENO, c, strlen(c)))

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


extern char **environment;

unsigned int checker(char c, const char *str);
char *_strtok(char *str, const char *delim);
char *_string_copy(char *destination, char *src, int n);
int _string_length(char *s);
int _putchar(char c);
int _convert(char *s);
void _put_str(char *str);
int _strcmp(char *s1, char *s2);
int _isalpha(int c);
void array_rev(char *arr, int len);
int intlen(int num);
char *_itoa(unsigned int n);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *str);


#endif

