#include <stdio.h>
#include <stdlib.h>
#include <elements/element.h>

#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int connect_face(element_t* this_element, element_t* neighbor_element, int face) {
    switch (face) {
        case NORTH_FACE:
            this_element->face_north_neighbor     = neighbor_element;
            neighbor_element->face_south_neighbor = this_element;
            printf("Copper wire %p has been connected to copper wire %p on the north face\n", neighbor_element, this_element);
            break;
        case SOUTH_FACE:
            this_element->face_south_neighbor     = neighbor_element;
            neighbor_element->face_north_neighbor = this_element;
            printf("Copper wire %p has been connected to copper wire %p on the south face\n", neighbor_element, this_element);
            break;
        case EAST_FACE:
            this_element->face_east_neighbor     = neighbor_element;
            neighbor_element->face_west_neighbor = this_element;
            printf("Copper wire %p has been connected to copper wire %p on the east face\n", neighbor_element, this_element);
            break;
        case WEST_FACE:
            this_element->face_west_neighbor     = neighbor_element;
            neighbor_element->face_east_neighbor = this_element;
            printf("Copper wire %p has been connected to copper wire %p on the west face\n", neighbor_element, this_element);
            break;
        case TOP_FACE:
            this_element->face_top_neighbor     = neighbor_element;
            neighbor_element->face_bottom_neighbor = this_element;
            printf("Copper wire %p has been connected to copper wire %p on the top face\n", neighbor_element, this_element);
            break;
        case BOTTOM_FACE:
            this_element->face_bottom_neighbor     = neighbor_element;
            neighbor_element->face_top_neighbor = this_element;
            printf("Copper wire %p has been connected to copper wire %p on the bottom face\n", neighbor_element, this_element);
            break;
        default:
            printf("Error: Could not connect the wires.\n");
            return 0;
    }

    return 1;
}

int update_voltage(element_t* this_element){

    if( this_element->face_north_neighbor != NULL ) {
        this_element->nanoamperes = (this_element->nanoamperes < this_element->face_north_neighbor->nanoamperes) ? this_element->face_north_neighbor->nanoamperes : this_element->nanoamperes;
    }

    if( this_element->face_south_neighbor != NULL ) {
        this_element->nanoamperes = (this_element->nanoamperes < this_element->face_south_neighbor->nanoamperes) ? this_element->face_south_neighbor->nanoamperes : this_element->nanoamperes;
    }

    if( this_element->face_east_neighbor != NULL ) {
        this_element->nanoamperes = (this_element->nanoamperes < this_element->face_east_neighbor->nanoamperes) ? this_element->face_east_neighbor->nanoamperes : this_element->nanoamperes;
    }

    if( this_element->face_west_neighbor != NULL ) {
        this_element->nanoamperes = (this_element->nanoamperes < this_element->face_west_neighbor->nanoamperes) ? this_element->face_west_neighbor->nanoamperes : this_element->nanoamperes;
    }

    if( this_element->face_top_neighbor != NULL ) {
        this_element->nanoamperes = (this_element->nanoamperes < this_element->face_top_neighbor->nanoamperes) ? this_element->face_top_neighbor->nanoamperes : this_element->nanoamperes;
    }

    if( this_element->face_bottom_neighbor != NULL ) {
        this_element->nanoamperes = (this_element->nanoamperes < this_element->face_bottom_neighbor->nanoamperes) ? this_element->face_bottom_neighbor->nanoamperes : this_element->nanoamperes;
    }

    return 1;
}

