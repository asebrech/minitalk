# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asebrech <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/23 16:13:10 by asebrech          #+#    #+#              #
#    Updated: 2021/06/28 11:54:51 by asebrech         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = includes
DLIB = libft
PLIB = libft/libft.a
NAME1 = libserver.a
NAME2 = libclient.a
EXEC1 = serveur
EXEC2 = client
SRC1 = srcs/server.c\
	   srcs/utiles.c
SRC2 = srcs/client.c\
	   srcs/utiles.c
OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)
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

clean :
	make -C $(DLIB) clean
	$(RM) $(OBJ1)
	$(RM) $(OBJ2)
	$(RM) $(NAME1)
	$(RM) $(NAME2)

fclean : clean
	$(RM) $(PLIB)
	$(RM) $(EXEC1)
	$(RM) $(EXEC2)

re : fclean all

.c.o :
	$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $(<:.c=.o)

.PHONY : all clean fclean re
