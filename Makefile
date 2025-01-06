
SERVER = server
CLIENT = client
PRINTF = libftprintf.a
PRINTFDIR = ./PRINTF
CC = cc
CFLAGS = -Wall -Werror -Wextra
CLIBONUS = client_bonus
SRVBONUS = server_bonus

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
	@rm -f $(SERVER) $(CLIENT) $(CLIBONUS) $(SRVBONUS)
	@cd $(PRINTFDIR) && make fclean

bonus: makeprintf
	@$(CC) $(CFLAGS) $(SRVBONUS).c $(PRINTFDIR)/$(PRINTF) -o $(SRVBONUS)
	@$(CC) $(CFLAGS) $(CLIBONUS).c $(PRINTFDIR)/$(PRINTF) -o $(CLIBONUS)

re: fclean all