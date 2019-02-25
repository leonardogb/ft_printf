# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: lgarcia- <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/01/25 19:10:56 by lgarcia-     #+#   ##    ##    #+#        #
#    Updated: 2018/04/02 14:10:34 by lgarcia-    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = libftprintf.a
PATH_SRC = ./srcs/
PATH_OBJ = ./objs/
PATH_INC = ./incs/
INCLUDE = $(addprefix $(PATH_INC), libft.h ft_printf.h)
FLAGS = -Wall -Wextra -Werror

PATH_SRC_FT_PRINTF = $(PATH_SRC)ft_printf/
PATH_OBJ_FT_PRINTF = $(PATH_OBJ)ft_printf/
FILES_FT_PRINTF = ft_printf ft_print ft_params ft_modif ft_modif_s\
				  ft_data ft_modif_d ft_itoa_base ft_strtoupper\
				  ft_modif_o ft_util ft_print_o ft_print_x\
				  ft_uitoa_base ft_putwchar ft_putwstr ft_modif_sup\
				  ft_print_u ft_modif_dif ft_modif_p ft_modif_u\
				  ft_modif_c ft_modif_x ft_util2 ft_print_ou
OBJ_FT_PRINTF = $(addprefix $(PATH_OBJ_FT_PRINTF), $(addsuffix .o, $(FILES_FT_PRINTF)))
SRC_FT_PRINTF = $(addprefix $(PATH_SRC_FT_PRINTF), $(addsuffix .c, $(FILES_FT_PRINTF)))

PATH_SRC_LIBFT = $(PATH_SRC)libft/
PATH_OBJ_LIBFT = $(PATH_OBJ)libft/
FILES_LIBFT = ft_atoi ft_isdigit ft_putchar ft_putstr ft_strchr\
			  ft_strdup ft_strlen ft_strsub ft_isspace ft_memchr
OBJ_LIBFT = $(addprefix $(PATH_OBJ_LIBFT), $(addsuffix .o, $(FILES_LIBFT)))
SRC_LIBFT = $(addprefix $(PATH_SRC_LIBFT), $(addsuffix .c, $(FILES_LIBFT)))

PATHS_OBJ = $(PATH_OBJ) $(PATH_OBJ_FT_PRINTF) $(PATH_OBJ_LIBFT)
OBJ = $(OBJ_FT_PRINTF) $(OBJ_LIBFT)
SRC = $(SRC_FT_PRINTF) $(SRC_LIBFT)

all: $(NAME)

$(NAME): $(PATHS_OBJ) $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(PATH_OBJ)%.o: $(PATH_SRC)%.c $(INCLUDE)
	gcc -o $@ -c $< -I $(PATH_INC)

$(PATHS_OBJ):
	mkdir $@

clean:
	/bin/rm -rf $(PATH_OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all


