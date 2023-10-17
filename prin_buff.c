#include "main.h"
/**
 * print_buffer - Prints the contents of a buffer if present
 * @buffer: Array of characters to be printed
 * @buff_ind: Index at which to add next buffer character, shows length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
