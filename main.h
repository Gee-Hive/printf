#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFFER_SIZE 1024

/* FLAGS */
#define FS_MINUS 1
#define FS_PLUS 2
#define FS_ZERO 4
#define FS_HASH 8
#define FS_SPACE 16

/*sizes */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - struct op
 * @fmt: The format
 * @fn: function associated
 */

struct fmt
{
	char fmt;
	int (*fn)(va_list[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format
 * @fmt_t: function assocaited.
 */

typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i, va_list lists, char buffer[], int flags, int width, int precision, int size);

/*functions for printing chars and strings */
int print_char(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[], int flags, int width, int precision, int size);

/*functions for printing number*/
int print_binary(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_int(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_hexa(va_list types, char map[], char buffer[], int flags, char flag_ch, int width, int precision, int size);
int print_hexa_toUpper(va_list types, char buffer[], int flags, int width, int precision, int size);

/* width handlers */
int write_unsgnd(int is_negative, int index, char buffer[], int flags, int width, int precision, int size);
int handle_write_char(char c, char buffer[], int flags, int width, int precision, int size);
int write_number(int is_positive, int index, char buffer[], int flags, int width, int precision, int size);
int write_pointer(char buffer[], int index, int len, int width, int flags, char pad, char extra_c, int pad_start);
int write_num(int index, char buffer[], int flags, int width, int precision, int length, char pad, char extra_c);

/* functions for printing memory address */
int print_pointer(va_list types, char buffer[], int flags, int width, int precision, int size);

/* functions for handling some other specifiers */
int retrieve_flags(const char *format, int *i);
int retrieve_width(const char *format, int *i, va_list lists);
int retrieve_precision(const char *format, int *i, va_list lists);
int retrieve_size(const char *format, int *i);

/* utils */
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digits(char);
int is_printable(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsigned(unsigned long int num, int size);


#endif
