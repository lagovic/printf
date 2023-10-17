#include "main.h"

/****** PRINTS A POINTER ***/
/**
 * print_pointer - Prints the value of a pointer variable
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_pointer(va_list types, char buffer[],
		                int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);
	
	UNUSED(width);
	UNUSED(size);
	
	if (addrs == NULL)
		return (write(1, "(nil)", 5));
	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;
	
	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;
	ind++;
	return (write_pointer(buffer, ind, length, width, flags, padd, extra_c, padd_start));
}

/**** PRINT NON PRINTABLE/FLAGS ********/
/**
 * print_non_printable - Prints ascii codes in hexadecimal of non printable chars
 * @types: List of argument to be checked
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width of the output
 * @precision: Precision specification
 * @size: Size specifier of the output
 * Return: Number of chars printed out
 */
int print_non_printable(va_list types, char buffer[],
		                int flags, int width, int precision, int size)
{
	int a = 0, offset = 0;
	char *str = va_arg(types, char *);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	
	if (str == NULL)
		return (write(1, "(null)", 6));
	
	while (str[a] != '\0')
	{
		if (is_printable(str[a]))
			buffer[a + offset] = str[a];
		else
			offset += append_hexa_code(str[a], buffer, a + offset);
		a++;
	}
	buffer[a + offset] = '\0';
	return (write(1, buffer, a + offset));
}

/***** PRINTS REVERSE ********/
/**
 * print_reverse - Prints reverse string.
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int print_reverse(va_list types, char buffer[],
		                int flags, int width, int precision, int size)
{
	char *str;
	int a, count = 0;
	
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);
	
	str = va_arg(types, char *);
	
	if (str == NULL)
	{
		UNUSED(precision);
		
		str = ")Null(";
	}
	for (a = 0; str[a]; a++)
	
	for (a = a - 1; a >= 0; a--)
	{
		char z = str[a];
		write(1, &z, 1);
		count++;
	}
	return (count);
}
/***** PRINTS A STRING IN ROT13 *********/
/**
 * print_rot13string - prints a string in rot13.
 * @types: List of arguments
 * @buffer: Buffer arrayS to handle print
 * @flags:  To calculates active flags
 * @width: get width of the output
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of characters printed
 */
int print_rot13string(va_list types, char buffer[],
		                int flags, int width, int precision, int size)
{
	char b;
	unsigned int a, j;
	char *str;
	int count = 0;
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	
	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(precision);
	UNUSED(precision);
	UNUSED(size);
	
	if (str == NULL)
		str = "(AHYY)";
	for (a = 0; str[a]; a++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[a])
			{
				b = out[j];
				write(1, &b, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			 b = str[a];
			 write(1, &b, 1);
			 count++;
		}
	}
	return (count);
}
