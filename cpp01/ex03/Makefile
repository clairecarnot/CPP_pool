# VARIABLES -------------------------------------------------------------------#

NAME = unnecessaryViolence

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -MMD -std=c++98

INCL = -I $(INCL_DIR)

SRCS = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

INCL_DIR = includes/
SRCS_DIR = srcs/
OBJS_DIR = .objs/

# DERIVED VARIABLES -----------------------------------------------------------#

OBJS = $(addprefix $(OBJS_DIR), $(OBJS_NAMES))

OBJS_NAMES = $(SRCS:.cpp=.o)

DEPS = $(SRCS:.cpp=.d)

# RULES -----------------------------------------------------------------------#

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

# PHONY TARGETS ---------------------------------------------------------------#

.PHONY: all clean fclean re
