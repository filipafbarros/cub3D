# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fibarros <fibarros@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/16 15:01:42 by fibarros          #+#    #+#              #
#    Updated: 2024/09/16 15:08:01 by fibarros         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3d

# **************************************************************************** #
#                                 variables                                    #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

# Minilibx
MLX	= minilibx-linux/libmlx.a

# Libft
LIBFT = ./Libft/libft.a

INCLUDES = -I includes/ \
			-I Libft/inclu

RM = rm -rf

#                         Color and Checkmark Definitions                      #

LILAC=\033[1;38;5;183m
PINK=\033[1;38;5;213m
BABY_BLUE = \033[1;38;5;153m
ORG =\033[38;5;216m
BLUE=\033[1;34m
AQUA=\033[1;38;5;79m
AQUA_L=\033[38;5;51m
CHECK = \033[0;34m✔\033[0m
RT = \033[0m

#                                 Print Function                               #

define print_libs
	@echo "${BABY_BLUE}====> ${1}${RT}"
endef

define print_status
	@echo "${LILAC}====> ${1}${RT}"
endef

define norm_check
	@echo "${AQUA}====> ${1}${RT}"
endef


# **************************************************************************** #
#                                 SOURCES                                      #
# **************************************************************************** #

SRCS = sources/main.c sources/error.c 

OBJS = $(SRCS:.c=.o)


# **************************************************************************** #
#                                  RULES                                       #
# **************************************************************************** #

all: Start $(NAME) End

Start :
	@if [ -f $(NAME) ]; then \
		echo "${LILAC}Checking if build is necessary...${RT}"; \
	else \
		echo "${PINK}Compiling Cub3D...${RT}"; \
		echo "Starting the build process...!"; \
	fi

$(LIBFT):
	$(call print_libs,"Compiling Libft...")
	@make -C Libft > /dev/null
	@echo "${CHECK} Libft compiled                 ✅"

$(NAME): $(OBJS) $(LIBFT)
	$(call print_status,"Creating Minishell...")
	@$(CC) $(INCLUDES) $(OBJS) $(LIBFT) $(RL_LIB) $(LDFLAGS) -o $@ > /dev/null
	@echo "${CHECK} Compiling utilities and sources"

%.o: %.c
	@${CC} $(INCLUDES) ${CFLAGS} -c $< -o $@ > /dev/null

End :
	@echo "${PINK}Cub3D...${RT}";
	@echo "${CHECK} successfully compiled!         🎉$(RT)";

# **************************************************************************** #
#                                clean RULES                                   #
# **************************************************************************** #

clean:
	@echo "${ORG}==> Cleaning up object files...${1}${RT}"
	@$(MAKE) clean -C Libft > /dev/null
	@$(RM) $(OBJS)
	@echo "${CHECK} Cleanup complete               🧹"

fclean: clean
	@echo "${ORG}==> Full clean - Removing executables...${1}${RT}"
	@$(MAKE) fclean -C Libft > /dev/null
	@$(RM) $(NAME)
	@echo "${CHECK} Full cleanup complete          🧹"

re: fclean all

.PHONY: all clean fclean re