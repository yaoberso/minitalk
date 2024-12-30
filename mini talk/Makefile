# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 13:32:22 by yaoberso          #+#    #+#              #
#    Updated: 2024/12/04 13:32:22 by yaoberso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Noms des exécutables
SERVER = server
CLIENT = client

# Options de compilation
CFLAGS = -Wall -Wextra -Werror -g -Iprintf
CC = gcc

# Fichiers sources
SERVER_SRC = serveur.c printf/ft_printf.c printf/ft_putchar.c printf/ft_puthex_lower.c \
             printf/ft_puthex_upper.c printf/ft_putnbr.c printf/ft_putpointer.c printf/ft_putstr.c \
             printf/ft_putunsint.c

CLIENT_SRC = client.c printf/ft_printf.c printf/ft_putchar.c printf/ft_puthex_lower.c \
             printf/ft_puthex_upper.c printf/ft_putnbr.c printf/ft_putpointer.c printf/ft_putstr.c \
             printf/ft_putunsint.c

# Fichiers objets
SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

# Compilation générale
all: $(SERVER) $(CLIENT)

# Compilation du serveur
$(SERVER): $(SERVER_OBJ)
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJ)

# Compilation du client
$(CLIENT): $(CLIENT_OBJ)
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJ)

# Vérification de la norme
norminette:
	@norminette $(SERVER_SRC) $(CLIENT_SRC)

# Nettoyage des fichiers objets
clean:
	rm -f $(SERVER_OBJ) $(CLIENT_OBJ)

# Nettoyage complet
fclean: clean
	rm -f $(SERVER) $(CLIENT)

# Reconstruction complète
re: fclean all

.PHONY: all clean fclean re norminette

