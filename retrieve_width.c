#include "main.h"
/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */

int retrieve_width(const char *format, int *i, va_list lists)
{
	int curl_t;
	int breadth = 0;

	for (curl_t = *i + 1; format[curl_t] != '\0'; curl_t++)
	{
		if (is_digits(format[curl_t]))
		{
			breadth *= 10;
			breadth += format[curl_t] - '0';
		}
		else if (format[curl_t] == '*')
		{
			curl_t++;
			breadth = va_arg(lists, int);
			break;
		}
		else
			break;
	}
	*i = curl_t - 1;
	return (breadth);
}
