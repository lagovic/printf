#include "main.h"
/***********Function to print unsigned number********/
/**
 * print_unsigned - Function to print an unsigned number
 * @types: Argument list
 * @buffer: Buffer array to be printed
 * @flags: Calculates active flags if they exist
 * @width: get width of the number
 * @precision: Precision specification
 * @size: Size specifier of the number
 * Return: Number of chars printed on the console
 */
int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int b = BUFF_SIZE - 2;
	unsigned long int num1 = va_arg(types, unsigned long int);

	num1 = convert_size_unsgnd(num1, size);

	if (num1 == 0)
		buffer[b--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num1 > 0)
	{
		buffer[b--] = (num1 % 10) + '0';
		num1 /= 10;
	}

	b++;

	return (write_unsgnd(0, b, buffer, flags, width, precision, size));
}

/***********Function to print unsigned number in octal ************/
/**
 * print_octal - Prints an unsigned number in octal notation
 * @types: Argument list
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flag and returns it
 * @width: Display width of the output
 * @precision: Precision specification
 * @size: Specifies the size
 * Return: Number of characters to be printed
 */
int print_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{

	int b = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[b--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[b--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[b--] = '0';

	b++;

	return (write_unsgnd(0, b, buffer, flags, width, precision, size));
}

/**************Function to print unsigned number in hexadecimal **************/
/**
 * print_hexadecimal - Function prints an unsigned number in hexadecimal notation
 * @types: Argument lists
 * @buffer: Buffer array to handle the printout
 * @flags:  Calculates active flags and returns it
 * @width: Display width of the output
 * @precision: Precision specification
 * @size: Specifies the size
 * Return: Number of characters printed out
 */
int print_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
				flags, 'x', width, precision, size));
}

/*************Function print unsigned number in upper hexadecimal **************/
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: Argument list
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Display width of the output
 * @precision: Precision specification
 * @size: Specifies the size
 * Return: Number of chars printed out
 */
int print_hexa_upper(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
				flags, 'X', width, precision, size));
}

/**************Function prints hexx num in lower or upper **************/
/**
 * print_hexa - Function to prints a hexadecimal number in lower or upper case
 * @types: List of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: Display width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of characters printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
		int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
