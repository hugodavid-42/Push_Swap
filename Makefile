SRC = check_value.c\
	complex_algo.c\
	easy_algos.c\
	exec.c\
	libft1.c\
	libft2.c\
	libft3.c\
	main.c\
	medium_algo.c\
	medium_algo_utils.c\
	options.c\
	parsing.c\
	printf.c\
	push.c\
	reverse_rotate.c\
	rotate.c\
	split.c\
	swap.c\
	utils1.c\
	utils2.c\
	utils3.c

OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror
EXEC = push_swap

all: $(EXEC)

$(EXEC): $(OBJ)
	 cc -o $@ $^

%.o: %.c
	cc -o $@ -c $< $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXEC)

re: fclean $(EXEC)