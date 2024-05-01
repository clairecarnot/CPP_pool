# VARIABLES ------------------------------------------------------------------------------------ #

NAME = realtype

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -MMD -std=c++98

SRCS = main.cpp Base.cpp

INCL_DIR = includes/
SRCS_DIR = srcs/
OBJS_DIR = .objs/

# DERIVED VARIABLES ---------------------------------------------------------------------------- #

OBJS = $(addprefix $(OBJS_DIR), $(OBJS_NAMES))

OBJS_NAMES = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

INCL = -I $(INCL_DIR)

# RULES ---------------------------------------------------------------------------------------- #

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

# PHONY TARGETS -------------------------------------------------------------------------------- #

.PHONY: all clean fclean re
