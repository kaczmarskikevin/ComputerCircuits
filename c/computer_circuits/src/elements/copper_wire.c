#include <stdio.h>
#include <stdlib.h>
#include <elements/copper_wire.h>

int connect_face(copper_wire_t* this_wire, copper_wire_t* neighbor_wire, int face) {
    printf("Loaded %s-%s\n", __FILE__, __FUNCTION__);

    switch (face) {
        case COPPER_NORTH:
            printf("Copper wire %p has been connected to copper wire %p on the north face\n", neighbor_wire, this_wire);
            break;
        case COPPER_SOUTH:
            printf("Copper wire %p has been connected to copper wire %p on the south face\n", neighbor_wire, this_wire);
            break;
        case COPPER_EAST:
            printf("Copper wire %p has been connected to copper wire %p on the east face\n", neighbor_wire, this_wire);
            break;
        case COPPER_WEST:
            printf("Copper wire %p has been connected to copper wire %p on the west face\n", neighbor_wire, this_wire);
            break;
        case COPPER_TOP:
            printf("Copper wire %p has been connected to copper wire %p on the top face\n", neighbor_wire, this_wire);
            break;
        case COPPER_BOTTOM:
            printf("Copper wire %p has been connected to copper wire %p on the bottom face\n", neighbor_wire, this_wire);
            break;
        default:
            printf("Error: Could not connect the wires.\n");
            return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
