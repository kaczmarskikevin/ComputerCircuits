#include <project.h>

int start_system_chipset(void) {
    printf("Loaded %s-%s\n", __FILE__, __FUNCTION__);

    start_cpu();

    return EXIT_SUCCESS;;
}