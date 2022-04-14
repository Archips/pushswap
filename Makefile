# ========== [ Project files ]

# TODO set name
PREFIX			= push_swap
NAME			= $(PREFIX)
NAME_BONUS		= checker

# TODO set libriaires
LIB_DIR		= lib
LIB			= libft
LIB			:= $(LIB:%=$(LIB_DIR)/%)

# TODO set frameworks
FRAMEWORK	=

INC_DIR		= include
INC			= $(INC_DIR) \
			  $(LIB:%=%/$(INC_DIR)) $(LIB)

# TODO set sources
SRC_DIR		= src
SRCS		= main.c				\
			  parse_args.c			\
			  check_args.c			\
			  algo/pre_sort.c		\
			  algo/moves.c			\
			  algo/sort.c			\
			  algo/smallsort.c		\
			  algo/id.c				\
			  algo/leader.c			\
			  algo/costs.c			\
			  operations_1.c		\
			  operations_2.c		\
			  listutils_1.c			\
			  listutils_2.c			\
			  listutils_3.c			\
			  char_listutils.c		\
			  security.c
SRCS		:= $(SRCS:%=$(SRC_DIR)/%)

SRCS_BONUS  = checker/main_bonus.c		\
			  parse_args.c				\
			  check_args.c				\
			  checker/checker_bonus.c	\
			  operations_1.c			\
			  operations_2.c			\
			  listutils_1.c				\
			  listutils_2.c				\
			  listutils_3.c				\
			  char_listutils.c			\
			  security.c
SRCS_BONUS  := $(SRCS_BONUS:%=$(SRC_DIR)/%)

OBJ_DIR 	= obj
OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJS_BONUS	= $(SRCS_BONUS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# ========== [ Compiler flags ]

CC			= gcc

# TODO set extra compiler flags
CFLAGS		=
CFLAGS		:= $(CFLAGS) -Wall -Wextra -Werror -Wconversion -Wsign-conversion

# TODO set extra linker flags
CPPFLAGS	=
CPPFLAGS	:= $(CPPFLAGS) $(INC:%=-I%)
LDFLAGS		=
LDFLAGS 	:= $(LDFLAGS) $(LIB:%=-L%) $(FRAMEWORK)
LDLIBS		=
LDLIBS		:= $(LDLIBS) $(LIB:$(LIB_DIR)/lib%=-l%)

# ========== [ Misc ]

RM		= rm -rf
MAKE	= make --silent --jobs --directory

# ========== [ Recipe ]

.PHONY: all sani bonus clean fclean norm update re test leak t l

all: $(NAME)

sani: CFLAGS := $(CFLAGS) -fsanitize=address,undefined,signed-integer-overflow
sani: $(NAME)

$(NAME): $(OBJS)
	@for f in $(LIB); do $(MAKE) $$f --no-print-directory; done
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)
	@$(ECHO)"$(G)created $(END)$(NAME)\n"

bonus: $(OBJS_BONUS)
	@echo -n "\r\033[K"
	@for f in $(LIB); do $(MAKE) $$f --no-print-directory; done
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(OBJS_BONUS) $(LDLIBS) -o $(NAME_BONUS)
	@$(ECHO)"$(G)created $(END)$(NAME_BONUS)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@[ ! -d $(@D) ] && mkdir -p  $(@D) || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@$(ECHO)"$(G)created $(END)$@"

clean:
	@for f in $(LIB); do $(MAKE) $$f clean --no-print-directory; done
	@[ -d $(OBJ_DIR) ] \
		&& $(RM) $(OBJ_DIR) && $(ECHO)"$(R)removed$(END) $(OBJ_DIR)/\n" || true

fclean: clean
	@for f in $(LIB); do $(MAKE) $$f fclean --no-print-directory; done
	@[ -f $(NAME) ] \
		&& $(RM) $(NAME) && $(ECHO)"$(R)removed$(END) $(NAME)\n" || true
	@[ -f $(NAME_BONUS) ] \
		&& $(RM) $(NAME_BONUS) && $(ECHO)"$(R)removed$(END) $(NAME_BONUS)\n" || true

norm:
	@for f in $(LIB); do $(MAKE) $$f norm --no-print-directory; done
	@norminette -R CheckForbiddenSourceHeader $(SRCS) | grep -v "OK" || true
	@$(ECHO)"$(G)checked$(END) sources\n"
	@norminette -R CheckDefine $(INC_DIR) | grep -v "OK" || true
	@$(ECHO)"$(G)checked$(END) headers\n"

update:
	@git pull
	@git submodule update
	@$(ECHO)"$(G)updated$(END)\n"

re : fclean all

# ========== [ Tests ]

test: fclean sanitize

t: fclean sanitize

leak: fclean
	@valgrind -q --leak-check=yes --show-leak-kinds=all ./push_swap 0 0 1
	@valgrind -q --leak-check=yes --show-leak-kinds=all ./push_swap 3 2 1
	@valgrind -q --leak-check=yes --show-leak-kinds=all ./push_swap 921934 -49233 1234 23445
	@valgrind -q --leak-check=yes --show-leak-kinds=all ./push_swap 921934 -49233 1234 23445 456620 23 683452 20394 603464 -45392 435 288 66392 84777 2389 0 -23543

l: fclean

# ========== [ Stdout ]

R		= $(shell tput setaf 1)
G		= $(shell tput setaf 2)
Y		= $(shell tput setaf 3)
B		= $(shell tput setaf 4)
M		= $(shell tput setaf 5)
C		= $(shell tput setaf 6)
W		= $(shell tput setaf 7)
K		= $(shell tput setaf 8)
END		= $(shell tput sgr0)
ECHO	= echo -n "\r\033[K$(PREFIX): "
