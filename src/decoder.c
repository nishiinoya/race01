#include "../inc/header.h"

int invalid_op(const char *s) {
    int number_of_ok = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ')
            continue;

        if (s[i] == '*' || s[i] == '+' || s[i] == '/' || s[i] == '-' || s[i] == '?')
            number_of_ok++;
        else
            return 1; // invalid (unpredicted character)

        if (number_of_ok > 1)
            return 1; // invalid (too many operands)
    }
    if (number_of_ok != 1)
        return 1; // invalid (no operands)
    else
        return 0; // if reached here we have only ' ' and 1 "ok" operand
}
int invalid_n(const char *s) {
    int start = 0;
    for (int i = 0; s[i] != '\0'; i++)
        if (!((s[i] - '0' >= 0 && s[i] - '0' < 10) || s[i] == ' ' || s[i] == '?')) {
            if (s[i] == '-') {
                start++;
                if (start > 1)
                    return 1;
            } else {
                return 1;
            }
        } else {
            if (!start)
                start++;
        }

    return 0;
}
char *format(char *x) {
    int l = 0;
    for (int i = 0; x[i] != '\0'; i++) {
        if (x[i] != ' ')
            l++; // find number of digits or '?';
    }
    char *y = malloc(sizeof(char) * (l + 2));
    int j = 0;
    for (int i = 0; x[i] != '\0'; i++) {
        if (x[i] != ' ') {
            y[j] = x[i];
            j++;
        }
    }
    y[j] = '\0';
    return y;
}
void check(char *operation, char *op1, char *op2, char *res) {
    int o1 = 0;
    for (int i = 0; op1[i] != '\0'; i++) {
        o1 *= 10;
        o1 += (op1[i] != '-' ? op1[i] - '0' : 0);
    }
    if (op1[0] == '-')
        o1 = -o1;
    int o2 = 0;
    for (int i = 0; op2[i] != '\0'; i++) {
        o2 *= 10;
        o2 += (op2[i] != '-' ? op2[i] - '0' : 0);
    }
    if (op2[0] == '-')
        o2 = -o2;
    int r = 0;
    for (int i = 0; res[i] != '\0'; i++) {
        r *= 10;
        r += (res[i] != '-' ? res[i] - '0' : 0);
    }
    if (res[0] == '-')
        r = -r;

    if (*operation == '+') {
        if (o1 + o2 == r) {
            mx_printint(o1);
            mx_printstr(" + ");
            mx_printint(o2);
            mx_printstr(" = ");
            mx_printint(r);
            mx_printchar('\n');
        }
    } else if (*operation == '-') {
        if (o1 - o2 == r) {
            mx_printint(o1);
            mx_printstr(" - ");
            mx_printint(o2);
            mx_printstr(" = ");
            mx_printint(r);
            mx_printchar('\n');
        }
    } else if (*operation == '*') {
        if (o1 * o2 == r) {
            mx_printint(o1);
            mx_printstr(" * ");
            mx_printint(o2);
            mx_printstr(" = ");
            mx_printint(r);
            mx_printchar('\n');
        }
    }
    if (*operation == '/') {
        if (o1 / o2 == r) {
            mx_printint(o1);
            mx_printstr(" / ");
            mx_printint(o2);
            mx_printstr(" = ");
            mx_printint(r);
            mx_printchar('\n');
        }
    }
}
void process(char *operation, char *op1, char *op2, char *res) {
    int no_questions = 1;
    if (operation[0] == '?') {
        no_questions = 0;
        operation[0] = '+';
        process(operation, op1, op2, res);
        operation[0] = '-';
        process(operation, op1, op2, res);
        operation[0] = '*';
        process(operation, op1, op2, res);
        operation[0] = '/';
        process(operation, op1, op2, res);
    }
    if (no_questions) {
        for (int i = 0; op1[i] != '\0'; i++) {
            if (op1[i] == '?') {
                no_questions = 0;
                for (char j = '0'; j <= '9'; j++) {
                    op1[i] = j;
                    process(operation, op1, op2, res);
                }
                op1[i] = '?';
                break;
            }
        }
    }
    if (no_questions) {
        for (int i = 0; op2[i] != '\0'; i++) {
            if (op2[i] == '?') {
                no_questions = 0;
                for (char j = '0'; j <= '9'; j++) {
                    op2[i] = j;
                    process(operation, op1, op2, res);
                }
                op2[i] = '?';
                break;
            }
        }
    }
    if (no_questions) {
        for (int i = 0; res[i] != '\0'; i++) {
            if (res[i] == '?') {
                no_questions = 0;
                for (char j = '0'; j <= '9'; j++) {
                    res[i] = j;
                    process(operation, op1, op2, res);
                }
                res[i] = '?';
                break;
            }
        }
    }
    if (no_questions) {
        check(operation, op1, op2, res);
    }
}
