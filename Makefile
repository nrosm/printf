NAME = libftprintf.a
INCLUDES = ft_printf.h
SRC = ft_printf.c libprintf.c

OBJ = $(SRC:.c=.o)

CC = cc
CCFLAGS = -Wall -Wextra -Werror

AR = ar rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)

%.o: %c
	$(CC) $(CCFLAGS) -c $< -o $@
clean:
	$(RM) $(OBJ)
fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
