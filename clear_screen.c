#include "main.h"
#include "shell.h"

/**
 * _clear - clears the terminal screen
 * @params: parameters
 *
 * Return: void
 */
void _cls(param_t *params)
{
	(void)params;
	_print("\033[2J\033[1;1H");
}

