NAME = bintree
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

FILE = 	deleteBinTree\
				deleteBinTreeNode\
				getLeftChildNodeBT\
				getRightChildNodeBT\
				getRootNodeBT\
				insertLeftChildNodeBT\
				insertRightChildNodeBT\
				main\
				makeBinTree\
				traversal\

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
