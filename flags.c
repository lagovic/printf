#include "main.h"
/**
 * get_flags - function calculating active flags
 * @format: string format to print arguments
 * @i: first parameter.
 * Return: Flags if it exists
 */
int get_flags(const char *format, int *i)
{
	int b, c;
	int flag = 0;
	const char FLAGS_CHA[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARRY[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};
	for (c = *i + 1; format[c] != '\0'; c++)
	{
	       for (b = 0; FLAGS_CHA[b] != '\0'; b++)
		       if (format[c] == FLAGS_CHA[b])
		       {
			       
			       flag |= FLAGS_ARRY[b];
			       break;
		       }
	       if (FLAGS_CHA[b] == 0)
		       break;
	}
	*i = c - 1;
	return (flag);
}
