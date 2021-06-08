#include "ft_printf.h"

int	flag_minus(long nbr, t_flags pir, int nbr_len, char fill)
{
	if (nbr < 0 && (fill == '0' || pir.prec >= pir.width))
	{
		ft_putchar('-', 1);
		nbr *= -1;
	}
	if (pir.width > max(pir.prec, nbr_len))
		ft_putchar(fill, pir.width - max(pir.prec, nbr_len) - pir.is_negative);
	if (nbr < 0 && (fill == '0' || (pir.prec <= pir.width && pir.prec != -1)))
	{ч
		ft_putchar('-', 1);
		nbr *= -1;
	}
	if (pir.prec > nbr_len)
		ft_putchar('0', pir.prec - nbr_len);
	ft_putnbr_fd(nbr, 1);
	return (0);
}

int	flag_plus (long nbr, t_flags pir, int nbr_len, char fill)
{
	if (nbr < 0)
	{
		ft_putchar('-', 1);
		nbr *= -1;
		pir.width--;
	}
	if (pir.prec > nbr_len)
		ft_putchar('0', pir.prec - nbr_len);
	ft_putnbr_fd(nbr, 1);
	if (pir.width > max(pir.prec, nbr_len))
		ft_putchar(fill, pir.width - max(pir.prec, nbr_len));
	return (0);
}

int	ft_printf_d_i(long nbr, t_flags pir)
{
	int		nbr_len;
	char	fill;
	int		res;

	nbr_len = get_nbr_len(nbr, 10);
	pir.is_negative = 0;
	if (nbr == 0 && pir.prec == 0)
	{
		ft_putchar(' ', pir.width);
		return (pir.width);
	}
	if (nbr < 0)
		pir.is_negative = 1;
	res = max(pir.width, max(pir.prec + pir.is_negative, \
	nbr_len + pir.is_negative));
	fill = ' ';
	if (pir.flag == '0' && pir.prec == -1)
		fill = '0';
	if (pir.flag == '-')
		flag_plus (nbr, pir, nbr_len, fill);
	else
		flag_minus (nbr, pir, nbr_len, fill);
	return (res);
}
