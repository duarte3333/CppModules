NAME = PmergeMe
CXX = c++ #-fsanitize=address -g
CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98
SRC = main.cpp \
	  PmergeMe.cpp 


OBJ =  $(SRC:.cpp=.o)

$(NAME): ${OBJ}
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	rm ${OBJ}

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all re clean fclean