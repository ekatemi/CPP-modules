NAME = span
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address
SRC = main.cpp Span.cpp
HEADER = Span.hpp
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