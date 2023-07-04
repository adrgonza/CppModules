NAME = Violence
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = HumanA.cpp HumanB.cpp main.cpp Weapon.cpp

OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re
