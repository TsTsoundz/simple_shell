#include "shell.h"

/**
 *_eputs: prints an input string
 * @str:  string to be printed
 * Return: Nothing
 */
void _eputs(char *str)
{
	int i = 0;

	while (!str)
		return;
	if (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar: writes the character q to stderr
 * @q: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char q)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (q == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (q != BUF_FLUSH)
		buf[i++] = q;
	return (1);
}

/**
 * _putfd: writes the character q to given fd
 * @q: this is the character to print
 * @fd: this is the filedescriptor to write to.
 * Return: On success 1
 * on error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char q, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (q == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (q != BUF_FLUSH)
		buf[i++] = q;
	return (1);
}

/**
 *_putsfd : this prints an input string
 * @str: this is the string to be printed
 * @fd: this is the filedescriptor to write to
 * Return: the number of chars put
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	while (!str)
		return (0);
	if (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
