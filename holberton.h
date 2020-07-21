#ifndef HOLBY
#define HOLBY

#include <stdarg.h>
#include <stdlib.h>
/**
 * struct print - struct
 * @print: identificador
 * @f: function pointer.
 */
typedef struct print
{
	char *print;
	int (*f)();
} print_t;

int _printf(const char *format, ...);
int p_char(va_list list);
int p_str(va_list list);

int p_dec(va_list list);
int p_int(va_list list);

int p_bin(va_list list);

int _putchar(char c);
#endif
