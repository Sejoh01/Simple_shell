#ifndef MY_SHELL_H
#define MY_SHELL_H
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>

/**
 * struct param_s - structure used to hold all shell variables needed
 * @argv: command line argument from main function
 * @buffer: input buffer
 * @args: array of arguments
 * @nextCommand: the next command to process
 * @argsCap: num of arguments the args array can hold
 * @lineCount: total line of input
 * @tokCount: num of tokens in a line input
 * @status: run command return status
 * @env_head: singly linked list of environment vars
 * @alias_head: singly linked list of aliases
 * Description: This structures hold all variables that passed into
 * other functions.
 */

typedef struct param_s
{
	char **argv;
	char *buffer;
	char **args;
	char *nextCommand;
	unsigned int argsCap;
	unsigned int lineCount;
	unsigned int tokCount;
	int status;
	list_t *env_head;
	list_t *alias_head;
} param_t;

/**
 * struct op - a buildin function
 * @name: buildin name
 * @func: pointer to buildin function
 */
typedef struct op
{
	char *name;
	void (*func)(param_t *);
} op_t;


int process_string(param_t *);
char *_strcpy(char *dest, const char *src);
int _getline(param_t *);
char *_strtok(char *str, char *delim, char **savePtr);
void _command(param_t *);
void *_realloc(char **ptr, unsigned int old_size, unsigned int new_size);
void sigint_handler(int);
void _setenv(param_t *params);
void _unsetenv(param_t *params);
char *get_file(param_t *params);
void _leave(param_t *params);
void _printenv(param_t *);
void my_alias(param_t *params);
void set_my_alias(char *name, param_t *params);
void make_my_alias(char *name, char *val, param_t *params);
void print_my_alias(char *name, param_t *params);
void print_aliases(param_t *params);
void print_alias_list(list_t *);
void _cls(param_t *params);
void param_free(param_t *params);
void _changedir(param_t *params);
void (*_builtin(param_t *params))(param_t *);
char *_getenv(char *name, param_t *params);
void print_env_list(list_t *);
void write_error(param_t *params, char *msg);
#endif
