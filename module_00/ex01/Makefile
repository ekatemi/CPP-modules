NAME = mybook
CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98
SRC = main.cpp Contact.cpp MyPhoneBook.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) Makefile
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean :
	rm -f $(NAME)
	rm -f $(OBJ)

re : fclean all

.PHONY : clean fclean re all