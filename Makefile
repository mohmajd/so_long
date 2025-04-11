SRC =	srcs/ft_checkmap.c				\
		srcs/ft_exit.c				\
		srcs/ft_input.c				\
		srcs/ft_map.c				\
		srcs/ft_mlx.c				\
		srcs/ft_utils.c				\
		srcs/get_next_line.c		\
		srcs/get_next_line_utils.c	\
		srcs/ft_check2.c			\
		srcs/main.c					\

OBG = $(SRC:.c=.o)
BOBG = $(BSRC:.c=.o)

NAME = so_long

I = -I ./includes/

L = -L ./libraries/ -lmlx_Linux -lX11 -lXext
FLAGS = -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBG)
	cc $(OBG) $(L) -o $@

%.o: %.c
	cc -c $(FLAGS) $(I) $^ -o $@

clean:
	rm -f $(OBG)

fclean: bclean clean
	rm -f $(NAME) $(BNAME)

re: clean all

.PHONEY: clean mlx

mlx:
	rm -fr minilibx-linux
	tar -xvzf minilibx-linux.tgz
	cd minilibx-linux && make
	cd ..
	mv minilibx-linux/libmlx_Linux.a .
	cp minilibx-linux/mlx.h ./includes/.
	rm -fr minilibx-linux
lldb:
	clang -g -I ./includes/ srcs/*.c -L ./ -lmlx_Linux -lX11 -lXext -o debugProg
