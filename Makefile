TARGET = part_of_the_matrix
SRC_DIR = src
INC_DIR = inc
CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: $(TARGET)

$(TARGET): $(SRC_DIR)/*.c $(INC_DIR)/*.h
	$(CC) $(CFLAGS) -I$(INC_DIR) -o $(TARGET) $(SRC_DIR)/*.c

clean:
	rm -f $(TARGET)

uninstall: clean

reinstall: uninstall all
