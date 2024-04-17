#---------------------- VARIABLES --------------------------#

NAME = PhoneBook

CFLAGS = -Wall -Wextra -Werror -MMD -g3 -std=c++98
CC = c++

SRCS = main.cpp PhoneBook.cpp Contact.cpp

INCL = -I ./includes/Contact.hpp ./includes/PhoneBook.hpp

SRCS_DIR = srcs/
OBJS_DIR = .objs/

#---------------------- DERIVED VARIABLES ------------------#

OBJS = $(addprefix $(OBJS_DIR), $(OBJS_NAMES))

OBJS_NAMES = $(SRCS:.cpp=.o)

DEPS = $(OBJS:.o=.d)

#---------------------- RULES -----------------------------#

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

$(OBJS_DIR)%.o:$(SRCS_DIR)%.cpp
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all

#---------------------- PHONY TARGETS ----------------------#

.PHONY: all clean fclean re
