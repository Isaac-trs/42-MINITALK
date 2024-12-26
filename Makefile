
SERVER = server
CLIENT = client
PRINTF = libftprintf.a
PRINTFDIR = ./PRINTF
CC = cc
CFLAGS = -Wall -Werror -Wextra


.PHONY : all, makelibft, clean, fclean, re

all: makeprintf $(SERVER) $(CLIENT)
	
makeprintf:
	@make -C $(PRINTFDIR)

$(SERVER):
	@$(CC) $(CFLAGS) $(SERVER).c $(PRINTFDIR)/$(PRINTF) -o $(SERVER)

$(CLIENT):
	@$(CC) $(CFLAGS) $(CLIENT).c $(PRINTFDIR)/$(PRINTF) -o $(CLIENT)

clean:
	@(cd $(PRINTFDIR) && make clean) 
	@rm -f $(SERVER) $(CLIENT)

fclean: clean
	@(cd $(PRINTFDIR) && make fclean)

re: fclean all