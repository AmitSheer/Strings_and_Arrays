#include <stdio.h>
#include "isort.h"
#include "txtfind.h"

int ccv(int* a){
    printf(" %c", *(a));
    return 1;
}
int main(int argc, char **argv){
    for (int i = 0; i < argc; ++i)
    {
        printf("argv[%d]: %s\n", i, argv[i]);
    }
}