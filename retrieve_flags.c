#include "main.h"
/**
 * retrieve_flags - Calculates active flags
 * @format formatted string in which to print the argumenets
 * @i: a param
 * Return: flags
 */

int retrieve_flags(const char *format, int *i)
{
	int j, curl_t;
	int flags = 0;
	const char FLAGS_CHAR[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARRAY[] = {FS_MINUS, FS_PLUS, FS_ZERO, FS_HASH, FS_SPACE, 0};

	for (curl_t = *i + 1; format[curl_t] != '\0', curl_t++)
	{
		for (j = 0; FLAGS_CHAR[j] != '\0'; j++)
		{
			if (format[curl_t] == FLAGS_CHAR[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}
		}
		if (FLAG_CHAR[j] == 0)
			break;
	}

	*i = curl_t - 1;

	return (flags);
}
