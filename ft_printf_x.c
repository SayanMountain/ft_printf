#include "ft_printf.h"

int	x_help_flag_minus(unsigned int nbr, t_flags pir, int nbr_len, char fill)
{
	if (pir.prec == 0 && nbr == 0)
	{
		ft_putchar(' ', pir.width);
		return (0);
	}
	else if (pir.flag == '-')
	{
		if (pir.prec > nbr_len)
			ft_putchar('0', pir.prec - nbr_len);
		ft_putnbr_hex(nbr, 1, pir.type);
		if (pir.width > max(pir.prec, nbr_len))
			ft_putchar(fill, pir.width - max(pir.prec, nbr_len));
	}
	else
	{
		if (pir.width > max(pir.prec, nbr_len))
			ft_putchar(fill, pir.width - max(pir.prec, nbr_len));
		if (pir.prec > nbr_len)
			ft_putchar('0', pir.prec - nbr_len);
		ft_putnbr_hex(nbr, 1, pir.type);
	}
	return (0);
}

int	ft_printf_x(unsigned int nbr, t_flags pir)
{
	int		res;
	int		nbr_len;
	char	fill;

	nbr_len = get_nbr_len(nbr, 16);
	res = max(pir.width, max(pir.prec, nbr_len));
	if (pir.width == 0 && pir.prec == 0 && nbr == 0)
		res = 0;
	fill = ' ';
	if (pir.flag == '0' && pir.prec == -1)
		fill = '0';
	x_help_flag_minus (nbr, pir, nbr_len, fill);
	return (res);
}
