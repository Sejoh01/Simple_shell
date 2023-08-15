#include <stdlib.h>
#include "shell.h"
#include "main.h"
/**
 * print_my_alias - prints the value of an alias, if it exists
 * @name: name of the alias
 * @params: parameter with alias list
 * Function printing the alias with a given name if found and an error when not found
*/
void print_my_alias(char *name, param_t *params)
{
	unsigned int len = 0;
	list_t *ptr = params->alias_head;

	len = _strlen(name);
	while (ptr)
	{
		if (_nstrcmp(name, ptr->str, len - 1) == 0)
			_print("%s=\'%s\'\n", ptr->str, ptr->val);
		ptr = ptr->next;
	}
	params->status = 0;
}

/**
 * print_aliases - prints all aliases in the alias list
 * @params: parameter struct containing the alias list
 *
 * Function printing all the name and values of each alias to the stdout
*/

void print_aliases(param_t *params)
{
	print_alias_list(params->alias_head);
	params->status = 0;
}

/**
 * print_alias_list - prints the name and value of each alias in a linked list
 * @head: pointer to the head of the linked list
 *
 * Function printing all the name and values of each alias to the stdout
*/

void print_alias_list(list_t *head)
{
	if (head)
	{
		print_alias_list(head->next);
		if (head->str != NULL)
			_print("%s=\'%s\'\n", head->str, head->val);
	}
}
