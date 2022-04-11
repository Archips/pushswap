# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvidon <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 15:04:55 by cvidon            #+#    #+#              #
#    Updated: 2022/04/06 16:37:03 by cvidon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ========== [ Project files ]

# TODO set name
PREFIX		= push_swap
NAME		= $(PREFIX)
NAME_BONUS	= checker

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
			  operations_1.c		\
			  operations_2.c		\
			  algo/pre_sort.c		\
			  algo/senpai.c			\
			  algo/costs.c			\
			  algo/id.c			\
			  algo/moves.c			\
			  algo/sort.c			\
			  algo/smallsort.c		\
			  security.c			\
			  listutils_1.c			\
			  listutils_2.c			\
			  listutils_3.c			\
			  char_listutils.c
SRCS		:= $(SRCS:%=$(SRC_DIR)/%)

SRC_DIR_BONUS		= src
SRCS_BONUS		= checker/main_bonus.c		\
			checker/checker_bonus.c		\
			checker/get_next_line_bonus.c		\
			checker/get_next_line_utils_bonus.c	\
			checker/push_bonus.c			\
			checker/reverse_bonus.c		\
			checker/rotate_bonus.c		\
			checker/swap_bonus.c			\
			parse_args.c			\
			check_args.c			\
			security.c			\
			listutils_1.c			\
			listutils_2.c			\
			listutils_3.c			

SRCS_BONUS		:= $(SRCS_BONUS:%=$(SRC_DIR_BONUS)/%)

OBJ_DIR 	= obj
OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

OBJ_DIR_BONUS 	= obj_bonus
OBJS_BONUS	= $(SRCS_BONUS:$(SRC_DIR_BONUS)/%.c=$(OBJ_DIR_BONUS)/%.o)

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
MAKE	= make -j -C

# ========== [ Recipe ]

.PHONY: all debug clean fclean norm update re leaks run

all: $(NAME)

debug: CPPFLAGS	:= $(CPPFLAGS) -D PINFO=1
debug: NAME := $(NAME)
debug: $(NAME)

sani: CFLAGS := $(CFLAGS) -fsanitize=address,undefined,signed-integer-overflow
sani: debug

$(NAME): $(OBJS)
	@for f in $(LIB); do $(MAKE) $$f --no-print-directory; done
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)
	@$(ECHO)"$(G)created $(END)$(NAME)\n"

bonus : $(OBJS_BONUS)
	@for f in $(LIB); do $(MAKE) $$f --no-print-directory; done
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(OBJS_BONUS) $(LDLIBS) -o $(NAME_BONUS)
	@$(ECHO)"$(G)created $(END)$(NAME_BONUS)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@[ ! -d $(@D) ] && mkdir -p  $(@D) || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@$(ECHO)"$(G)created $(END)$@"

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c
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
	@sh ./test/test.sh

leak: fclean debug
	@sh ./test/leak.sh

t: fclean sanitize
	@echo "---[ ?? ]"
	./push_swap "1 2 3" "4" " 32 1 "

l: fclean debug
	@echo "---[ ?? ]"
	./push_swap ""

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
