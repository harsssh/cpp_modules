SHELL := /bin/bash

NAME := convert
SRC := main.cpp ScalarConverter.cpp
OBJ := $(SRC:.cpp=.o)

CXX := c++
# some C++11 features are available in this exercise
CXXFLAGS := -Wall -Wextra -Werror

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
	./$(NAME) "42.0f" \
	3>&2 &> /dev/null
