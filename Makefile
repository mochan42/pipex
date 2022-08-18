# **************************************************************************** #
# VARIABLES

NAME				:= pipex

CC					:= clang
CFLAGS				:= -Wall -Wextra -Werror -g
RM					:= rm -rf
INCS				:= -I ./inc/
HEADER				:= ./inc/pipex.h

LIBFT_DIR			:= libft
LIBFT_A				:= ./libft/libft.a

FT_PRINTF_DIR		:= ft_printf
FT_PRINTF_A			:= ./ft_printf/ft_printf.a

GET_NEXT_LINE_DIR	:= get_next_line
GET_NEXT_LINE_A		:= ./get_next_line/get_next_line.a

SRC_DIR				:= ./src/
OBJ_DIR				:= ./obj/

# **************************************************************************** #
# COLORS

GREEN				:= \033[0;92m
YELLOW				:= \033[0;93m
BLUE				:= \033[0;94m
END_COLOR			:= \033[0;39m

# **************************************************************************** #
# SOURCES

SRC_FILES			:=	main.c get_paths.c get_commands.c error_arguments.c\
						child_processes.c utils.c parent_process.c

OBJ_FILES			:= ${SRC_FILES:.c=.o}

SRC					:= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ					:= $(addprefix $(OBJ_DIR), $(OBJ_FILES))

# **************************************************************************** #
# RULES

# all :	$(OBJ_DIR) $(NAME)
all : $(NAME)

$(NAME):  $(OBJ_DIR) $(OBJ)
	@echo "$(BLUE)make $(LIBFT_DIR)$(END_COLOR)"
	make -C $(LIBFT_DIR)
	@echo "$(BLUE)make $(FT_PRINTF_DIR)$(END_COLOR)"
	make -C $(FT_PRINTF_DIR)
	@echo "$(BLUE)make $(GET_NEXT_LINE_DIR)$(END_COLOR)"
	make -C $(GET_NEXT_LINE_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_A) $(FT_PRINTF_A) $(GET_NEXT_LINE_A) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled :)$(END_COLOR)"
# -C	:	make option that tells make to change directory before execution.


$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(CFLAGS)  -c $< -o $@ $(INCS)
# -c	:	gcc option to compile each .c file into .o file.
# $<	:	represents the first prerequisite of the rule (each .c file 
#			contained in the src folder).
# -o	:	gcc option to define the name of the program (output) file :
#			"push_swap".
# $@	:	represents the filename of the target of the rule, i.e. each output
#			file which will be linked with the so_long.h header file.

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

clean: 
	$(RM) $(OBJ)
	make clean -C $(LIBFT_DIR)
	make clean -C $(FT_PRINTF_DIR)
	make clean -C $(GET_NEXT_LINE_DIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(OBJ_DIR)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(FT_PRINTF_DIR)
	make fclean -C $(GET_NEXT_LINE_DIR)

re: fclean all
	@echo "$(GREEN) Cleaned all and rebuild $(NAME), $(LIBFT_DIR) $(FT_PRINTF_DIR) and $(GET_NEXT_LINE_DIR)!$(END_COLOR)!"

.PHONY:		all clean fclean re