int inspect_wire(element_t* this_element){

    element_t* north_neighbor = (this_element->face_north_neighbor) ? this_element->face_north_neighbor: NULL;
    element_t* south_neighbor = (this_element->face_south_neighbor) ? this_element->face_south_neighbor: NULL;
    element_t* east_neighbor = (this_element->face_east_neighbor) ? this_element->face_east_neighbor: NULL;
    element_t* west_neighbor = (this_element->face_west_neighbor) ? this_element->face_west_neighbor: NULL;
    element_t* top_neighbor = (this_element->face_top_neighbor) ? this_element->face_top_neighbor: NULL;
    element_t* bottom_neighbor = (this_element->face_bottom_neighbor) ? this_element->face_bottom_neighbor: NULL;

    element_t* north_neighbor_south_neighbor = (north_neighbor) ? north_neighbor->face_south_neighbor : NULL;
    element_t* south_neighbor_north_neighbor = (south_neighbor) ? south_neighbor->face_north_neighbor : NULL;
    element_t* east_neighbor_west_neighbor = (east_neighbor) ? east_neighbor->face_west_neighbor : NULL;
    element_t* west_neighbor_east_neighbor = (west_neighbor) ? west_neighbor->face_east_neighbor : NULL;
    element_t* top_neighbor_bottom_neighbor = (top_neighbor) ? top_neighbor->face_bottom_neighbor : NULL;
    element_t* bottom_neighbor_top_neighbor = (bottom_neighbor) ? bottom_neighbor->face_top_neighbor : NULL;

    const char *north_null_color  = (north_neighbor) 
                                ? ANSI_COLOR_GREEN : ANSI_COLOR_RED;

    const char *south_null_color  = (south_neighbor) 
                                ? ANSI_COLOR_GREEN : ANSI_COLOR_RED;

    const char *east_null_color   = (east_neighbor) 
                                ? ANSI_COLOR_GREEN : ANSI_COLOR_RED;

    const char *west_null_color   = (west_neighbor) 
                                ? ANSI_COLOR_GREEN : ANSI_COLOR_RED;

    const char *top_null_color    = (top_neighbor) 
                                ? ANSI_COLOR_GREEN : ANSI_COLOR_RED;

    const char *bottom_null_color = (bottom_neighbor) 
                                ? ANSI_COLOR_GREEN : ANSI_COLOR_RED;

    const char *north_face_color  = (north_neighbor_south_neighbor == this_element) 
                                ? ANSI_COLOR_GREEN : ANSI_COLOR_RED;

    const char *south_face_color  = (south_neighbor_north_neighbor == this_element) 
                                ? ANSI_COLOR_GREEN : ANSI_COLOR_RED;

    const char *east_face_color   = (east_neighbor_west_neighbor == this_element) 
                                ? ANSI_COLOR_GREEN : ANSI_COLOR_RED;

    const char *west_face_color   = (west_neighbor_east_neighbor == this_element) 
                                ? ANSI_COLOR_GREEN : ANSI_COLOR_RED;

    const char *top_face_color    = (top_neighbor_bottom_neighbor == this_element) 
                                ? ANSI_COLOR_GREEN : ANSI_COLOR_RED;

    const char *bottom_face_color = (bottom_neighbor_top_neighbor == this_element) 
                                ? ANSI_COLOR_GREEN : ANSI_COLOR_RED;


    printf("*************************************************************************************************************\n");
    printf("*                                                                                                           *\n");
    printf("*                                              *******************                                          *\n");
    printf("*                                              **  COPPER WIRE  **                                          *\n");
    printf("*                                              *******************                                          *\n");
    printf("*                                                                                                           *\n");
    printf("*                               ********************** **********************                               *\n");
    printf("*                               **                  ** **                  **                               *\n");
    printf("*                               **  %s%p%s  ** **  %s%p%s  **                               *\n", top_null_color, top_neighbor, ANSI_COLOR_RESET, north_null_color, north_neighbor, ANSI_COLOR_RESET);
    printf("*                               **                  ** **                  **                               *\n");
    printf("*                               ********************** **********************                               *\n");
    printf("*                                           ^                     ^                                         *\n");
    printf("*                                           |                     |                                         *\n");
    printf("*                                           |                     |                                         *\n");
    printf("*                                           v                     v                                         *\n");
    printf("*                               ********************** **********************                               *\n");
    printf("*                               **       TOP        ** **       NORTH      **                               *\n");
    printf("*                               **  %s%p%s  ** **  %s%p%s  **                               *\n", top_face_color, top_neighbor_bottom_neighbor, ANSI_COLOR_RESET, north_face_color, north_neighbor_south_neighbor, ANSI_COLOR_RESET);
    printf("*                               **                  ** **                  **                               *\n");
    printf("*                               ********************** **********************                               *\n");
    printf("*                                                                                                           *\n");
    printf("*  **********************       ********************** **********************       **********************  *\n");
    printf("*  **                  **       **       WEST       ** **       EAST       **       **                  **  *\n");
    printf("*  **  %s%p%s  ** <---> **  %s%p%s  ** **  %s%p%s  ** <---> **  %s%p%s  **  *\n", west_null_color, west_neighbor, ANSI_COLOR_RESET, west_face_color, west_neighbor_east_neighbor, ANSI_COLOR_RESET, east_face_color, east_neighbor_west_neighbor, ANSI_COLOR_RESET, east_null_color, east_neighbor, ANSI_COLOR_RESET);
    printf("*  **                  **       **                  ** **                  **       **                  **  *\n");
    printf("*  **********************       ********************** **********************       **********************  *\n");
    printf("*                                                                                                           *\n");
    printf("*                               ********************** **********************                               *\n");
    printf("*                               **      SOUTH       ** **      BOTTOM      **                               *\n");
    printf("*                               **  %s%p%s  ** **  %s%p%s  **                               *\n", south_face_color, south_neighbor_north_neighbor,ANSI_COLOR_RESET, bottom_face_color, bottom_neighbor_top_neighbor, ANSI_COLOR_RESET);
    printf("*                               **                  ** **                  **                               *\n");
    printf("*                               ********************** **********************                               *\n");
    printf("*                                           ^                      ^                                        *\n");
    printf("*                                           |                      |                                        *\n");
    printf("*                                           |                      |                                        *\n");
    printf("*                                           v                      v                                        *\n");
    printf("*                               ********************** **********************                               *\n");
    printf("*                               **                  ** **                  **                               *\n");
    printf("*                               **  %s%p%s  ** **  %s%p%s  **                               *\n", south_null_color, south_neighbor, ANSI_COLOR_RESET, bottom_null_color, bottom_neighbor, ANSI_COLOR_RESET);
    printf("*                               **                  ** **                  **                               *\n");
    printf("*                               ********************** **********************                               *\n");
    printf("*                                                                                                           *\n");
    printf("*************************************************************************************************************\n");
    return 1;
}