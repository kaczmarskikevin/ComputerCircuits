#include <project.h>

int type_hello_world(void) {
    printf("Loaded %s-%s\n", __FILE__, __FUNCTION__);

    return EXIT_SUCCESS;;
}