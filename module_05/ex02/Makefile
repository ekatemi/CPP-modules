NAME = test
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
SRC = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
HEADER = Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp
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