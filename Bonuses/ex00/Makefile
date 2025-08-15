NAME = ex00

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Bank.cpp Account.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean : 
	rm -rf $(OBJ) $(NAME)

re : fclean all