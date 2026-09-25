#include <stdio.h>
#include <stdlib.h>
#include <elements/copper_wire.h>
#include <tests/elements/copper_wire.h>

// Connect all wires to all faces.
int copper_wire_connections(void) {

    copper_wire_t main_wire_obj = {0}; 
    copper_wire_t north_obj = {0}, south_obj = {0}, east_obj = {0};
    copper_wire_t west_obj = {0}, top_obj = {0}, bottom_obj = {0};

    copper_wire_t* main_wire   = &main_wire_obj;
    copper_wire_t* north_wire  = &north_obj;
    copper_wire_t* south_wire  = &south_obj;
    copper_wire_t* east_wire   = &east_obj;
    copper_wire_t* west_wire   = &west_obj;
    copper_wire_t* top_wire    = &top_obj;
    copper_wire_t* bottom_wire = &bottom_obj;

    int result = EXIT_SUCCESS;

    result |= connect_face(main_wire, north_wire,  COPPER_NORTH);
    result |= connect_face(main_wire, south_wire,  COPPER_SOUTH);
    result |= connect_face(main_wire, east_wire,   COPPER_EAST);
    result |= connect_face(main_wire, west_wire,   COPPER_WEST);
    result |= connect_face(main_wire, top_wire,    COPPER_TOP);
    result |= connect_face(main_wire, bottom_wire, COPPER_BOTTOM);

    return result; 
}

//Connect the north wire to a face that doesn't exist.
int copper_wire_connections_error(void) {

    copper_wire_t main_wire_obj = {0}; 
    copper_wire_t north_obj = {0};

    copper_wire_t* main_wire   = &main_wire_obj;
    copper_wire_t* north_wire  = &north_obj;

    int result = EXIT_SUCCESS;

    result |= connect_face(main_wire, north_wire,  99);

    return !result; 
}

//
int copper_wire_power_draw(void){
    return EXIT_SUCCESS;
}

int copper_wire_power_draw_error(void){
    return EXIT_SUCCESS;
}

int copper_wire_power_release(void){
    return EXIT_SUCCESS;
}

int copper_wire_power_release_error(void){
    return EXIT_SUCCESS;
}