NAME        = claptrap

CXX         = c++
CPPFLAGS    = -Wall -Wextra -Werror -std=c++98
HEADERS		=	ClapTrap.hpp

OBJ_PATH	= obj/

SRC_FILES   =	main.cpp			\
				ClapTrap.cpp		\

OBJ_FILES   = $(SRC_FILES:.cpp=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ_FILES))

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: %.cpp $(HEADERS)
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
