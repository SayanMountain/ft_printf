#include "ft_printf.h"

char	get_hex_chr(int nbr, char type)
{
	if (nbr <= 9 && nbr >= 0)
		return (nbr + '0');
	nbr %= 10;
	if (type == 'X')
		return ('A' + nbr);
	else
		return ('a' + nbr);
}

void	ft_putnbr_hex(long long n, int fd, char type)
{
	char	tiempo;

	tiempo = 0;
	if (n >= 16)
	{
		ft_putnbr_hex(n / 16, fd, type);
	}
	tiempo = get_hex_chr(n % 16, type);
	if (ft_isdigit(tiempo) == 1)
		ft_putchar(tiempo, fd);
	else if (ft_isalpha(tiempo) == 1)
		ft_putchar(tiempo, fd);
}

int	get_nbr_len(long long nbr, int base)
{
	long long	len;

	len = 0;
	if (nbr < 0)
		nbr *= -1;
	if (nbr == 0)
		len++;
	while (nbr > 0)
	{
		nbr /= base;
		len++;
	}
	return (len);
}
