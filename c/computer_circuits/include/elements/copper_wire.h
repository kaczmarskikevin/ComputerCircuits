#include <project.h>

#define COPPER_NORTH  0
#define COPPER_SOUTH  1
#define COPPER_EAST   2
#define COPPER_WEST   3
#define COPPER_TOP    4
#define COPPER_BOTTOM 5

typedef struct copper_wire_t {
    struct copper_wire_t* face_north_neighbor;
    struct copper_wire_t* face_south_neighbor;
    struct copper_wire_t* face_east_neighbor;
    struct copper_wire_t* face_west_neighbor;
    struct copper_wire_t* face_top_neighbor;
    struct copper_wire_t* face_bottom_neighbor;

    // We will use positive and negative voltage to determine 
    //  electron flow.
    int face_north_voltage;
    int face_south_voltage;
    int face_east_voltage;
    int face_west_voltage;
    int face_top_voltage;
    int face_bottom_voltage;
};

copper_wire_t* connect_face(copper_wire_t* this_wire, copper_wire_t* neighbor_wire, int face);