NAME = fractol

DIRSRC = ./srcs

DIRCINC = ./includes/

DIRLIB = ./libft/

DIRMLX = ./mlx_linux/

SRC =	fractals \
		hooks \
		image \
		main \
		window \
		colors \

SRCS = $(addprefix ${DIRSRC}/, $(addsuffix .c, ${SRC}))

OBJS = ${SRCS:.c=.o}

LFT = libft.a

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g3

MLXFLAGS = -I . -lXext -lX11 -lm

.c.o:
	@${CC} ${CFLAGS} -c -I${DIRCINC} -I${DIRLIB} -I${DIRMLX} $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	@cd ${DIRLIB} && ${MAKE}
	@${CC} ${CFLAGS} ${MLXFLAGS} -o ${NAME} ${OBJS} -L./libft -lft -L./mlx_linux -lmlx
	@echo "✅ fractol has been created"

all: ${NAME}

clean:
	@${RM} ${OBJS} ${OBJS_B}
	@cd ${DIRLIB} && ${MAKE} clean
	@echo "✅ Directory is clean"

fclean:
	@${RM} ${OBJS}
	@${RM} ${NAME}
	@cd ${DIRLIB} && ${MAKE} fclean
	@echo "✅ Directory is fclean"

re : fclean all

.PHONY : all clean fclean re bonus