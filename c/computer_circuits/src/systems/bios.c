#include <stdio.h>
#include <stdlib.h>
#include <systems/bios.h>

int read_bios(void) {
    printf("Loaded %s-%s\n", __FILE__, __FUNCTION__);

    return EXIT_SUCCESS;
}