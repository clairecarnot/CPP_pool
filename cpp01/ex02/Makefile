# VARIABLES --------------------------------------------------------#

NAME = thisIsBrain

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -MMD -std=c++98

SRCS = main.cpp

SRCS_DIR = srcs/
OBJS_DIR = .objs/

# DERIVED VARIABLES ------------------------------------------------#

OBJS = $(addprefix $(OBJS_DIR), $(OBJS_NAMES))

OBJS_NAMES = $(SRCS:.cpp=.o)

DEPS = $(SRCS:.cpp=.d)

# RULES ------------------------------------------------------------#

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

$(OBJS_DIR)%.o:$(SRCS_DIR)%.cpp
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean
	make all

# PHONY TARGETS ----------------------------------------------------#

.PHONY: all clean fclean re
