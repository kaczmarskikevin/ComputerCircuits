#define COPPER_NORTH  0
#define COPPER_SOUTH  1
#define COPPER_EAST   2
#define COPPER_WEST   3
#define COPPER_TOP    4
#define COPPER_BOTTOM 5

#define AWG 28
#define SAFEAMPS 1
#define BURNAMPS 10
#define WIREDIAMETER 321 //PICOMETERS

//Power Loss = Current Squared * Resistance
// P = I^2 * R


typedef struct copper_wire {
    struct copper_wire* face_north_neighbor;
    struct copper_wire* face_south_neighbor;
    struct copper_wire* face_east_neighbor;
    struct copper_wire* face_west_neighbor;
    struct copper_wire* face_top_neighbor;
    struct copper_wire* face_bottom_neighbor;

    long long femtoamperes;
} copper_wire_t;

int connect_face(copper_wire_t* this_wire, copper_wire_t* neighbor_wire, int face);

int update_current(copper_wire_t* this_wire, long long femtoamperes);

int inspect_wire(copper_wire_t* this_wire);