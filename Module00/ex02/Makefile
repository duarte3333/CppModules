NAME = account
CXX = c++ -fsanitize=address -g
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = Account.cpp \
	  tests.cpp 
OBJ =  $(SRC:.cpp=.o)

all: $(NAME)

$(NAME):
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

fclean:
	rm $(NAME)

re: fclean all