NAME	= program
CC	= cc
#CFLAGS	= -Wall

SRCS	= getinfo.c $(wildcard srcs/*.c)
OBJS	= $(SRCS:.c=.o)
LIBS	= ncurses

all: $(OBJS)
	@$(CC) $(OBJS) -l$(LIBS) -o $(NAME)
	@rm -f $(OBJS)
	@./$(NAME)
%.o: %.c
	@$(CC) -c $< -o $@

clean:
	@rm -f $(OBJS)
fclean: clean
	@rm -f $(NAME)
re: fclean all
