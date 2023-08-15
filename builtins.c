#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"
#include "main.h"

/**
 * _builtin - Get built-in function
 * @params: Pointer to the param_t struct containing command parameters
 *
 * Description: A code to search for the built in function in the struct and returns a function ponter corresponding to it
 * Return: Function pointer to the built-in function. NULL if not found.
 */

void (*_builtin(param_t *params))(param_t *)
{
	op_t ops[] = {
		{"exit", _myExit},
		{"clear", _clear},
		{"env", _printenv},
		{"setenv", _setenv},
		{"cd", _cd},
		{"unsetenv", _unsetenv},
		{"alias", _alias},
		{NULL, NULL},
	};
	op_t *op = ops;

	while (op->name)
	{
		if (!_strcmp(params->args[0], op->name))
			return (op->func);
		op++;
	}
	return (NULL);
}
