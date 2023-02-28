DEPS = ft_fdf.h
EXUT = exut_fdf
EXUT_BONUS = exut_fdf_bonus
CC = cc
FLAG = -Wall -Wextra -Werror -fsanitize=address
MLX = -lmlx -framework OpenGL -framework AppKit
FDF = ./fdf_util/evant_m.c fdf.c
BONUS = ./fdf_util/evant.c fdf_bonus.c
SRC = ./fdf_util/baffering_map.c ./fdf_util/check_map.c  ./fdf_util/ft_fdf_utile.c ./fdf_util/ft_len_win.c \
		./fdf_util/ft_line.c ./fdf_util/open_mlx_win.c ./fdf_util/ft_atoi_base.c ./fdf_util/ft_split_line.c \
		./fdf_util/ft_rgb.c ./fdf_util/ft_hook.c
OBJ = $(SRC:.c=.o)
OBJ_FDF = $(FDF:.c=.o)
OBJ_BONUS = $(BONUS:.c=.o)


all		: util $(EXUT)

bonus	: util $(EXUT_BONUS)

$(EXUT) : $(OBJ) $(OBJ_FDF)
	$(CC) $(FLAG) $(OBJ) $(OBJ_FDF) -lm ./fdf_util/*/*.a $(MLX) -o $(EXUT)

$(EXUT_BONUS) : $(OBJ) $(OBJ_BONUS)
	$(CC) $(FLAG) $(OBJ) $(OBJ_BONUS) -lm ./fdf_util/*/*.a $(MLX) -o $(EXUT_BONUS)

%.o: %.c
	@${CC} ${FLAG} -c $< -o $@

util	:
	@make -C ./fdf_util/get_next_line
	@make -C ./fdf_util/libft
	@make -C ./fdf_util/printf


clean	:
	@rm -f *.o
	@rm -rf fdf_util/*.o
	@make -C ./fdf_util/get_next_line clean
	@make -C ./fdf_util/libft clean
	@make -C ./fdf_util/printf clean

fclean	:
	@rm -rf *.o $(EXUT) $(EXUT_BONUS)
	@rm -rf fdf_util/*.o
	@make -C ./fdf_util/get_next_line fclean
	@make -C ./fdf_util/libft fclean
	@make -C ./fdf_util/printf fclean

re		: fclean all