SRCS1 = ./client_src/client_main.c ./client_src/client_methods.c 
SRCS2 =	./server_src/server_main.c ./server_src/server_methods.c
SRCS3 = ./rstr/rstr_methods1.c ./rstr/rstr_methods2.c ./rstr/rstr_methods3.c ./tools/tools1.c ./tools/tools2.c
NAME	= minitalk
NAME1	= client
NAME2	= server
CC	 = gcc
CFLAGS	 = -Wall -Wextra -Werror

all:$(NAME1) $(NAME2)
$(NAME1):	
	@echo "\033[0;32mcompiling minitalk"	
	@gcc $(CFLAGS) $(SRCS1) $(SRCS3) -o client
$(NAME2):	
	@echo "\033[0;32mcompiling minitalk"	
	@gcc $(CFLAGS) $(SRCS2) $(SRCS3) -o server

clean:
	@rm -f $(NAME1)
	@rm -f $(NAME2)
fclean: clean
	@echo "\033[0;33meverything cleaned"

re : fclean all