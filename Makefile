NAME = philo

CFLAGS = -Wall -Wextra -Werror -g

SRCS =  srcs/main.c \
		srcs/init_args.c \

		
OBJSDIR = Temporary

OBJS = $(subst srcs/,$(OBJSDIR)/,$(SRCS:.c=.o))

HDR = -I./includes

all: $(NAME)

$(OBJSDIR):
	mkdir $@

$(OBJSDIR)/%.o: srcs/%.c | $(OBJSDIR)
	gcc -g $(CFLAGS) $(HDR) -c $< -o $@

$(NAME): $(OBJS) ./includes/philosophers.h
	gcc -g  $(OBJS)  -o $@

clean:
	/bin/rm -f $(OBJS)
	rm -rf $(OBJSDIR)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all