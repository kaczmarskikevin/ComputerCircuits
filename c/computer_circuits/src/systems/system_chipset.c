#include <stdio.h>
#include <stdlib.h>
#include <systems/system_chipset.h>
#include <systems/cpu.h>

int start_system_chipset(void) {
    printf("Loaded %s-%s\n", __FILE__, __FUNCTION__);

    start_cpu();

    return EXIT_SUCCESS;
}