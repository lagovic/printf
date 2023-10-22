#include "main.h"
/************ Prints unsigned number(Binary) **********/
/**
 * print_binary - Prints an unsigned number
 * @types: Argument list
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: To get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of characters to print.
 */
int print_binary(va_list types, char buffer[],
                int flags, int width, int precision, int size)
{
        unsigned int p, m, b, sum;
        unsigned int a[32];
        int count;

        UNUSED(buffer);
        UNUSED(flags);
        UNUSED(width);
        UNUSED(precision);
        UNUSED(size);

        p = va_arg(types, unsigned int);
        m = 2147483648; /* (2 ^ 31) */
        a[0] = p / m;
        for (b = 1; b < 32; b++)
        {
                m /= 2;
                a[b] = (p / m) % 2;
        }
        for (b = 0, sum = 0, count = 0; b < 32; b++)
        {
                sum += a[b];
                if (sum || b == 31)
                {
                        char z = '0' + a[b];

                        write(1, &z, 1);
                        count++;
                }
		 }
        return (count);
}
