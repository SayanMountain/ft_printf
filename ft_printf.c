#include "ft_printf.h"

int	ft_printf_help(t_flags pir, va_list ap)
{
	int	result;

	result = 0;
	if (pir.type == 'd' || pir.type == 'i')
		result += ft_printf_d_i(va_arg(ap, int), pir);
	if (pir.type == 'x' || pir.type == 'X')
		result += ft_printf_x (va_arg(ap, unsigned int), pir);
	if (pir.type == 's')
		result += ft_printf_s(va_arg(ap, char *), pir);
	if (pir.type == 'u')
		result += ft_printf_u(va_arg(ap, unsigned int), pir);
	if (pir.type == 'c')
		result += ft_printf_c(va_arg(ap, int), pir);
	if (pir.type == '%')
		result += ft_printf_c(pir.type, pir);
	if (pir.type == 'p')
		result += ft_printf_p(va_arg(ap, unsigned long), pir);
	return (result);
}

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	t_flags		pir;
	int			result;

	result = 0;
	va_start(ap, str);
	while (*str != '\0')
	{
		if (*str == '%' && *(str + 1) != '%')
		{
			str++;
			pir = parser(&(str), ap);
			result += ft_printf_help(pir, ap);
		}
		else
		{
			if (*str == '%' && *(str + 1) == '%')
				str++;
			ft_putchar(*str, 1);
			result++;
		}
		str += *str != '\0';
	}
	va_end(ap);
	return (result);
}
