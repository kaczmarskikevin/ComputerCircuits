#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// elements/copper_wire.c

#define COPPER_NORTH  0
#define COPPER_SOUTH  1
#define COPPER_EAST   2
#define COPPER_WEST   3
#define COPPER_TOP    4
#define COPPER_BOTTOM 5

typedef struct copper_wire {
    struct copper_wire* face_north_neighbor;
    struct copper_wire* face_south_neighbor;
    struct copper_wire* face_east_neighbor;
    struct copper_wire* face_west_neighbor;
    struct copper_wire* face_top_neighbor;
    struct copper_wire* face_bottom_neighbor;

    // We will use positive and negative voltage to determine 
    //  electron flow.
    int face_north_voltage;
    int face_south_voltage;
    int face_east_voltage;
    int face_west_voltage;
    int face_top_voltage;
    int face_bottom_voltage;
} copper_wire_t;

int start_computer(void);
int start_cpu(void);
int start_monitor(void);
int plug_in_monitor(void);
int plug_in_keyboard(void);
int type_hello_world(void);
int display_to_screen(void);
int shutdown_computer(void);
int read_reset_vector(void);
int read_instruction(int);
int start_system_chipset(void);