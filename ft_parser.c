#include "ft_printf.h"

void	check(t_flags *res)
{
	if ((*res).width < 0)
	{
		(*res).flag = '-';
		(*res).width *= -1;
	}
	if ((*res).prec < 0)
		(*res).prec = -1;
}

void	zero_minus(const char **str, va_list arg, t_flags *res)
{
	while (**str == '0' || **str == '-')
	{
		if (res->flag != 0 && res->flag == '-' && **str == '0')
		{
			(*str)++;
			continue ;
		}
		res->flag = **str;
		(*str)++;
	}
	while ((**str >= '0' && **str <= '9') || **str == '*')
	{
		if (**str == '*')
		{
			res->width = va_arg(arg, int);
			(*str)++;
			break ;
		}
		else
			res->width = res->width * 10 + (**str - '0');
		(*str)++;
	}
}

void	precision(va_list arg, t_flags *res, const char **str)
{
	res->prec = 0;
	(*str)++;
	while ((**str >= '0' && **str <= '9') || **str == '*')
	{
		if (**str == '*')
		{
			res->prec = va_arg(arg, int);
			(*str)++;
			break ;
		}
		else
			res->prec = res->prec * 10 + (**str - '0');
		(*str)++;
	}
}

t_flags	parser(const char **str, va_list arg)
{
	t_flags	res;

	res.flag = 0;
	res.prec = -1;
	res.width = 0;
	zero_minus(str, arg, &res);
	if (**str == '.')
		precision(arg, &res, str);
	res.type = **str;
	check(&res);
	return (res);
}
