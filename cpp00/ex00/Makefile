NAME        = megaphone

CC          = c++
CFLAGS      = -Wall -Wextra -Werror -std=c++98

OBJ_PATH	= obj/

SRC_FILES   = megaphone.cpp \

OBJ_FILES   = $(SRC_FILES:.cpp=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ_FILES))

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
