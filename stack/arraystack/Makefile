NAME = arraystack
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

FILE = createArrayStack\
		pushAS\
		popAS\
		peekAS\
		deleteArrayStack\
		isArrayStackFull\
		isArrayStackEmpty\
		main \
		displayStack

INCS = ./includes

SRCS_DIR = ./srcs/
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILE)))
OBJS_DIR = ./srcs/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILE)))

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $< -I$(INCS)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all bonus clean fclean re
