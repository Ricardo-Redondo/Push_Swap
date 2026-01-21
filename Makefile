# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsao-pay <rsao-pay@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/12 21:34:25 by rsao-pay          #+#    #+#              #
#    Updated: 2026/01/21 11:26:44 by rsao-pay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

BHCYN		= \e[1;96m
RESET       = \033[0m

define INTRO_ART



				   .-------.   ___    _    .-'''-. .---.  .---.            .-'''-. .--.      .--.   ____    .-------.  
				   \  _(`)_ \.'   |  | |  / _     \|   |  |_ _|           / _     \|  |_     |  | .'  __ `. \  _(`)_ \ 
				   | (_ o._)||   .'  | | (`' )/`--'|   |  ( ' )          (`' )/`--'| _( )_   |  |/   '  \  \| (_ o._)| 
				   |  (_,_) /.'  '_  | |(_ o _).   |   '-(_{;}_)        (_ o _).   |(_ o _)  |  ||___|  /  ||  (_,_) / 
				   |   '-.-' '   ( \.-.| (_,_). '. |      (_,_)          (_,_). '. | (_,_) \ |  |   _.-`   ||   '-.-'  
				   |   |     ' (`. _` /|.---.  \  :| _ _--.   |         .---.  \  :|  |/    \|  |.'   _    ||   |      
				   |   |     | (_ (_) _)\    `-'  ||( ' ) |   |         \    `-'  ||  '  /\  `  ||  _( )_  ||   |      
				   /   )      \ /  . \ / \       / (_{;}_)|   |          \       / |    /  \    |\ (_ o _) //   )      
				   `---'       ``-'`-''   `-...-'  '(_,_) '---'           `-...-'  `---'    `---` '.(_,_).' `---'        



endef
export INTRO_ART

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

INCLUDES	= -I includes/
SRC_DIR		= sources/
OBJ_DIR		= obj/

SRC_FILES	= main.c \
			  ft_init.c \
			  ft_parsing.c \
			  ft_push.c \
			  ft_rotate.c \
			  ft_rrotate.c \
			  ft_sort_utils.c \
			  ft_sort.c \
			  ft_split.c \
			  ft_stack_utils.c \
			  ft_utils.c \
			  ft_swap.c

SRCS		= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS		= $(SRC_FILES:%.c=$(OBJ_DIR)%.o)

all:$(NAME)

$(NAME):$(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) -o $(NAME)
	@clear
	@printf "|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n"
	@printf "$(BHCYN)$$INTRO_ART$(RESET)\n"
	@printf "|------------------------------------------------------------------------|$(BHCYN)push swap is compiled$(RESET)|------------------------------------------------------------------------------|\n"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
ifneq ($(filter fclean,$(MAKECMDGOALS)), fclean)
ifneq ($(filter re,$(MAKECMDGOALS)), re)
	@printf "|---------------------------------------------------------------------------|$(BHCYN)Objects are clean$(RESET)|-------------------------------------------------------------------------------|\n"
endif
endif

fclean: clean
	@rm -rf $(NAME)
ifneq ($(filter re,$(MAKECMDGOALS)), re)
	@printf "|-----------------------------------------------------------------------------|$(BHCYN)Fully cleaned$(RESET)|---------------------------------------------------------------------------------|\n"
endif

re: fclean clean
	@printf "|--------------------------------------------------------------------------|$(BHCYN)Remade everything$(RESET)|--------------------------------------------------------------------------------|\n"

.PHONY: all clean fclean re