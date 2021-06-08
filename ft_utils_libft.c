#include "ft_printf.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return (1);
	}
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

void	ft_putnbr_fd(long n, int fd)
{
	char	tiempo;

	tiempo = 0;
	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write (fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd (n / 10, fd);
	}
	tiempo = n % 10 + '0';
	if (ft_isdigit(tiempo) == 1)
		ft_putchar_fd(tiempo, fd);
}

size_t	ft_strlen(const char *s)
{
	size_t	kudrin;

	kudrin = 0;
	while (s[kudrin] != '\0')
	{
		kudrin++;
	}
	return (kudrin);
}

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
