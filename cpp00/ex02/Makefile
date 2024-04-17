NAME = Account

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

INCL = -I Account.hpp

SRCS = tests.cpp Account.cpp

OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

%.o:%.cpp
	$(CC) $(CFLAGS) $(INCL) -o $@ -c $<

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean
	make all

.PHONY: all clean fclean re
