#include <stdio.h>
#include <stdlib.h>
#include <systems/monitor.h>

int start_monitor(void) {
    printf("Loaded %s-%s\n", __FILE__, __FUNCTION__);

    return EXIT_SUCCESS;
}