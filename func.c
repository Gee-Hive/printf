#include "main.h"

/*to print char */

/**
 * print_char - prints a char
 * @types: list arguments
 * @buffer: arrays to handle print
 * @flags: calculates active flags
 * @width: calculates the width
 * @precision: precision
 * @size: size specifier
 * Return: Number of chars printed
 */

int print_char(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/*
 * print_string - prints a string
 * @types: list of arguments
 * @buffer: arrays to handle print
 * @flags: calculates active flags
 * @width: calculates the width
 * @precision: precision
 * @size: size specifier
 * Return: Number of string printed
 */

int print_string(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int length = 0, i;
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
		if (flags & FS_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}
	return (write(1, str, length));
}

/**
 * print_percent - Prints a percent sign
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
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
/**
 * print_int - Print int
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int i = BUFFER_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int numbre;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '\0';
	buffer[BUFFER_SIZE - 1] = '\0';
	numbre = (unsigned long int)n;

	if (n < 0)
	{
		numbre = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (numbre > 0)
	{
		buffer[i--] = (numbre % 10) + '0';
		numbre /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

/**
 * print_binary - Prints an unsigned number
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	unsigned int n, m, o, sum;
	unsigned int a[32];
	int counter;
	char z;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648;
	a[0] = n / m;
	for (o = 1; o < 32; o++)
	{
		m /= 2;
		a[o] = (n / m) % 2;
	}
	for (o = 0, sum = 0, counter = 0; o < 32; o++)
	{
		sum += a[o];
		if (sum || o == 31)
		{
			z = '0' + a[o];
			_putcharr(z);
			counter++;
		}
	}
	return (counter);
}
