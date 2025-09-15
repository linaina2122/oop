
NAME = Graph

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Graph.cpp Vector2.cpp main.cpp

OBJ = $(SRCS:.cpp=.o)

all : $(NAME)

CXX = c++

$(NAME) : $(OBJ)
	$(CXX) $(CFLAGS) -o $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)

fclean :
	rm -f $(OBJ) $(NAME)

re : fclean all
