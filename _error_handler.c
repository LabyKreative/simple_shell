#include "main.h"

/**
 * _error_handler - a function that handles the error, and prints
 * them according to format.
 * @status: exit status.
 * @err: line counter.
 * @argv: Buffer containing the tokens.
 */
void _error_handler(int *status, int err, char **argv)
{
	/* error msg */

	switch (*status)
	{
		case 127:
			_print_base_error(err, argv);
			_puts("not found");
			_puts("\n");
			break;
		case 3:
			_print_base_error(err, argv);
			_puts("Illegal number");
			if (argv[1])
			{
				_puts(": ");
				_puts(argv[1]);
				_puts("\n");
			}
			break;
		default:
			break;
	}
}
/**
 * _print_base_error - a function that prints the errors.
 * @err: line counter.
 * @argv: buffer containing the tokens.
 */
void _print_base_error(int err, char **argv)
{
	_puts(program_invocation_name);
	_puts(": ");
	_printd(err);
	_puts(": ");
	_puts(argv[0]);
	_puts(": ");
}
