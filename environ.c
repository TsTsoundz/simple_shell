#include "shell.h"

/**
 * _ourenv –this will print the current environment
 * @info: this structure contains potential arguments that is used to maintain
 * function prototype.
 * Return: Always 0
 */
int _ourenv(info_i *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv – this generates the value of an environ variable
 * @info: this structure contains arguments that is used to maintain
 * @name: env var name
 * Return: the value
 */
char *_getenv(info_i *info, const char *name)
{
	list_i *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _oursetenv – will automatically initialize a new environment variable,
 * or modify an existing one
 * @info: this structure contains potential arguments that is 
 *  used to maintain function prototype.
 *  Return: Always 0
 */
int _oursetenv(info_i *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _ourunsetenv – this will remove an environment variable
 * @info: this structure contains potential arguments that is 
 * used to maintain constant function prototype.
 *  Return: Always 0
 */
int _ourunsetenv(info_i *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * populate_env_list: this will populate the env linked list
 * @info: this is a structure that contains arguments that is 
 * used to maintain function prototype.
 * Return: Always 0
 */
int populate_env_list(info_i *info)
{
	list_i *node = NULL;
	size_i i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
