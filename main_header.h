#ifndef _MAIN_H_
#define _MAIN_H_
#define NULL_PTR -1
#define WRONG_SPECIFIER -2
#include <unistd.h>

/**
 * struct list_s - singly linked list node
 * @str: string data
 * @val: value string data
 * @len: length of the string data
 * @valLen: length of the value string data
 * @next: pointer to the next node in the list
 *
 * Description: This struct represents a node in a singly linked list
*/

typedef struct list_s
{
	char *str;
	char *val;
	unsigned int len;
	unsigned int valLen;
	struct list_s *next;
} list_t;

int _putchar(char c);
size_t print_list(list_t *h);
size_t list_len(list_t *h);
list_t *add_node(list_t **head, char *str, char *val);
void free_list(list_t *head);
list_t *get_node(list_t *head, char *str);

int _Delim(char c, char *delim)
char *get_char(char c);
char *get_string(char *s);
char *get_arg(char type, ...);
char *get_binary(unsigned int n);
char *get_rev(char *s);
char *get_rot13(char *s);
char *move_left(char *a, int size, int num);
int _print(const char *, ...);
int _strcmp(char *, char *);
int _string(char *);
char *_strchr(char *s, char c);
char *_strdup(char *);
char *get_number(int n);
char *_concat(char *, char *);
char *_nconcat(char *, char *, unsigned int);
int _atoi(char *s);
int _nstrcmp(char *, char *, int n);
#endif
