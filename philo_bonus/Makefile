# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfunctio <hfunctio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 18:56:19 by hfunctio          #+#    #+#              #
#    Updated: 2021/11/18 17:13:08 by hfunctio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

CFLAGS = -Wall -Wextra -Werror -g

SRCS =	srcs_bonus/main_bonus.c \
		srcs_bonus/utils_bonus.c  \
		srcs_bonus/init_args_bonus.c \
		srcs_bonus/philo_life.c \


GCC = gcc

MK_DIR = mkdir

OBJSDIR = Bonus_tmp

OBJS = $(subst srcs_bonus/,$(OBJSDIR)/,$(SRCS:.c=.o))

HDR = -I.philosophers_bonus.h

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

$(OBJSDIR)/%.o: srcs_bonus/%.c | $(OBJSDIR)
	@$(GCC) $(CFLAGS) $(HDR) -c $< -o $@

$(NAME): $(OBJS) philosophers_bonus.h Makefile
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