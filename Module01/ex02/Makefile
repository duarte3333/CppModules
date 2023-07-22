NAME = HI_THIS_IS_BRAIN
CXX = c++ -fsanitize=address -g
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp 

OBJ =  $(SRC:.cpp=.o)

$(NAME):
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	rm ${OBJ}

fclean:
	rm $(NAME)

re: fclean all

PHONY: all re clean fclean