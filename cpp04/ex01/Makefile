NAME        = brain

CXX         = c++
CPPFLAGS    = -Wall -Wextra -Werror -std=c++98
HEADERS		=	Animal.hpp		\
				Dog.hpp			\
				Cat.hpp			\
				WrongAnimal.hpp	\
				WrongCat.hpp	\
				Brain.hpp		\

OBJ_PATH	= obj/

SRC_FILES   =	main.cpp		\
				Animal.cpp		\
				Dog.cpp			\
				Cat.cpp			\
				WrongAnimal.cpp	\
				WrongCat.cpp	\
				Brain.cpp		\

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
