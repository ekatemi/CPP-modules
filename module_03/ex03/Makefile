NAME = frag
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

# Directories
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj

# Explicit source and object files
SRC = $(SRC_DIR)/main.cpp $(SRC_DIR)/ClapTrap.cpp $(SRC_DIR)/ScavTrap.cpp $(SRC_DIR)/FragTrap.cpp $(SRC_DIR)/DiamondTrap.cpp
HEADER = $(INC_DIR)/ClapTrap.hpp $(INC_DIR)/ScavTrap.hpp $(INC_DIR)/FragTrap.hpp $(INC_DIR)/DiamondTrap.hpp
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# All rule
all: $(NAME)

# Compile executable
$(NAME): $(OBJ) Makefile
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

# Compile object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADER) Makefile
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -I $(INC_DIR) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJ)

# Clean everything
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: clean fclean re all