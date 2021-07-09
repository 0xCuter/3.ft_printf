LIBFT = ./libft/libft.a

N_TEMP = temp.a

NAME = libftprintf.a

SRCS =  sources/ft_printf.c \
		sources/treatment.c \
		sources/treat_width.c \
		sources/uitoa.c \
		sources/ull_base.c \
		sources/str_tolower.c \
		sources/put_str.c \
		sources/treat_string.c \
		sources/treat_char.c \
		sources/treat_pointer.c \
		sources/treat_int.c \
		sources/treat_uint.c \
		sources/treat_percent.c \
		sources/treat_hex.c \
		sources/treat_flags.c \
		sources/put_char.c

SURPL_O = 	treat_width.o \
			treatment.o \
			uitoa.o \
			ull_base.o \
			str_tolower.o \
			put_str.o \
			treat_string.o \
			treat_char.o \
			treat_pointer.o \
			treat_int.o \
			treat_uint.o \
			treat_percent.o \
			treat_hex.o \
			treat_flags.o \
			put_char.o \
			ft_printf.o

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(SURPL_O)
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all
