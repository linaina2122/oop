NAME  = Graph

SRCS  = Graph.cpp Vector2.cpp main.cpp

OBJS  = $(SRCS:.cpp=.o)

FLAGS = -Wall -Wextra -Werror -std=c++98

CXX = c++

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CFLAGS) -o $(NAME) $(OBJS)

clean: 
	rm -rf $(OBJS)

fclean: 
	rm -rf $(NAME) $(OBJS)

re : fclean all


