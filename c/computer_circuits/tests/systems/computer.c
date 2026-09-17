int start_computer(void) {
    printf("Loaded %s-%s\n", __FILE__, __FUNCTION__);

    start_bios();
    start_disk();
    start_operating_system();

    return 0;
}

int plug_in_keyboard(void) {
    printf("Loaded %s-%s\n", __FILE__, __FUNCTION__);

    return 0;
}