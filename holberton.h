#ifndef HOLBERTON_H
#define HOLBERTON_H


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>


extern char **environ;

/**
 * struct env_t - structure of specific shell environment variables.
 * @exit_sig - holds the exit signal.
 */

typedef struct env_t
{
	int in_shell;
	int status;
	int exit_sig;


}env_t;

/**
 * struct hist_t - singly linked list
 * @cmd: string - (malloc'ed string)
 * @next: points to the next node.
 *
 * Description: singly linked list node structure.
 */

typedef struct hist_t
{

        char *cmd;
        struct hist_t *next;
} hist_t;

/**
 * struct b_t - struct for built in functions.
 * @cmd: command.
 * @func: function associated with command.
 *
 * Description: Builtin function command and corresponding function.
 */

typedef struct b_t
{
        char *cmd;
        void(*func)(char **, env_t *);
}b_t;


/**
 * struct help_list - struct for help files of specific commands.
 * @cmd: command.
 * @file: help file for command.
 *
 * Description: commands and their corresponding help files.
 */

typedef struct help_list
{
	char *cmd;
	char *helpfile;
}help_list;


bool is_interactive(void);
char **tokenize(char *line);
char *_getenv(const char *name);
char *search_path(char *command);
int _putchar(char c);
void print_env(char **environ, env_t *env);
void exit_check(char **cmd, env_t *env);
void exit_shell(char **cmd, env_t *env);
int is_builtin(char **cmd, env_t *env);
int wordcount(char *s, char *d);
char *eachword(char *s);
char **_strtok(char *str, char *d);
int _strcmp(char *s1, char *s2);
env_t *init_env(env_t *env);
void exit_status(char **cmd, env_t *env);
char *reverse(char *s, env_t *env);
char *itoa(int num, char *s, env_t *env);
void echo_parser(char **cmd, env_t *env);
void echo_ppid(char **cmd, env_t *env);
void echo_exit_status(char **cmd, env_t *env);
#endif
