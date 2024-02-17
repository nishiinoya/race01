#include <stdbool.h>

void printerr(const char *s);

bool mx_isdigit(int c);

bool mx_str_isdigit(char *arr);

int mx_atoi(const char *str);

int mx_strlen(const char *s);

char *mx_remove_spaces(char *str);

int error_handling(int argc, char *argv[]) {
    if (argc < 5) {
        printerr("usage: ./part_of_the_matrix [operand] [operation] [operand2] [result]\n");
        return 0;
    }
    char *operation = mx_remove_spaces(argv[2]);
	if (mx_strlen(operation) != 1){
		printerr("Invalid operator: ");
		printerr(operation);
		printerr("\n");
		return 0;
	}
	else if( *operation != '+' && *operation != '-' && *operation != '/' && *operation != '*' && *operation != '?') {
		printerr("Invalid operator: ");
		printerr(operation);
		printerr("\n");
		return 0;
	}
    char *operand1 = mx_remove_spaces(argv[1]);
    char *operand2 = mx_remove_spaces(argv[3]);
    char *result = mx_remove_spaces(argv[4]);
    if (!mx_str_isdigit(operand1)) {
        printerr("Invalid operand: ");
        printerr(operand1);
        printerr("\n");
        return 0;
    }
    if (!mx_str_isdigit(operand2)) {
        printerr("Invalid operand: ");
        printerr(operand2);
        printerr("\n");
        return 0;
    }
    if (!mx_str_isdigit(result)) {
        printerr("Invalid result: ");
        printerr(result);
        printerr("\n");
        return 0;
    }
    if(mx_atoi(operand2) == 0 && *operation == '/'){
		return 0;
	}

    return 1;
}

bool mx_str_isdigit(char *arr) {
    for (int i = 0; arr[i] != '\0'; i++) {
        if (!mx_isdigit(arr[i]) && arr[i] != '-' && arr[i] != '?') {
            return false;
        }
    }
    return true;
}

