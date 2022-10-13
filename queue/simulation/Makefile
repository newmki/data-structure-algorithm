NAME = simulation
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

DEQUE_FILE = 	createLinkedDeque\
							deleteFrontLD\
							deleteLinkedDeque\
							deleteRearLD\
							displayLinkedDeque\
							insertFrontLD\
							insertRearLD\
							isLinkedDequeEmpty\
							isLinkedDequeFull\
							peekFrontLD\
							peekRearLD

FILE = 	insertCustomer\
				main\
				printReport\
				printSimCustomer\
				printWaitQueueStatus\
				processArrival\
				processServiceNodeEnd\
				processServiceNodeStart

INCS = ./includes

SRCS_DIR = ./srcs/
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILE)))
OBJS_DIR = ./srcs/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILE)))

DEQUE_SRCS_DIR = ./linkedDeque/
DEQUE_SRCS = $(addprefix $(DEQUE_SRCS_DIR), $(addsuffix .c, $(DEQUE_FILE)))
DEQUE_OBJS_DIR = ./linkedDeque/
DEQUE_OBJS = $(addprefix $(DEQUE_OBJS_DIR), $(addsuffix .o, $(DEQUE_FILE)))

.c.o: $(SRCS) $(DEQUE_SRCS)
	$(CC) $(CFLAGS) -c -o $@ $< -I$(INCS)

all: $(NAME)

$(NAME): $(OBJS) $(DEQUE_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(OBJS) $(DEQUE_OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all bonus clean fclean re
