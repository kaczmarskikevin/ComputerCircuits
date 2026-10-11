#define NORTH_FACE  0
#define SOUTH_FACE  1
#define EAST_FACE   2
#define WEST_FACE   3
#define TOP_FACE    4
#define BOTTOM_FACE 5

#define AWG 28 //Smallest common hobbyist copper wire size
#define SAFENANOAMPS 1000000000 // 1 amp
#define BURNNANOAMPS 10000000000 // 10 amps
#define WIREDIAMETER 321000000 //PICOMETERS
#define CROSSSECTIONALAREA 81000000000000000 // square picometers
#define COPPERRESISTANCE 168000000000000000 * (WIREDIAMETER/CROSSSECTIONALAREA) // R = p(L/A) where p = 168000000000000000 OHMS * PICOMETER at 20 C

//Power Loss = Current Squared * Resistance
// P = I^2 * R

// Can be a copper wire or a resistor
typedef struct element {
    struct element* face_north_neighbor;
    struct element* face_south_neighbor;
    struct element* face_east_neighbor;
    struct element* face_west_neighbor;
    struct element* face_top_neighbor;
    struct element* face_bottom_neighbor;

    // Types: Copper Wire, Resistor, N Type Transistor, P Type Transistor
    char* type;
    long long nanoamperes;
    long long microvolts;
    long long resistance;
} element_t;

int connect_face(element_t* this_element, element_t* neighbor_element, int face);

int update_current(element_t* this_element, long long nanoamperes);

int inspect_wire(element_t* this_element);