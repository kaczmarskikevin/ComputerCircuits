#include <project.h>

int start_computer(void) {
    printf("Loaded %s-%s\n", __FILE__, __FUNCTION__);

    start_system_chipset();

    return 0;
}

int plug_in_keyboard(void) {
    printf("Loaded %s-%s\n", __FILE__, __FUNCTION__);

    return 0;
}

int plug_in_monitor(void) {
    printf("Loaded %s-%s\n", __FILE__, __FUNCTION__);

    return 0;
}

int display_to_screen(void) {
    printf("Loaded %s-%s\n", __FILE__, __FUNCTION__);

    return 0;
}

int shutdown_computer(void) {
    printf("Loaded %s-%s\n", __FILE__, __FUNCTION__);

    return 0;
}