NAME = animal
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
SRC = main.cpp Animal.cpp Cat.cpp Dog.cpp 
HEADER = Animal.hpp Cat.hpp Dog.hpp
OBJ = $(SRC:.cpp=.o)
all: $(NAME)
$(NAME): Makefile $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADER) Makefile
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: clean fclean re all