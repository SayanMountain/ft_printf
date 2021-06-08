#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
#include "libft/libft.h"

typedef struct  s_flags
{
	char        flag;
	char        type;
	int         width;
	int         prec;
	char 		is_negative;
}               t_flags;

void        check (t_flags *res);
void        ft_putstr(char *str, int len);
void		ft_putstr(char *str, int len);
void        ft_putchar(char c, int counter);
void		ft_putchar(char c, int n);
void        ft_putnbr_hex(long long n, int fd, char type);
int         max(int a, int b);
int         min(int a, int b);
int         ft_printf_c(int c, t_flags pir);
int         ft_printf(const char *str, ...);
int         ft_printf_s(char *str, t_flags pir);
int         ft_printf_d_i(long nbr, t_flags pir);
int         ft_printf_p(long long int nbr, t_flags pir);
int         ft_printf_u(unsigned int nbr, t_flags pir);
int         ft_printf_x(unsigned int nbr, t_flags pir);
int         get_nbr_len(long long nbr, int base);
t_flags     parser(const char **str, va_list arg);

#endif
