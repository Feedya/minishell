# Compilateur
CC = gcc

# Options de compilation
CFLAGS = -Wall -Wextra -Werror

# Nom de l'exécutable
TARGET = prog

# Fichiers sources (tous les fichiers .c dans le répertoire courant)
SRCS = $(wildcard *.c)

# Fichiers objets (générés à partir des fichiers sources)
OBJS = $(SRCS:.c=.o)

# Règle par défaut
all: $(TARGET)

# Règle pour créer l'exécutable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Règle pour compiler chaque fichier .c en .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Règle pour nettoyer les fichiers générés
clean:
	rm -f $(OBJS) $(TARGET)

# Règle pour recompiler depuis zéro
re: clean all

# Indique que les règles "all", "clean" et "re" ne sont pas des fichiers
.PHONY: all clean re