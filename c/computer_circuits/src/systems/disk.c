#include <stdio.h>
#include <stdlib.h>
#include <systems/disk.h>

int start_disk(void) {
    printf("Loaded %s-%s\n", __FILE__, __FUNCTION__);

    return EXIT_SUCCESS;
}