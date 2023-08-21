#include "main.h"
/**
 * print_pointer - Prints the value of a pointer variable
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */

int print_pointer(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	char extra_ch = 0, padding = '';
	int index = BUFFER_SIZE - 2, length = 2, padding_start = 1;
	unsigned long number_address;
	char map[] = "0123456789abcdef";
	void *address = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (address == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFFER_SIZE - 1] = '\0';

	UNUSED(precision);

	number_address = (unsigned long)address;

	while (number_address > 0)
	{
		buffer[index--] = map[number_address % 16];
		number_address /= 16;
		length++;
	}

	if ((flags & FS_ZERO) && !(flags & FS_MINUS))
		padding = '0';
	if (flags & FS_PLUS)
		extra_ch = '+', length++;
	else if (flags & FS_SPACE)
		extra_ch = '', length++;

	index++;

	return (write_pointer(buffer, index, length, width, flags, padding, extra_ch, padding_start));
}

/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_non_printable(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int i = 0, off_set = 0;
	char *s = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (s == NULL)
		return (write(1, "(null)", 6));

	while (s[i] != '\0')
	{
		if (is_printable(s[i]))
			buffer[i + off_set] = s[i];
		else
			off_set += append_hexa_code(s[i], buffer, i + off_set);
		i++;
	}

	buffer[i + off_set] = '\0';

	return (write(1, buffer, i + off_set));
}

/**
 * print_reverse - Prints reverse string.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int print_reverse(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	char *s;
	int i, counter = 0;
	char z;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	s = va_arg(types, char *);

	if (s == NULL)
	{
		UNUSED(precision);
		s = ")Null(";
	}
	for (i = 0; s[i]; i++)
		;
	for (i = i - 1; i >= 0; i--)
	{
		z = s[i];

		write(1, &z, 1);
		counter++;
	}
	return (counter);
}

/**
 * print_rot13string - Print a string in rot13.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int print_rot13string(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	char x;
	char *s;
	unsigned int i, j;
	int count = 0;
	char in_side[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out_side[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	s = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (s == NULL)
		s = "(AHYY)";
	for (i = 0; s[i]; i++)
	{
		for (j = 0; in_side[j]; j++)
		{
			if (in_side[j] == s[i])
			{
				x = out_side[i];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in_side[j])
		{
			x = s[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
