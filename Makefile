all:
	gcc -Wall -Werror -Wextra -D BUFFER_SIZE=1 get_next_line.c get_next_line.h get_next_line_utils.c && ./a.out
leak:
	gcc -Wall -Werror -Wextra -D BUFFER_SIZE=1 get_next_line.c get_next_line.h get_next_line_utils.c -fsanitize=address && ./a.out