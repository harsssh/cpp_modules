SHELL := /bin/bash

NAME := btc
SRC := $(wildcard *.cpp)
OBJ := $(SRC:.cpp=.o)

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

.PHONY: clean
clean:
	$(RM) $(OBJ)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
re: fclean all

.PHONY: valgrind
valgrind: all
	valgrind -q --log-fd=3 --leak-check=full --error-exitcode=1 \
	./$(NAME) input.txt \
	3>&2 &> /dev/null
