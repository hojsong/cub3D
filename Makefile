# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoslim <hoslim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 20:01:46 by hoslim            #+#    #+#              #
#    Updated: 2023/03/28 17:05:28 by hoslim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
SRCS = \
		srcs/parse/get_next_line_utils.c\
		srcs/parse/get_next_line.c\
		srcs/parse/hj_parsing.c\
		srcs/parse/hj_parsing_player.c\
		srcs/parse/hj_check_map.c\
		srcs/parse/hj_check_map2.c\
		srcs/parse/hj_util.c\
		srcs/parse/hj_util2.c\
		srcs/parse/hj_util3.c\
		srcs/parse/ft_split.c\
		srcs/parse/map_dfs.c\
		srcs/main.c\
		srcs/ft_util.c\
		srcs/init.c\
		srcs/utils.c\
		srcs/util_free.c\
		srcs/render.c\
		srcs/key.c\
		srcs/key2.c\
		srcs/ray.c\
		srcs/draw.c\
		srcs/draw2.c\
		srcs/ray_cal.c\
		srcs/update.c

HEADER = ./includes
OBJS = $(SRCS:.c=.o)

CC = cc
FLAGS = -Wall -Werror -Wextra
MLX_NAME = mlx
MLX_DIR = ./mlx
MLX = $(addprefix $(MLX_DIR)/, libmlx.a)
CLIB = -Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx

all : $(NAME)

%.o : %.c
	@echo "compliling srcs files...!"
	$(CC) $(FLAGS) -I $(HEADER) -I $(MLX_DIR) -c $< -o $@

$(NAME) : $(OBJS) $(HEADER)
	@echo "making mlx"
	$(MAKE) -C $(MLX_DIR) all
	@echo "compliling cub3D ...!"
	$(CC) $(FLAGS) -L$(MLX_DIR) -l$(MLX_NAME) $(CLIB) -o $(NAME) $(OBJS)

clean :
	@echo "Clean object files..."
	rm -rf srcs/*.o srcs/parse/*.o mlx/*.o

fclean : clean
	@echo "Clean and remove cub3D & mlx.a..."
	rm -rf $(NAME) ./mlx/libmlx.a

re : fclean all
	@echo "Remaking cub3D"

.PHONY : all re clean fclean