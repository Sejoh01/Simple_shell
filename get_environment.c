#include "main.h"
#include "shell.h"
#include <stdlib.h>

/**
 * _getenv - Gets the value of an environment variable.
 * @name: The name of the environment variable to retrieve.
 * @params: Pointer to the parameter structure containing the environment list.
 *
 * Return: A pointer of environment variable, or NULL if not.
 *
 * Function to duplicate the environment variable in the linked list when a match is found else null 
 */

char *_getenv(char *name, param_t *params)
{
	list_t *pointer = params->env_head;

	while (pointer)
	{
		if (!_strcmp(name, pointerr->str))
			return (_strdup(pointer->val));
		pointer = pointer->next;
	}
	return (NULL);
}
