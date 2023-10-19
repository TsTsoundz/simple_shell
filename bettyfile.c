#include "main.h"

/**
 * print_alphabet_x3 - Prints the  alphabet, in lowercase three times
 * Return: Always 0
 */
void print_alphabet_x3(void)
{
	int tally = 0;
	char letters;

	while (tally++ <= 3)
	{
		for (letters = 'a'; letters <= 'z'; letters++)
			_putchar(letters);
		_putchar('\n');
	}
}
