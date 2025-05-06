NAME        = Weapon

CC          = c++
CFLAGS      = -Wall -Wextra -Werror -std=c++98
HEADERS		=	Weapon.hpp \
				HumanA.hpp \
				HumanB.hpp \

OBJ_PATH	= obj/

SRC_FILES   =	main.cpp		\
				Weapon.cpp		\
				HumanA.cpp		\
				HumanB.cpp		\

OBJ_FILES   = $(SRC_FILES:.cpp=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ_FILES))

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
