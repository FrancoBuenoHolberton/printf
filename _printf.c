#include "holberton.h"
#include <stdarg.h>
/**
 * _printf - prints text to screen, redirects num of bytes to stdout
 * @format: character string
 * Return: int, num of bytes
 */
int _printf(const char *format, ...)
{
	va_list vl;
	int i = 0, count = 0, flag = 0;

	if (format)
	{
		va_start(vl, format);
		for (; format[i] != '\0'; i++)
		{
			if (!flag)
			{
				if (format[i] != '%')
					count += _putchar(format[i]);
				else
					flag = 1;
			}
			else
			{
				switch (format[i])
				{
				case 'c':
					count += _putchar(va_arg(vl, int));
					break;
				case 's':
					count += print_str(va_arg(vl, char *));
					break;
				case '%':
					count += _putchar('%');
					break;
				case 'd':
					count += print_int(va_arg(vl, int));
					break;
				case 'i':
					count += print_int(va_arg(vl, int));
					break;
				case '\0':
					return (-1);
				default:
					count += _putchar('%');
					count += _putchar(format[i]);
				}
				flag = 0;
			}
		}
		va_end(vl);
	}
	else
	{
		return (-1);
	}
	return (count);
}
