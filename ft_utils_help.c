#include "ft_printf.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

void	ft_putstr(char *str, int len)
{
	while (*str != '\0' && len > 0)
	{
		ft_putchar(*str, 1);
		str++;
		len--;
	}
}

void	ft_putchar(char c, int n)
{
	while (n--)
		write(1, &c, 1);
}
