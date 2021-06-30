# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asebrech <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/23 16:13:10 by asebrech          #+#    #+#              #
#    Updated: 2021/06/30 12:39:40 by asebrech         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = includes
DLIB = libft
PLIB = libft/libft.a
NAME1 = libserver.a
NAME2 = libclient.a
EXEC1 = server
EXEC2 = client
SRC1 = srcs/server.c
SRC2 = srcs/client.c
SRC3 = bonus/server_bonus.c
SRC4 = bonus/client_bonus.c
RM = rm -rf

ifdef WHITH_BONUS
	OBJ1 = $(SRC3:.c=.o)
	OBJ2 = $(SRC4:.c=.o)
else
	OBJ1 = $(SRC1:.c=.o)
	OBJ2 = $(SRC2:.c=.o)
endif

all : $(NAME1) $(NAME2)

bonus :
	@make WHITH_BONUS=1 all

$(NAME1) : $(OBJ1)
	@make -C $(DLIB) bonus
	@cp $(PLIB) $(NAME1)
	@ar rc $(NAME1) $(OBJ1)
	@ranlib $(NAME1)
	$(CC) $(CFLAGS) -I$(HEADER) -L. -lserver -o $(EXEC1)
	@$(RM) $(NAME1)

$(NAME2) : $(OBJ2)
	@make -C $(DLIB) bonus
	@cp $(PLIB) $(NAME2)
	@ar rc $(NAME2) $(OBJ2)
	@ranlib $(NAME2)
	$(CC) $(CFLAGS) -I$(HEADER) -L. -lclient -o $(EXEC2)
	@$(RM) $(NAME2)

clean :
	@make -C $(DLIB) clean
	$(RM) $(SRC1:.c=.o)
	$(RM) $(SRC2:.c=.o)
	$(RM) $(SRC3:.c=.o)
	$(RM) $(SRC4:.c=.o)

fclean : clean
	$(RM) $(PLIB)
	$(RM) $(EXEC1)
	$(RM) $(EXEC2)

re : fclean all

.c.o :
	$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $(<:.c=.o)

.PHONY : all clean fclean re bonus
