#include <stdio.h>
#include <stdlib.h>
#include <systems/operating_system.h>

int load_operating_system(void) {
    printf("Loaded %s-%s\n", __FILE__, __FUNCTION__);
    
    return EXIT_SUCCESS;
}