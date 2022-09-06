#include "shell.h"
/**
 * _fork_fun - function that create a fork
 *@args: command and values path
 *@av: Has the name of our program
 *@env: environment
 *@lineptr: command line for the user
 *@np: id of proces
 *@c: Checker add new test
 *Return: 0 success
 */

int _fork_fun(char **args, char **av, char **env, char *lineptr, int np, int c)
{
	pid_t child;
	int status;
	char *format = "%s: %d: %s: not found\n";

	child = fork();

	if (child == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			fprintf(stderr, format, av[0], np, args[0]);
			if (!c)
				free(args[0]);
			free(args);
			free(lineptr);
			exit(errno);
		}
	}
	else
	{
		wait(&status);

		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			return (WEXITSTATUS(status));
	}
	return (0);
}
