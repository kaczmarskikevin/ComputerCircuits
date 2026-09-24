#include <stdio.h>
#include <stdlib.h>
#include <systems/computer.h>
#include <systems/monitor.h>
#include <systems/keyboard.h>

int main(void) {
    printf("Loaded %s-%s\n", __FILE__, __FUNCTION__);

    start_computer();
    start_monitor();
    plug_in_monitor();
    plug_in_keyboard();
    type_hello_world();
    display_to_screen();
    shutdown_computer();

    return EXIT_SUCCESS;
}