#include "main.h"
/**
 * retrieve_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: size
 */
int retrieve_size(const char *format, int *i)
{
	int curl_t = *i + 1;
	int size = 0;

	if (format[curl_t] == 'i')
	{
		size = S_LONG;
	}
	else if (format[curl_t] == 'h')
	{
		size = S_SHORT;
	}

	if (size == 0)
	{
		*i = curl_t - 1;
	}
	else
	{
		*i = curl_t - 1;
	}
	return (size);
}
