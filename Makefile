# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/08 22:55:30 by ojessi            #+#    #+#              #
#    Updated: 2019/10/08 10:22:23 by ojessi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re, obj, red, grn, off, norm

NAME = wolf3d

# src / obj files
SRC =	sdl.c \
		main.c \
		func.c \
		color.c \
		image.c \
		raycast.c \
		main_cicle.c \
		utils.c \


OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))

# compiler
CC = gcc
CFLAGS = -Wextra -Wall -Werror -g

# ft library
FT = ./libft
FT_LIB = $(addprefix $(FT), libft.a)
FT_INC = -I ./libft
FT_LNK = ./libft/libft.a

# SDL
SDL_INC = -I /Users/ojessi/Library/Frameworks/SDL2.framework/Headers -I /Users/ojessi/Library/Frameworks/SDL2_mixer.framework/Headers
SDL_LNK = -F /Users/ojessi/Library/Frameworks/ -framework SDL2 -framework SDL2_mixer

# directories
SRCDIR = ./src/
INCDIR = -I ./includes/
OBJDIR = ./obj/

all: $(NAME)

$(NAME): obj $(FT_LIB) grn $(OBJ)
	@$(CC) $(OBJ) $(FT_LNK) $(SDL_LNK) -o $(NAME)
	@echo "\x1b[0m"

red:
	@echo "\x1B[31m"

grn:
	@echo "\x1B[32m"

off:
	@echo "\x1b[0m"

obj:
	@mkdir -p $(OBJDIR)

$(FT_LIB):
	@make -C $(FT)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(FT_INC) $(SDL_INC) $(INCDIR) -o $@ -c $<

clean: red
	/bin/rm -rf $(OBJDIR)
	@make -C $(FT) clean

fclean: clean
	/bin/rm -rf $(NAME)
	make -C $(FT) fclean

re: fclean all

norm:
	norminette
