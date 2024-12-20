NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g #REMOVE FLAG GDB

OBJ_DIR = obj
LIBFT = LIBFT/libft.a

SRCS = \
	parsing.c \
	push_swap_operators.c \
	sort_small.c \
	push_swap_utils.c \
	algo.c \
	algo_utils.c \
	main.c \
	counting.c \
	parsing_utils.c

OBJS = \
	$(OBJ_DIR)/parsing.o \
	$(OBJ_DIR)/push_swap_operators.o \
	$(OBJ_DIR)/sort_small.o \
	$(OBJ_DIR)/algo.o \
	$(OBJ_DIR)/push_swap_utils.o \
	$(OBJ_DIR)/parsing_utils.o \
	$(OBJ_DIR)/algo_utils.o \
	$(OBJ_DIR)/counting.o \
	$(OBJ_DIR)/main.o

# Cible par défaut
all: $(LIBFT) $(NAME)

# Compilation de push_swap avec libft
$(NAME): $(OBJS) $(LIBFT)
	@echo "Linking $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L./LIBFT -lft

# Compilation des fichiers objets dans le dossier obj
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@echo "Compiling $(notdir $<)..."
	@$(CC) $(CFLAGS) -I. -I LIBFT/ -o $@ -c $<  # Ajout de -I. pour inclure le répertoire racine

# Appel du Makefile de LIBFT pour générer libft.a
$(LIBFT):
	@echo "Building libft..."
	@$(MAKE) -C LIBFT

# Suppression des fichiers objets
clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJ_DIR)

# Suppression des fichiers objets et de libft.a
lclean:
	@echo "Cleaning libraries..."
	@$(MAKE) -C LIBFT fclean

# Suppression de tout (fichiers objets et libft.a)
fclean: clean lclean
	@echo "Cleaning executable $(NAME)..."
	@rm -f $(NAME)

# Reconstruction complète
re: fclean all

.PHONY: all clean fclean lclean re
