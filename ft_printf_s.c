#include "ft_printf.h"

int	s_help_flag_minus (char *str, char fill, int len, t_flags pir)
{
	if (pir.flag == '-')
	{
		ft_putstr(str, len);
		if (pir.width > len)
			ft_putchar(fill, pir.width - len);
	}
	else
	{
		if (pir.width > len)
			ft_putchar(fill, pir.width - len);
		ft_putstr(str, len);
	}
	return (0);
}

int	ft_printf_s(char *str, t_flags pir)
{
	int		len;
	int		res;
	char	fill;

	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	fill = ' ';
	if (pir.flag == '0' && pir.prec == -1)
		fill = '0';
	if (pir.prec != -1 && pir.prec < len)
		len = pir.prec;
	if (pir.prec != -1)
		res = max(pir.width, min(pir.prec, len));
	else
		res = max(pir.width, len);
	s_help_flag_minus(str, fill, len, pir);
	return (res);
}
