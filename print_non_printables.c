#include "main.h"
/**
 * op_nptbl - prints non printable chars in a string
 * @vl: ...
 * Return: ...
 */
int op_nptbl(va_list vl)
{
	int i = 0, len = 0;
	char *str = va_arg(vl, char *);

	if (!str)
		str = "(null)";

	while (str[i])
	{
		if ((0 < str[i] && str[i] < 32) || 127 <= str[i])
		{
			len += (str[i] < 16) ? _printf("\\x0") : _printf("\\x");
			len += convert_base(str[i], 16, 55);
			i++;
		}
		if (!str[i])
			return (len);

		len += _putchar(str[i]);
		i++;
	}

	return (len);
}