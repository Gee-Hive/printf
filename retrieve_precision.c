#include "main.h"

/**
 * retrieve_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */

int retrieve_precision(const char *format, int *i, va_list lists)
{
	int curl_t = *i + 1;
	int precision = -1;

	if (format[curl_t] != '.')
		return (precision);

	precision = 0;

	for (curl_t += 1; format[curl_t] != '\0'; curl_t++)
	{
		if (is_digits(format[curl_t]))
		{
			precision *= 10;
			precision += format[curl_t] - '\0';
		}
		else if (format[curl_t] == '*')
		{
			curl_t++;
			precision = va_arg(lists, int);
			break;
		}
		else
			break;
	}
	*i = curl_t - 1;
	return (precision);
}
