#include "ft_printf.h"

int	u_help_flag(int nbr_len, char fill, unsigned int nbr, t_flags pir)
{
	if (pir.flag == '-')
	{
		if (pir.prec > nbr_len)
			ft_putchar('0', pir.prec - nbr_len);
		if (!(pir.prec == 0 && nbr == 0))
			ft_putnbr_fd(nbr, 1);
		if (pir.width > max(pir.prec, nbr_len))
			ft_putchar(fill, pir.width - max(pir.prec, nbr_len));
	}
	else
	{
		if (pir.width > max(pir.prec, nbr_len))
			ft_putchar(fill, pir.width - max(pir.prec, nbr_len));
		if (pir.prec > nbr_len)
			ft_putchar('0', pir.prec - nbr_len);
		if (!(pir.prec == 0 && nbr == 0))
			ft_putnbr_fd(nbr, 1);
	}
	return (0);
}

int	ft_printf_u(unsigned int nbr, t_flags pir)
{
	int		res;
	int		nbr_len;
	char	fill;

	if (!(pir.prec == 0 && nbr == 0))
		nbr_len = get_nbr_len(nbr, 10);
	else
		nbr_len = 0;
	res = max(pir.width, max(pir.prec, nbr_len));
	if (pir.width == 0 && pir.prec == 0 && nbr == 0)
		res = 0;
	fill = ' ';
	if (pir.flag == '0' && pir.prec == -1)
		fill = '0';
	u_help_flag(nbr_len, fill, nbr, pir);
	return (res);
}
