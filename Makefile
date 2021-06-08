NAME		= libftprintf.a
SRCS		= ft_printf.c ft_parser.c ft_printf_d_i.c ft_printf_x.c ft_utils_hex.c\
 				ft_printf_s.c ft_printf_u.c ft_printf_c.c ft_printf_p.c ft_utils_help.c
HEADERS		= ft_printf.h
LIBFT		= g
OBJS		= $(SRCS:.c=.o)
FLAGS		= -Wall -Wextra -Werror
PROJDIR		= $(dir $(CURDIR))
LIBFTMAKE	= $(MAKE) -C libft/
CC			= gcc

all: $(NAME)

%.o: %.c ft_printf.h
	$(CC) $(FLAGS) -c $<

(%.o): %.o
	ar rc $@ $<

$(LIBFT):
	${LIBFTMAKE} printf

$(NAME): $(HEADERS) $(OBJS) $(NAME)($(OBJS)) $(LIBFT)

clean:
	rm -f  $(OBJS)
	$(LIBFTMAKE) clean

fclean:
	rm -f $(NAME) $(OBJS)
	$(LIBFTMAKE) fclean

re: fclean all
.PHONY:    all clean fclean re
