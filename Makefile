C_PURPLE_B		=\033[1;95m
C_YELLOW_B		=\033[1;33m
C_RED_B			=\033[1;31m
C_WHITE			=\033[0;97m
C_GREEN			=\033[0;32m
C_GREEN_B		=\033[1;32m
C_RESET			=\033[0m

COMPILER	= g++
RM			= rm -f
RMF			= rm -rf
GCCFLAGS	= -Wall -Wextra -Werror

NAME		= tracker

SRCS		= main.cpp

OBJ_DIR		= objs
OBJ_FILES	= $(SRCS:.cpp=.o)
OBJS		= $(addprefix $(OBJ_DIR)/,$(OBJ_FILES))

all:	$(NAME)

$(OBJ_DIR)/%.o: %.cpp
			@mkdir -p $(dir $@)
			@printf "$(C_GREEN).$(C_RESET)";
			@$(COMPILER) $(CPPFLAGS) -c $< -o $@


$(NAME):	$(OBJS)
			@$(COMPILER) $(CPPFLAGS) $(OBJS) -o $(NAME)
			@printf "\n$(C_GREEN_B)Finished!$(C_RESET)\n";

clean:
			@echo "$(C_RED_B)Deleting $(NAME) o-files...$(C_RESET)";
			@$(RM) $(OBJS)
			@$(RMF) $(OBJ_DIR)
			@echo "$(C_RED_B)Done!$(C_RESET)";

fclean:		clean
			@echo "$(C_RED_B)Deleting $(NAME) binary...$(C_RESET)";
			@$(RM) $(NAME)
			@echo "$(C_RED_B)Done!$(C_RESET)";

re:			fclean all

.PHONY:		all clean fclean re val run