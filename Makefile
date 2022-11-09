# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iharile <iharile@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 14:12:07 by iharile           #+#    #+#              #
#    Updated: 2022/11/09 17:01:18 by iharile          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = ""
p = parser
e = executer
NAME = cub3D
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address
MLX = -lmlx -framework OpenGl -framework AppKit
SRC = main.c $(p)/files_error.c $(p)/valid_map.c $(p)/my_atoi.c \
	$(p)/handle_objects.c $(p)/free.c $(p)/norm1.c $(p)/counter.c $(p)/land_content.c\
	$(p)/taken_by_struct.c $(p)/copy.c $(p)/dfs.c $(p)/hex.c $(p)/texture.c \
	$(p)/player_surrounded.c \
	$(e)/execute.c $(e)/walls.c $(e)/textures.c $(e)/rotation.c $(e)/execute_utils.c $(e)/movement.c
OBJ = $(SRC:.c=.o)
MSG_LIB = @echo "\033[0;33mpreparing libft\033[0m"
MSG_CUB =  @echo "\033[0;33mpreparing cub3d\033[0m"
MSG_DESTROY = @echo "\033[0;31mObjects is destroyed\033[0m"

all: $(EXEC) $(NAME)

$(EXEC):
	$(MSG_LIB)
	@make -s -C libft
	$(MSG_CUB)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(MLX) libft/*.o $(OBJ) -o $(NAME)

clean :
	$(MSG_DESTROY)
	@rm -rf $(OBJ)
	@rm -rf libft/*.o

fclean : clean
	@rm -rf $(NAME)
	@rm -rf libft/libft.a

re : fclean all

.SILENT: $(OBJ) $(NAME)