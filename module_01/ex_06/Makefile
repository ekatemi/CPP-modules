NAME = harl
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
SRC = main.cpp Harl.cpp
OBJ = $(SRC:.cpp=.o)
HEADER = Harl.hpp

all: $(NAME)

$(NAME): Makefile $(OBJ) 
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADER) Makefile
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

re: fclean all

fclean: clean
	rm -f $(NAME)

.PHONY: make clean fclean re