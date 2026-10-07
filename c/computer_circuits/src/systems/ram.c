#include <stdio.h>
#include <stdlib.h>
#include <systems/ram.h>

int read(void) {
    printf("Loaded %s-%s\n", __FILE__, __FUNCTION__);

    return EXIT_SUCCESS;
}