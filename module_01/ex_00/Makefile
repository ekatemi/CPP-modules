NAME = zombie
CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic
SRC = Zombie.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
HEADERS = Zombie.hpp

all: $(NAME)

$(NAME): Makefile $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp Makefile $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all