NAME = findmaze
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

LL_FILE = createLinkedStack\
		pushLS\
		popLS\
		peekLS\
		deleteLinkedStack\
		isLinkedStackSize\
		isLinkedStackEmpty

FILE = main\
			findPath\
			printMaze\
			pushLSMapPosition\
			showPath

INCS = ./includes

SRCS_DIR = ./srcs/
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILE)))
OBJS_DIR = ./srcs/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILE)))

LL_SRCS_DIR = ./linkedlist/
LL_SRCS = $(addprefix $(LL_SRCS_DIR), $(addsuffix .c, $(LL_FILE)))
LL_OBJS_DIR = ./linkedlist/
LL_OBJS = $(addprefix $(LL_OBJS_DIR), $(addsuffix .o, $(LL_FILE)))

.c.o: $(SRCS) $(LL_SRCS)
	$(CC) $(CFLAGS) -c -o $@ $< -I$(INCS)

all: $(NAME)

$(NAME): $(OBJS) $(LL_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(OBJS) $(LL_OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all bonus clean fclean re
