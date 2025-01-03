
SERVER = server
CLIENT = client
PRINTF = libftprintf.a
PRINTFDIR = ./PRINTF
CC = cc
CFLAGS = -Wall -Werror -Wextra


.PHONY : all, makeprintf, server, client clean, fclean, re, bonus

all: makeprintf $(SERVER) $(CLIENT)
	
makeprintf:
	@make -C $(PRINTFDIR)

$(SERVER):
	@$(CC) $(CFLAGS) $(SERVER).c $(PRINTFDIR)/$(PRINTF) -o $(SERVER)

$(CLIENT):
	@$(CC) $(CFLAGS) $(CLIENT).c $(PRINTFDIR)/$(PRINTF) -o $(CLIENT)

clean:
	@cd $(PRINTFDIR) && make clean 

fclean: clean
	@rm -f $(SERVER) $(CLIENT)
	@cd $(PRINTFDIR) && make fclean

bonus:
	@echo "Bonus already in satisfied in my mandatory part :)"

re: fclean all