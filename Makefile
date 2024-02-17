CC := clang
CFLAGS := -std=c11 -Wall -Wextra -Werror -Wpedantic

PROJECT := DECRYPT_MATH_EXPR
EXECUTABLE := part_of_the_matrix

.PHONY: all clean uninstall reinstall

all: $(PROJECT)

$(PROJECT):
	mkdir -p ./obj
	$(CC) $(CFLAGS) -c ./src/*.c
	mv ./*.o ./obj
	$(CC) $(CFLAGS) -o $(EXECUTABLE) ./obj/*.o

uninstall:
	rm -rf ./obj
	rm -rf $(EXECUTABLE)

clean:
	rm -rf ./obj

reinstall: uninstall $(PROJECT)
