CLIENT		= client 
SERVER		= server
CLSRC		= client.c ft_atoi.c ft_putbin.c ft_strlen.c ft_bzero.c
CLOBJ		= client.o ft_atoi.o ft_putbin.o ft_strlen.o ft_bzero.o
SERSRC		= server.c ft_putnbr.c 
SEROBJ		= server.o ft_putnbr.o

all : $(CLIENT) $(SERVER)

$(CLIENT) : $(CLOBJ) libft.h
	@gcc -Wall -Werror -Wextra $(CLOBJ) -o client
	@echo "\x1b[32m\x1b[1m./client build successfully\x1b[0m 🥝"

$(SERVER) : $(SEROBJ) libft.h
	@gcc -Wall -Werror -Wextra $(SEROBJ) -o server
	@echo "\x1b[33m\x1b[1m./server build successfully\x1b[0m 🍋"

$(CLOBJ) : $(CLSRC)
	@gcc -Wall -Werror -Wextra -c $^

$(SEROBJ) : $(SERSRC)
	@gcc -Wall -Werror -Wextra -c $^ 

clean :
	@rm -rf *.o
	@echo "\x1b[35m.o files destroyed successfully\x1b[0m 🔥"

fclean : clean
	@rm -rf server client
	@echo "\x1b[31m\x1b[1mexecutable files destroyed successfully\x1b[0m 🚽"

re : fclean all