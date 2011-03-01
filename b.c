#include <stdio.h>

void main(int argc, char**argv) {
    int i;

    // Prints arguments
    for (i = 0; i < argc; i++) {
        printf("%i: %s\n", i, argv[i]);
    }
}

