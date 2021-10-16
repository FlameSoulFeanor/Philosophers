NAME = philo

CFLAGS = -Wall -Wextra -Werror -g

SRCS =  srcs/main.c \
		srcs/utils.c \
		srcs/init_args.c \


GCC = gcc

MK_DIR = mkdir

OBJSDIR = Temporary

OBJS = $(subst srcs/,$(OBJSDIR)/,$(SRCS:.c=.o))

HDR = -I./includes

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
	@$(MK_DIR) $@

GREEN = \033[0;32m
RESET = \033[0m

$(OBJSDIR)/%.o: srcs/%.c | $(OBJSDIR)
	@$(GCC) $(CFLAGS) $(HDR) -c $< -o $@


$(NAME): $(OBJS) ./includes/philosophers.h Makefile
	@$(GCC) -lpthread $(OBJS)  -o $@
	@echo "$(GREEN) objects were created $(RESET)"
	@echo "$(GREEN) philo - [ok] $(RESET)"

clean:
	@$(RM) $(OBJSDIR)
	@echo "$(GREEN) objects were deleted $(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(GREEN) objects and $(NAME) were deleted $(RESET)"

re: fclean all