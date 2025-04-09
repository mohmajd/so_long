SRC =	srcs/ft_check.c				\
		srcs/ft_exit.c				\
		srcs/ft_input.c				\
		srcs/ft_map.c				\
		srcs/ft_mlx.c				\
		srcs/ft_utils.c				\
		srcs/get_next_line.c		\
		srcs/get_next_line_utils.c	\
		srcs/ft_check2.c			\
		srcs/main.c					\

BSRC = 	bonus/ft_animation_bonus.c				\
		bonus/ft_check_bonus.c				\
		bonus/ft_exit_bonus.c				\
		bonus/ft_input_bonus.c				\
		bonus/ft_map_bonus.c				\
		bonus/ft_mlx_bonus.c				\
		bonus/ft_utils_bonus.c				\
		bonus/get_next_line_bonus.c			\
		bonus/get_next_line_utils_bonus.c	\
		bonus/ft_check2_bonus.c				\
		bonus/main_bonus.c					\

OBG = $(SRC:.c=.o)
BOBG = $(BSRC:.c=.o)

NAME = so_long
BNAME = so_long_bonus

I = -I ./includes/

L = -L ./libraries/ -lmlx_Linux -lX11 -lXext
FLAGS = -g -Wall -Wextra -Werror

all: $(NAME)
bonus: $(BNAME)

$(NAME): $(OBG)
	cc $(OBG) $(L) -o $@

$(BNAME): $(BOBG)
	cc $(BOBG) $(L) -o $@

%.o: %.c
	cc -c $(FLAGS) $(I) $^ -o $@

clean:
	rm -f $(OBG)

bclean:
	rm -f $(BOBG) $(NAME)

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
