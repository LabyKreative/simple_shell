#include "main.h"

/**
 * shell_execute - function to executes the built in commands.
 * @argv: pointer to the argv.
 * @built_in_arr: pointer to the struct with built in commands.
 * Return: 1 on success
 **/
int shell_execute(char **argv, built_in_t built_in_arr[])
{
	int i = 0;

	if (argv[0] == NULL)
		return (0);

	while (i < 5)
	{
		if (_strcmp(argv[0], built_in_arr[i].command) == 0)
		{
			return (built_in_arr[i].f(argv));
		}
		i++;
	}
	return (shell_launch(argv));
}
/**
 * shell_launch - creates the process to execute shell commands.
 * @argv: pointer to argv
 * Return: 1 on success
 */
int shell_launch(char **argv)
{
	int pid, existence, current_path = 0, c, status;
	char **path = 0, *command = 0, *path_command = 0, *env = 0;

	pid = fork();
	if (pid == 0)
	{
		env = _getenv("PATH");
		if (env && env[0] == ':')
			current_path = 1;
		path = token_buff(env, ":");
		for (c = 0; path[c]; c++)
		{
			command = _strcat("/", argv[0]);
			path_command = _strcat(path[c], command);
			existence = check_existence(path_command);
			if (existence != -1 && !current_path)
			{
				argv[0] = path_command;
				break;
			}
			else
				free(path_command);
			free(command);
		}
		existence = check_existence(argv[0]);
		if (existence == -1)
		{
			_freeall(argv, path);
			exit(127);
		}
		if (execve(argv[0], argv, environ) == -1)
			perror("Error");
		_freeall(argv, path);
		exit(2);
	}
	else if (pid < 0)
		perror("hsh");
	else
		wait(&status);
	return (WEXITSTATUS(status));
}

/**
 * _freeall - a function that frees arv and path.
 * @argv: Buffer containing the tokens.
 * @path: path to look for exec files.
 */
void _freeall(char **argv, char **path)
{
	free(argv[0]);
	free(argv);
	free(path);
}

/**
 * check_existence - a function that checks whether a file exists.
 * @path: pointer to the path to search in
 * Return: 1 on success, -1 if failed
 */
int check_existence(char *path)
{
	int fd = access(path, F_OK | X_OK);

	if (fd == -1)
		return (-1);
	return (1);
}
