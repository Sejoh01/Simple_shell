#include <unistd.h>
#include <stdlib.h>
#include "shell.h"
#include "main.h"
/**
 * _changedir - changees the current working directory
 * @params: shell parameters
 *
 * Return: null
 */

void _changedir(param_t *params)
{
	char *changed = NULL, cwd[1024];
	char **temp = NULL, **originArgs = NULL;
	int i;

	if (params->tokCount == 1)
	{
		changed = _getenv("HOME", params);
		if (!changed)
		{
			params->status = 0;
			return;
		}
	}
	else if (params->args[1][0] == '-')
	{
		if (!_strcmp(params->args[1], "-"))
		{
			changed = _getenv("OLDPWD", params);
			if (!changed)
			{
				params->status = 0;
				changed = _getenv("PWD", params);
				_print("%s\n", changed);
				free(changed);
				return;
			}
			_print("%s\n", changed);
		}
		else
		{
			params->status = 2;
			_print("%s: %d: cd: Illegal option %c%c\n",
				params->argv[0], params->lineCount,
				'-', params->args[1][1]);
			return;
		}
	}
	else
	{
		changed = _strdup(params->args[1]);
		if (!changed)
		{
			write(STDERR_FILENO, "cd changed malloc error\n", 18);
			exit(-1);
		}
	}
	i = chdir(changed);
	if (i)
	{
		write_error(params, "can't cd to ");
		write(STDERR_FILENO, changed, _strlen(changed));
		write(STDERR_FILENO, "\n", 1);
		params->status = 0;
		free(changed);
		return;
	}
	free(changed);
	temp = malloc(sizeof(char *) * 3);
	if (!temp)
		exit(-1);
	originArgs = params->args;
	params->args = temp;
	params->tokCount = 3;

	temp[0] = _strdup("setenv");
	temp[1] = _strdup("OLDPWD");
	if (!temp[0] || !temp[1])
	{
		write(STDERR_FILENO, "cd old PWD malloc error\n", 18);
		param_free(params);
		exit(-1);
	}
	temp[2] = _getenv("PWD", params);
	_setenv(params);
	for (i = 0; i < 3; i++)
		free(temp[i]);

	temp[0] = _strdup("setenv");
	temp[1] = _strdup("PWD");
	temp[2] = _strdup(getcwd(cwd, 1024));
	if (!temp[0] || !temp[1] || !temp[2])
	{
		write(STDERR_FILENO, "cd new PWD malloc error\n", 18);
		param_free(params);
		exit(-1);
	}
	_setenv(params);
	for (i = 0; i < 3; i++)
		free(temp[i]);
	free(temp);
	// reset params 
	params->args = originArgs;
}
