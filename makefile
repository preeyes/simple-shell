CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = src
OBJ = obj
TARGET = my_shell

# List all source files in SRC directory
SRC_FILES = $(wildcard $(SRC)/*.c)

# Create a list of object files in OBJ directory
OBJ_FILES = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRC_FILES))

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ_FILES)

# Rule to compile source files into object files in obj directory
$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)/*.o $(TARGET)

run: all
	./$(TARGET)
