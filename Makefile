SRCS = get_next_line.c get_next_line_utils.c
OBJS = ${SRCS:.c=.o}
SRCSB = get_next_line_utils_bonus.c get_next_line_bonus.c
OBJSB = ${SRCSB:.c=.o}

NAME = get_next_line.a
LIBC = ar rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

all: ${NAME}

bonus: ${OBJSB}
	${LIBC} ${NAME} ${OBJSB}

clean:
	${RM} ${OBJS} ${OBJSB}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re
