# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/04 15:03:13 by brivera           #+#    #+#              #
#    Updated: 2025/03/05 14:41:03 by brivera          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libs/libft
LIBFTA = $(LIBFT_DIR)/libft.a

SRC_DIR = src
SRC_DIR_BONUS = bonus

SRCS = 	$(SRC_DIR)/main.c \
		$(SRC_DIR)/utils_00.c $(SRC_DIR)/utils_01.c \
		$(SRC_DIR)/control_argument_00.c $(SRC_DIR)/control_argument_01.c \
		$(SRC_DIR)/movements_00.c $(SRC_DIR)/movements_01.c $(SRC_DIR)/movements_02.c \
		$(SRC_DIR)/stack_sort_00.c $(SRC_DIR)/stack_sort_01.c $(SRC_DIR)/stack_sort_02.c \
		$(SRC_DIR)/stack_sort_03.c $(SRC_DIR)/stack_sort_04.c \

SRC_BONUS = $(SRC_DIR_BONUS)/checker_bonus.c\
			$(SRC_DIR_BONUS)/utils_00_bonus.c $(SRC_DIR_BONUS)/utils_01_bonus.c \
			$(SRC_DIR_BONUS)/control_argument_00_bonus.c $(SRC_DIR_BONUS)/control_argument_01_bonus.c \
			$(SRC_DIR_BONUS)/checker_mov_01_bonus.c $(SRC_DIR_BONUS)/checker_mov_02_bonus.c \
			$(SRC_DIR_BONUS)/checker_mov_00_bonus.c \

OBJ_DIR = obj
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJS_BONUS = $(SRC_BONUS:$(SRC_DIR_BONUS)/%.c=$(OBJ_DIR)/%.o)

INCLUDE = include/push_swap.h
INCLUDES_BONUS = include/push_swap_bonus.h

RED = \033[91;1m
GREEN = \033[92;1m
CLEAR_COLOR = \033[0m
CYAN = \033[96;1m

RM = rm -f

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(LIBFTA) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFTA) -I. -o $(NAME)
	@echo "$(GREEN)✅ Compilado PUSH_SWAP\n$(CLEAR_COLOR)"

$(NAME_BONUS): $(LIBFTA) $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFTA) -I. -o $(NAME_BONUS)
	@echo "$(GREEN)\n\n✅ Compilado CHECKER.\n$(CLEAR_COLOR)"

$(LIBFTA):
	@make -C $(LIBFT_DIR)
	@echo "$(GREEN)✅ Compilado LIBFT\n$(CLEAR_COLOR)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDE)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -Iinclude -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR_BONUS)/%.c $(INCLUDES_BONUS)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -Iinclude -c $< -o $@
	@echo -n "\rCompilando BONUS: $<"

clean:
	@$(RM) -r $(OBJ_DIR) $(OBJS_BONUS)
	@make clean -C $(LIBFT_DIR)
	@echo "$(RED)⛔ Limpieza de archivos objeto.$(CLEAR_COLOR)"

fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS)
	@make fclean -C $(LIBFT_DIR)
	@echo "$(RED)⛔ Limpieza total (ejecutables y librerías).$(CLEAR_COLOR)"

re: fclean all
	@echo "$(CYAN)🔄 Proyecto reconstruido.$(CLEAR_COLOR)"

norminette:
	@norminette $(SRCS) $(SRC_BONUS) $(INCLUDE) $(INCLUDES_BONUS)
