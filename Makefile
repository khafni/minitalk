SRCS1 = ./client_src/client_main.c ./client_src/client_methods.c 
SRCS2 =	./server_src/server_main.c ./server_src/server_methods.c
SRCS3 = ./rstr/rstr_methods1.c ./rstr/rstr_methods2.c ./rstr/rstr_methods3.c ./tools/tools1.c ./tools/tools2.c

BONUS_SRCS1 = ./client_src_bonus/client_main_bonus.c ./client_src_bonus/client_methods_bonus.c 
BONUS_SRCS2 =	./server_src_bonus/server_main_bonus.c ./server_src_bonus/server_methods_bonus.c
BONUS_SRCS3 = ./rstr_bonus/rstr_methods1_bonus.c ./rstr_bonus/rstr_methods2_bonus.c ./rstr_bonus/rstr_methods3_bonus.c ./tools_bonus/tools1_bonus.c ./tools_bonus/tools2_bonus.c

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

bonus: fclean
	@echo "\033[0;32mcompiling minitalk bonus"
	@gcc $(CFLAGS) $(BONUS_SRCS1) $(BONUS_SRCS3) -o client
	@gcc $(CFLAGS) $(BONUS_SRCS2) $(BONUS_SRCS3) -o server

re : fclean all
.PHONY: all clean fclean bonus re