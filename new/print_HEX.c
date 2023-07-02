#include "main.h"

/**
 * print_hex_upper - Print an unsigned integer in uppercase hexadecimal format.
 * @args: A va_list containing the unsigned integer to print.
 * @buffer: The output buffer to store the formatted string.
 * @len: The current length of the output buffer.
 *
 * Return: The number of characters printed.
 */
int print_hex_upper(va_list args, char *buffer, int len)
{
    int i = 0, j;
    char hex_digits[] = "0123456789ABCDEF";
    char hex_representation[100];
    unsigned int n = va_arg(args, unsigned int);

    if (n == 0)
    {
        buffer[len] = '0';
        return 1;
    }

    // Convert the unsigned integer to hexadecimal representation in reverse
    while (n != 0)
    {
        hex_representation[i++] = hex_digits[n % 16];
        n /= 16;
    }

    // Reverse the hexadecimal representation to get the correct format
    for (j = i - 1; j >= 0; j--)
    {
        buffer[len++] = hex_representation[j];
    }

    return i;
}
