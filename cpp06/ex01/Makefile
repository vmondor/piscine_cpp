NAME        = serialize

CXX         = c++
CPPFLAGS    = -Wall -Wextra -Werror -std=c++98
HEADERS		=	Serializer.hpp

OBJ_PATH	= obj/

SRC_FILES   =	main.cpp			\
				Serializer.cpp		\

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

re:
	make fclean
	make all

.PHONY: all clean fclean re
