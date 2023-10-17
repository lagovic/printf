#include "main.h"

/**** PRINTS CHARACTERS ****/
/**
 * print_char - Prints characters
 * @types: List of Arguments
 * @buffer: Buffer array handling print
 * @flags:  Enumarates active flags
 * @width: Output width
 * @precision: Precision specification
 * @size: Size of the output specification
 * Return: number of chars printed
 */
int print_char(va_list types, char buffer[] int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);
	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/***** PRINTS STRINGS *****/
/**
 * print_string - Prints strings
 * @types: List of Arguments
 * @buffer: Buffer array handling print
 * @flags: Enunumerates flags
 * @width: Output width
 * @precision: Precision specification
 * @size: Specifies size
 * Return: number of chars printed
 */
int print_string(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int length = 0, b;
	char *str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}
	while (str[length] != '\0')
		length++;
	if (precision >= 0 && precision < length)
		length = precision;
	
	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (b = width - length; b > 0; b--)
				write(1, " ", 1);
			 return (width);
			                 }
		                else
					                {
								                        for (b = width - length; b > 0; b--)
												                                write(1, " ", 1);
											                        write(1, &str[0], length);
														return (width);
							}
	}
	return (write(1, str, length));
}
/**** PRINTS PERCENT SIGN *****/
/**
 * print_percent - Prints percent sign
 * @types: Argument list
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width of the output.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/*** PRINTS INTEGERS *******/
/**
 * print_int - Print integer
 * @types: Argument list
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width of the output.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters to print
 */
int print_int(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int b = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;
	n = convert_size_number(n, size);
	if (n == 0)
		buffer[b--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;
	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}
	
	while (num > 0)
	{
		buffer[b--] = (num % 10) + '0';
		num /= 10;
	}
	b++;
	return (write_number(is_negative, b, buffer, flags, width, precision, size));
}
