#include "main.h"
#include "shell.h"

/**
 * _printenv - prints the environment
 * @params: parameters
 *
 * Prints all the environment variables stored in params->env_head. Else an error message
 *
 * Return: void
 */

void _printenv(param_t *params)
{
	if (params->tokCount != 1)
	{
		_print("env: %s: No such file or directory\n",
			params->args[1]);
		params->status = 2;
		return;
	}
	print_env_list(params->env_head);
	params->status = 0;
}

/**
 * print_env_list - print the environment variables
 * @head: pointer to the head of the environment list
 *
 * A pointer to the head and prints the list in reverse order. 
*/

void print_env_list(list_t *head)
{
	if (head)
	{
		print_env_list(head->next);
		if (head->str)
			_print("%s=%s\n", head->str, head->val);
	}
}
