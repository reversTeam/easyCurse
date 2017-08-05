CXX = g++

CXXFLAGS = -Wall -Wextra -Werror -Iinclude

LDFLAGS = -lncurses

SRC = $(shell find src -name "*.cpp")

OBJ = $(SRC:.cpp=.o)

NAME = easyCurses

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
