# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asebrech <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/23 16:13:10 by asebrech          #+#    #+#              #
#    Updated: 2021/06/30 09:39:01 by asebrech         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = includes
DLIB = libft
PLIB = libft/libft.a
NAME1 = libserver.a
NAME2 = libclient.a
NAME3 = libserver_bonus.a
NAME4 = libclient_bonus.a
EXEC1 = server
EXEC2 = client
SRC1 = srcs/server.c
SRC2 = srcs/client.c
SRC3 = bonus/server_bonus.c
SRC4 = bonus/client_bonus.c
OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)
OBJ3 = $(SRC3:.c=.o)
OBJ4 = $(SRC4:.c=.o)
RM = rm -rf

all : $(NAME1) $(NAME2)

$(NAME1) : $(OBJ1)
	make -C $(DLIB) bonus
	cp $(PLIB) $(NAME1)
	ar rc $(NAME1) $(OBJ1)
	ranlib $(NAME1)
	$(CC) $(CFLAGS) -I$(HEADER) -L. -lserver -o $(EXEC1)
	$(RM) $(NAME1)

$(NAME2) : $(OBJ2)
	make -C $(DLIB) bonus
	cp $(PLIB) $(NAME2)
	ar rc $(NAME2) $(OBJ2)
	ranlib $(NAME2)
	$(CC) $(CFLAGS) -I$(HEADER) -L. -lclient -o $(EXEC2)
	$(RM) $(NAME2)

bonus : $(NAME3) $(NAME4)

$(NAME3) : $(OBJ3)
	make -C $(DLIB) bonus
	cp $(PLIB) $(NAME3)
	ar rc $(NAME3) $(OBJ3)
	ranlib $(NAME3)
	$(CC) $(CFLAGS) -I$(HEADER) -L. -lserver_bonus -o $(EXEC1)
	$(RM) $(NAME3)

$(NAME4) : $(OBJ4)
	make -C $(DLIB) bonus
	cp $(PLIB) $(NAME4)
	ar rc $(NAME4) $(OBJ4)
	ranlib $(NAME4)
	$(CC) $(CFLAGS) -I$(HEADER) -L. -lclient_bonus -o $(EXEC2)
	$(RM) $(NAME4)

clean :
	make -C $(DLIB) clean
	$(RM) $(OBJ1)
	$(RM) $(OBJ2)
	$(RM) $(OBJ3)
	$(RM) $(OBJ4)

fclean : clean
	$(RM) $(PLIB)
	$(RM) $(EXEC1)
	$(RM) $(EXEC2)

re : fclean all

.c.o :
	$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $(<:.c=.o)

.PHONY : all clean fclean re
