CXX = clang++

CXXFLAGS = -Wall -Werror -Wextra

NAME1 = predict_price

NAME2 = learn_thetas

SRC1 = predict/main.cpp

SRC2 = learn/learn.cpp learn/learning.cpp

OBJ1 = $(SRC1:.cpp=.o)

OBJ2 = $(SRC2:.cpp=.o)


all: $(NAME1) $(NAME2)

$(NAME1): $(OBJ1)
	$(CXX) $(CXXFLAGS) -o $(NAME1) $(OBJ1)
$(NAME2): $(OBJ2)
	$(CXX) $(CXXFLAGS) -o $(NAME2) $(OBJ2)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ1) $(OBJ2)

fclean: clean
	rm -rf $(NAME1) $(NAME2)

re: fclean all