#include "main.h"

/**
 * ourexit - function to check if input is the exit command
 * @argv: buffer with the commands
 * Return: Exit status
 */
int ourexit(char **argv)
{
	int status = 0, i;

	if (argv[1] == NULL)
	{
		free(argv[0]);
		free(argv);
		fflush(stdout);
		exit(status);
	}

	for (i = 0; argv[1][i] != '\0'; i++)
	{
		if (argv[1][i] < 48 || argv[1][i] > 57)
			return (3);
	}
	status = _atoi(argv[1]);
	free(argv[0]);
	free(argv);
	exit(status);
}

/**
 * _cd - function that changes the current directory
 * @argv: string containing the input
 * Return: 1 on success
 **/
int _cd(char **argv)
{
	char buff[1024], *cwd, *new_wd, *comp = "-", *old_pwd;
	int chint = 0;
	char *env;

	cwd = getcwd(buff, sizeof(buff));
	if (argv[1] == NULL)
	{
		setenv("OLDPWD", getcwd(buff, sizeof(buff)), 1);
		env = _getenv("HOME");
		chdir(env);
		return (0);
	}
	if (_strcmp(argv[1], comp) == 0)
	{
		old_pwd = _getenv("OLDPWD");
		setenv("OLDPWD", getcwd(buff, sizeof(buff)), 1);
		chdir(old_pwd);
		return (0);
	}

	if (cwd == NULL)
	{
		free(argv);
		perror("Error: ");
		return (1);
	}

	chint = chdir(argv[1]);

	if (chint == -1)
	{
		free(argv);
		perror("Error: ");
		return (1);
	}
	setenv("OLDPWD", _getenv("PWD"), 1);
	new_wd = getcwd(buff, sizeof(buff));
	setenv("PWD", new_wd, 1);
	return (0);
}
