NAME = materia
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
SRC = main.cpp Amateria.cpp Character.cpp Cure.cpp Ice.cpp Icharacter.cpp IMateriaSource.cpp MateriaSource.cpp
HEADER = Amateria.hpp Character.hpp Cure.hpp Ice.hpp Icharacter.hpp IMateriaSource.hpp MateriaSource.hpp
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