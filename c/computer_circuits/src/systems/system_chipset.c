int start_system_chipset(void) {
    printf("Loaded %s-%s\n", __FILE__, __FUNCTION__);

    start_cpu();

    return 0;
}