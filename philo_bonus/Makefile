# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 18:56:19 by hfunctio          #+#    #+#              #
#    Updated: 2021/11/17 19:04:43 by hfunctio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

CFLAGS = -Wall -Wextra -Werror -g

SRCS = main.c utils.c

GCC = gcc

MK_DIR = mkdir

OBJSDIR = Bonus_tmp

OBJS = $(SRCS:.c=.o)

HDR = -I.philo_bonus.h

RM = rm -rf

all: $(NAME)
	@echo "\n\
		██████╗░██╗░░██╗██╗██╗░░░░░░█████╗░░██████╗░█████╗░██████╗░██╗░░██╗███████╗██████╗░░██████╗\n\
		██╔══██╗██║░░██║██║██║░░░░░██╔══██╗██╔════╝██╔══██╗██╔══██╗██║░░██║██╔════╝██╔══██╗██╔════╝\n\
		██████╔╝███████║██║██║░░░░░██║░░██║╚█████╗░██║░░██║██████╔╝███████║█████╗░░██████╔╝╚█████╗░\n\
		██╔═══╝░██╔══██║██║██║░░░░░██║░░██║░╚═══██╗██║░░██║██╔═══╝░██╔══██║██╔══╝░░██╔══██╗░╚═══██╗\n\
		██║░░░░░██║░░██║██║███████╗╚█████╔╝██████╔╝╚█████╔╝██║░░░░░██║░░██║███████╗██║░░██║██████╔╝\n\
		╚═╝░░░░░╚═╝░░╚═╝╚═╝╚══════╝░╚════╝░╚═════╝░░╚════╝░╚═╝░░░░░╚═╝░░╚═╝╚══════╝╚═╝░░╚═╝╚═════╝░"

$(OBJSDIR):
	@$(MK_DIR)	$@

GREEN = \033[0;32m
RESET = \033[0m

$(OBJSDIR)/%.o: %.c | $(OBJSDIR)
	@$(GCC) $(FLAGS) $(HDR) -c $< -o $@

$(NAME): $(OBJS) philo_bonus.h Makefile
	@$(GCC) -lpthread $(OBJS) -o $@
	@echo "$(GREEN) objects were created $(RESET)"
	@echo "$(GREEN) philo_bonus - [ok] $(RESET)"

clean:
	@$(RM) $(OBJSDIR)
	@echo "$(GREEN) objects were deleted $(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(GREEN) objects and $(NAME) were deleted $(RESET)"

re: fclean all