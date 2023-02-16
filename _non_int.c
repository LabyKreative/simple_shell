#include "main.h"

/**
 * _non_int - a function that executes the shell in non-interactive mode.
 * @arr: array of structures to handle built in commands.
 */
void _non_int(built_in_t arr[])
{
	char **argv;
	char *buff = 0;
	int status = EXIT_SUCCESS;
	size_t buffsize = 1024;
	int err_count = 0;

	while (getline(&buff, &buffsize, stdin) != EOF)
	{
		err_count++;
		argv = token_buff(buff, " \t\r\n\a");
		status = shell_execute(argv, arr);
		_error_handler(&status, err_count, argv);
		free(argv);
	}
	free(buff);
	exit(status);
}
