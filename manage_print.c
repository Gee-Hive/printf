#include "main.h"
/**
 * handle_print - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int handle_print(const char *fmt, int *i, va_list lists, char buffer[], int flags, int width, int precision, int size)
{
	int index, unknown_length = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	
	for (index = 0; fmt_types[index].fmt != '\0'; index++)
		if (fmt[*i] == fmt_types[index].fmt)
			return (fmt_types[index].fn(lists, buffer, flags, width, precision, size));
	if (fmt_types[index].fmt == '\0')
	{
		if (fmt[*i] == '\0')
			return (-1);
		unknown_length += write(1, "%%", 1);
		
		if (fmt[*i - 1] == ' ')
			unknown_length += write(1, " ", 1);
		else if (width)
		{
			--(*i);
			while (fmt[*i] != ' ' && fmt[*i] != '%')
				--(*i);
			if (fmt[*i] == ' ')
				--(*i);
			return (1);
		}
		unknown_length += _putcharr(fmt[*i]);
		return (unknown_length);
	}
	return (printed_chars);
}
