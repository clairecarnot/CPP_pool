###################### VARIABLES ##########################

NAME = megaphone

CFLAGS = -Wall -Wextra -Werror -MMD -g3 -std=c++98
CC = c++

SRCS = megaphone.cpp

SRCS_DIR = srcs/
OBJS_DIR = .objs/

###################### DERIVED VARIABLES ##################

OBJS = $(addprefix $(OBJS_DIR), $(OBJS_NAMES))

OBJS_NAMES = $(SRCS:.cpp=.o)

DEPS = $(OBJS:.o=.d)

###################### RULES #############################

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

$(OBJS_DIR)%.o:$(SRCS_DIR)%.cpp
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all

###################### PHONY TARGETS ######################

.PHONY: all clean fclean re
