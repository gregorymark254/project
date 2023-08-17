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
int _compare(char *str1, char *str2);
int _alpha(int c);
void rev_array(char *arr, int len);
int int_length(int n);
char *_conv_int(unsigned int n);
char *_str_concat(char *dest, char *src);
char *_strcopy(char *dest, char *src);
char *_str_chr(char *s, char c);
int _str_cmp(const char *st1, const char *st2, size_t n);
char *_str_up(char *str);
void around_env(char **env);
void *_array(void *a, int el, unsigned int len);
char *_memory_copy(char *dest, char *src, unsigned int n);
void *_calc(unsigned int size);
void *_alloc(void *ptr, unsigned int old, unsigned int new);
void all_free(char **input, char *line);
void show(void);
void handle_signal(int sign);
char *get_line(void);
int path_shell(char **line);
char *get_env(char *name);
char **parse_shell(char *cmd);
int built_in(char **cmd, int er);
void file_read(char *filename, char **argv);
char *shell_build(char *token, char *value);
int check_built_in(char **cmd);
void create_environment(char **envi);
int check_shell(char **tokens, char *line, int count, char **argv);
void file_treat(char *line, int counter, FILE *fd, char **argv);
void exit_file(char **cmd, char *line, FILE *fd);
void handle_hash(char *buff);
int previous(char *input);
int disp_his(char **cmd, int er);
int display(char **cmd, int er);
int change(char **cmd, __attribute__((unused))int er);
int show_help(char **cmd, __attribute__((unused))int er);
int echo(char **cmd, int st);
void exit_build(char **cmd, char *input, char **argv, int d);
int _print(char **cmd);
void print_nbr(unsigned int n);
void print_nbr_in(int n);
void error_print(char *line, int c, char **argv);
void _error(char **argv, int c, char **cmd);


/**
 * struct bulltin - built in function to handle execution
 * @command:pointer to node
 * @fun:fun to excute when bulting
 */

typedef struct  bulltin
{
	char *command;
	int (*fun)(char **line, int er);
} bul_t;

#endif

