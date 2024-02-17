#ifndef HEADER_H
#define HEADER_H

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

void error_handling(int argc, char *argv[]);
void mx_printint(int n);
void mx_printchar(char c);
int mx_atoi(const char *str);
bool mx_isdigit(int c);
bool mx_isspace(char c);
void mx_printerr(const char *s);
void mx_printstr(const char *s);
char *mx_remove_spaces(const char *str);
bool mx_str_isdigit(char *arr);
int mx_strlen(const char *s);
void process(char *operation, char * op1, char *op2, char *res);
void check(char *operation, char * op1, char *op2, char *res);
char *format(char *x);
int invalid_n(const char *s);
int invalid_op(const char *s);

#endif
