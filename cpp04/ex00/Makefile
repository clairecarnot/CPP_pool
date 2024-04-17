# VARIABLES --------------------------------------------------------#

NAME = polymorphism

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -MMD -std=c++98

SRCS = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp

SRCS_DIR = srcs/
INCL_DIR = includes/
OBJS_DIR = .objs/

# DERIVED VARIABLES ------------------------------------------------#

OBJS = $(addprefix $(OBJS_DIR), $(OBJS_NAMES))

INCL = -I $(INCL_DIR)

OBJS_NAMES = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

# RULES ------------------------------------------------------------#

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCL) -o $(NAME) $(OBJS)

all: $(NAME)

$(OBJS_DIR)%.o:$(SRCS_DIR)%.cpp
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCL) -o $@ -c $<

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean
	make all

# PHONY TARGETS ----------------------------------------------------#

.PHONY: all clean fclean re
