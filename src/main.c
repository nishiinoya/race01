#include "../inc/header.h"

int main(int argc, char *argv[]) {
    error_handling(argc, argv);

    char *operation= format(argv[2]);
    char *op1 = format(argv[1]);
    char *op2 = format(argv[3]);
    char *res = format(argv[4]);

    process(operation, op1, op2, res);
    
    free(op1);
    op1 = NULL;
    free(operation);
    operation = NULL;
    free(op2);
    op2 = NULL;
    free(res);
    res = NULL;
    return 0;
}
