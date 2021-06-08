#include "ft_printf.h"

int	p_help_flag_minus(int nbr_len, unsigned long nbr, char fill, t_flags pir)
{
	write(1, "0x", 2);
	if (pir.prec > nbr_len)
		ft_putchar('0', pir.prec - nbr_len + 2);
	if (!(pir.prec == 0 && nbr == 0))
		ft_putnbr_hex(nbr, 1, pir.type);
	if (pir.width > max(pir.prec, nbr_len))
		ft_putchar(fill, pir.width - max(pir.prec + 2, nbr_len));
	return (0);
}

int	p_help_flag_plus(int nbr_len, unsigned long nbr, char fill, t_flags pir)
{
	if (fill == '0')
	{
		write(1, "0x", 2);
	}
	if (pir.width > max(pir.prec, nbr_len))
		ft_putchar(fill, pir.width - max(pir.prec + 2, nbr_len));
	if (fill != '0')
	{
		write(1, "0x", 2);
	}
	if (pir.prec > nbr_len)
		ft_putchar('0', pir.prec - nbr_len + 2);
	if (!(pir.prec == 0 && nbr == 0))
		ft_putnbr_hex(nbr, 1, pir.type);
	return (0);
}

int	ft_printf_p(long long int nbr, t_flags pir)
{
	int		nbr_len;
	int		res;
	char	fill;

	if (!(pir.prec == 0 && nbr == 0))
		nbr_len = get_nbr_len(nbr, 16) + 2;
	else
		nbr_len = 2;
	res = max(pir.width, max(pir.prec + 2, nbr_len));
	fill = ' ';
	if (pir.flag == '0' && pir.prec == -1)
		fill = '0';
	if (pir.flag == '-')
		p_help_flag_minus (nbr_len, nbr, fill, pir);
	else
		p_help_flag_plus (nbr_len, nbr, fill, pir);
	return (res);
}
