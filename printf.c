#include "holberton.h"
/**
 * _printf - print
 * @format: char
 * Return: characters
 */
int _printf(const char *format, ...)
{
    //Declaracion de variables
    va_list list;
    unsigned int i = 0, j = 0;
    unsigned int check = 0;
    unsigned int length = 0;
    // estructura de puntero a funcion "la estructura esta declarada en el header"
	print_t print[] = {
		{"c", p_char},
		{"s", p_str},
		{"d", p_dec},
		{"i", p_int},
		{NULL, NULL}
	};
    va_start(list, format);
    while (format != NULL && format[i] != '\0')
    {
        // En este IF entra a buscar los identificadores en caso que no encuentre ninguno, imprime el contenido
        if (format[i] == '%' && format[i + 1] != '%')
        {
            j = 0;
            // Empezamos a recorrer el puntero a funciones  (printf ("%d", variable);)
            while (print[j].f != NULL)
            {
                if (format[i + 1] == print[j].print[0])
                {
                    length += print[j].f(list);
                    check = 1;
                    i++;
                }
                j++;
            }
            // Aqui se imprime el contenido en caso que no encuentre el identificador
            if (check == 0)
            {
                _putchar(format[i]);
                length += 1;
            }
        }
        // En este else if imprime doble %% en caso que sea ingresado (printf ("%%");)
        else if (format[i] == '%' && format[i + 1] == '%')
        {
            _putchar('%');
            i++;
            length += 1;
        }
        // Aqui se imprime el contenido de printf sin ningun identificador  (printf ("Hola bb");)
        else
        {
            _putchar(format[i]);
            length += 1;
        }
        i++;
    }
    va_end(list);
    // retornamos el numero de vainas impresas 
    return (length);
}
