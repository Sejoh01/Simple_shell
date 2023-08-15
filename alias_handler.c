#include <stdlib.h>
#include "shell.h"
#include "main.h"

/**
 * my_alias - Implements the "alias" shell command.
 * @params: Pointer to a param_t struct with the shell state and args.
*/
void my_alias(param_t *params)
{
	unsigned int var;

	if (params->tokCount == 1)
	{
		/* If called with no args, print all existing aliases. */
		print_aliases(params);
		return;
	}
	for (var = 1; var < params->tokCount; var++)
	{
		if (_strchr(params->args[var], '='))
			set_my_alias(params->args[var], params);
		else
			print_my_alias(params->args[var], params);
	}
}
/**
 * set_my_alias - creates a new alias or updates an existing one
 * @name: the name of the alias to set
 * @params: shell
 * Return: void
*/

void set_my_alias(char *name, param_t *params)
{
	char *value;
	char *junk = NULL;
	unsigned int i = 0, j = 1;

	while (name[i] && name[i] != '=')
		i++;
	if (name[i + 1] == '\'')
	{
		if (_strchr(&name[i + 2], '\''))
		{
			junk = _strchr(&name[i + 2], '\'');
			*junk = '\0';
			value = _strdup(&name[i + 2]);

			if (junk[1] != '\0')
			{
				while (junk[j] &&
					(junk[j] == ' ' || junk[j] == '\t' || junk[j] == '\n'))
					j++;
				if (junk[j] != '\0')
					set_my_alias(&junk[j], params);
			}
		}
		else
		{
			_print("Usage: alias name='value' [...]\n");
			return;
		}
	}
	else
		value = _strdup(&name[i + 1]);
	name[i] = '\0';
	make_my_alias(name, value, params);
}
/**
 * make_my_alias - creates a new alias and adds it to the alias list
 * @name: alias name
 * @val: alias value
 * @params: parameter struct with list
 */

void make_my_alias(char *name, char *val, param_t *params)
{
	list_t *head = params->alias_head;

	while (head)
	{
		if (!_strcmp(name, point->str))
		{
			free(head->val);
			head->val = val;
			head->valLen = _string(val);
			params->status = 0;
			return;
		}
		head = head->next;
	}

	params->alias_head = add_node(&(params->alias_head), name, val);
	free(val);
	params->status = 0;
}
