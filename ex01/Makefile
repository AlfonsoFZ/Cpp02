NAME = a.out

SRC = 	main.cpp 	\
		Fixed.cpp	

OBJT_DIR = objt

OBJT = $(addprefix $(OBJT_DIR)/, $(patsubst %.cpp, %.o, $(SRC)))

C++ = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -D DEBUG=$(DEBUG) 

RM = rm -f

MAKEFLAGS += --quiet

ifdef DEBUG
	DEBUG = 1
else
	DEBUG = 0
endif

all: $(NAME)

$(NAME): $(OBJT)
	$(C++) $(CFLAGS) $(OBJT) -o $(NAME)

$(OBJT_DIR)/%.o: %.cpp
	mkdir -p $(@D)
	$(C++) $(CFLAGS) -c $< -o $@ 

run: $(NAME)
	./$(NAME)

rerun:	
	make re run

debug:
	make re DEBUG=1

clean:
		$(RM) -r $(OBJT_DIR)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re rerun run debug
