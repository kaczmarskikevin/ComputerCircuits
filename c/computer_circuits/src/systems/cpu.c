#define BIOS_ADDRESS 0

int start_cpu(void) {
    printf("Loaded %s-%s\n", __FILE__, __FUNCTION__);

    read_reset_vector();

    return 0;
}

int read_reset_vector(void) {
    printf("Loaded %s-%s\n", __FILE__, __FUNCTION__);

    read_instruction(BIOS_ADDRESS);

    return 0;
}

int read_instruction(int address) {
    printf("Loaded %s-%s\n", __FILE__, __FUNCTION__);

    printf("Successfully read instruction at %d\n", address);

    return 0;
}