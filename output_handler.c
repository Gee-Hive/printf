#include "main.h"

/**
 * handle_write_char - prints a string
 * @c: the char type
 * @buffer: buffer: buffer array to handles print
 * @flags: calculates active flags
 * @width: get width
 * @precision: precision specifier
 * @size: size specifier
 * Return: Number of chars to be printed
 */

int handle_write_char(char c, char buffer[], int flags, int width, int precision, int size)
{
	int i = 0;
	char pad = '';

	UNUSED(precision);
	UNUSED(size);

	if (flags & FS_ZERO)
		pad = '0';
	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFFER_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFFER_SIZE - i - 2] = pad;
		if (flags & FS_MINUS)
			return(write(1, &buffer[0], 1) + write(1, &buffer[BUFFER_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFFER_SIZE - i - 1], width - 1) + write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}

/**
 * write_number - Prints a string
 * @is_negative: Lista of arguments
 * @ind: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int write_number(int is_negative, int index, char buffer[], int flags, int width, int precision, int size)
{
	int length = BUFFER_SIZE - index -1;
	char pad = "", extra_ch = 0;

	UNUSED(size);

	if ((flags & FS_ZERO) && !(flags & FS_MINUS))
		pad = '\0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & FS_PLUS)
		extra_ch = '+';
	else if (flags & FS_SPACE)
		extra_ch = '';

	return (write_num(index, buffer, flags, width, precision, length, pad, extra_ch));
}

/**
 * write_num - Write a number using a bufffer
 * @ind: Index at which the number starts on the buffer
 * @buffer: Buffer
 * @flags: Flags
 * @width: width
 * @prec: Precision specifier
 * @length: Number length
 * @padd: Pading char
 * @extra_c: Extra char
 *
 * Return: Number of printed chars.
 */

int write_num(int index, char buffer[], int flags, int width, int precision, int length, char pad, char extra_c)
{
	int i, pad_start = 1;

	if (precision == 0 && index == BUFFER_SIZE - 2 && buffer[index] == '0' && width == 0)
		return (0);
	if (precision == 0 && index == BUFFER_SIZE - 2 && buffer[index] == '0')
		buffer[index] = pad = '';
	if (precision > 0 && precision < length)
		pad = '';
	while (precision > length)
		buffer[--index] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = pad;
		buffer[i] = '\0';
		if (flags & FS_MINUS && pad == '')
		{
			if (extra_c)
				buffer[--index] =  extra_c;
			return (write(1, &buffer[index], length) + write(1, &buffer[1], i - 1))
		}
		else if (!(flags & FS_MINUS) && pad == '')
		{
			if (extra_c)
				buffer[--index] = extra_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[index], length));
		}
		else if (!(flags & FS_MINUS) && pad == '0')
		{
			if (extra_c)
				buffer[--pad_start] = extra_c;
			return (write(1, &buffer[pad_start], i - pad_start) + write(1, &buffer[index], length - (1 - pad_start)));
		}
	}
	if (extra_c)
		buffer[--index] = extra_c;
	
	return (write(1, &buffer[index], length));
}
