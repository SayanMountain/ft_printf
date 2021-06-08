#include "ft_printf.h"

int	ft_printf_c(int c, t_flags pir)
{
	int		res;
	char	c_str[2];

	res = 0;
	if (c == 0)
	{
		pir.width--;
		if (pir.flag == '-')
			write (1, &c, 1);
	}
	c_str[0] = (char) c;
	c_str[1] = 0;
	res = ft_printf_s(c_str, pir);
	if (c == 0)
	{
		if (pir.flag != '-')
			write(1, &c, 1);
		res++;
	}
	return (res);
}
