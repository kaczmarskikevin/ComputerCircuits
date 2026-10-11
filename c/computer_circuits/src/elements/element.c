#include <stdio.h>
#include <stdlib.h>
#include <elements/element.h>

#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int connect_neighbor(element_t* source, element_t* neighbor, int face) {
    switch (face) {
        case NORTH:
            source->north_neighbor   = neighbor;
            neighbor->south_neighbor = source;
            printf("Copper wire %p has been connected to copper wire %p on the north face\n", neighbor, source);
            break;
        case SOUTH:
            source->south_neighbor   = neighbor;
            neighbor->north_neighbor = source;
            printf("Copper wire %p has been connected to copper wire %p on the south face\n", neighbor, source);
            break;
        case EAST:
            source->east_neighbor   = neighbor;
            neighbor->west_neighbor = source;
            printf("Copper wire %p has been connected to copper wire %p on the east face\n", neighbor, source);
            break;
        case WEST:
            source->west_neighbor   = neighbor;
            neighbor->east_neighbor = source;
            printf("Copper wire %p has been connected to copper wire %p on the west face\n", neighbor, source);
            break;
        case TOP:
            source->top_neighbor      = neighbor;
            neighbor->bottom_neighbor = source;
            printf("Copper wire %p has been connected to copper wire %p on the top face\n", neighbor, source);
            break;
        case BOTTOM:
            source->bottom_neighbor = neighbor;
            neighbor->top_neighbor  = source;
            printf("Copper wire %p has been connected to copper wire %p on the bottom face\n", neighbor, source);
            break;
        default:
            printf("Error: Could not connect the wires.\n");
            return 0;
    }

    return 1;
}

int inspect_element(element_t* source){

    element_t* north_neighbor  = (source->north_neighbor) ? source->north_neighbor: NULL;
    element_t* south_neighbor  = (source->south_neighbor) ? source->south_neighbor: NULL;
    element_t* east_neighbor   = (source->east_neighbor) ? source->east_neighbor: NULL;
    element_t* west_neighbor   = (source->west_neighbor) ? source->west_neighbor: NULL;
    element_t* top_neighbor    = (source->top_neighbor) ? source->top_neighbor: NULL;
    element_t* bottom_neighbor = (source->bottom_neighbor) ? source->bottom_neighbor: NULL;

    element_t* north_neighbor_south_neighbor = (north_neighbor) ? north_neighbor->south_neighbor : NULL;
    element_t* south_neighbor_north_neighbor = (south_neighbor) ? south_neighbor->north_neighbor : NULL;
    element_t* east_neighbor_west_neighbor   = (east_neighbor) ? east_neighbor->west_neighbor : NULL;
    element_t* west_neighbor_east_neighbor   = (west_neighbor) ? west_neighbor->east_neighbor : NULL;
    element_t* top_neighbor_bottom_neighbor  = (top_neighbor) ? top_neighbor->bottom_neighbor : NULL;
    element_t* bottom_neighbor_top_neighbor  = (bottom_neighbor) ? bottom_neighbor->top_neighbor : NULL;

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

    const char *north_color  = (north_neighbor_south_neighbor == source) 
                                ? ANSI_COLOR_GREEN : ANSI_COLOR_RED;

    const char *south_color  = (south_neighbor_north_neighbor == source) 
                                ? ANSI_COLOR_GREEN : ANSI_COLOR_RED;

    const char *east_color   = (east_neighbor_west_neighbor == source) 
                                ? ANSI_COLOR_GREEN : ANSI_COLOR_RED;

    const char *west_color   = (west_neighbor_east_neighbor == source) 
                                ? ANSI_COLOR_GREEN : ANSI_COLOR_RED;

    const char *top_color    = (top_neighbor_bottom_neighbor == source) 
                                ? ANSI_COLOR_GREEN : ANSI_COLOR_RED;

    const char *bottom_color = (bottom_neighbor_top_neighbor == source) 
                                ? ANSI_COLOR_GREEN : ANSI_COLOR_RED;


    printf("*************************************************************************************************************\n");
    printf("*                                                                                                           *\n");
    printf("*                                            *******************                                            *\n");
    printf("*                                            **    ELEMENT    **                                            *\n");
    printf("*                                            *******************                                            *\n");
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
    printf("*                               **  %s%p%s  ** **  %s%p%s  **                               *\n", top_color, top_neighbor_bottom_neighbor, ANSI_COLOR_RESET, north_color, north_neighbor_south_neighbor, ANSI_COLOR_RESET);
    printf("*                               **                  ** **                  **                               *\n");
    printf("*                               ********************** **********************                               *\n");
    printf("*                                                                                                           *\n");
    printf("*  **********************       ********************** **********************       **********************  *\n");
    printf("*  **                  **       **       WEST       ** **       EAST       **       **                  **  *\n");
    printf("*  **  %s%p%s  ** <---> **  %s%p%s  ** **  %s%p%s  ** <---> **  %s%p%s  **  *\n", west_null_color, west_neighbor, ANSI_COLOR_RESET, west_color, west_neighbor_east_neighbor, ANSI_COLOR_RESET, east_color, east_neighbor_west_neighbor, ANSI_COLOR_RESET, east_null_color, east_neighbor, ANSI_COLOR_RESET);
    printf("*  **                  **       **                  ** **                  **       **                  **  *\n");
    printf("*  **********************       ********************** **********************       **********************  *\n");
    printf("*                                                                                                           *\n");
    printf("*                               ********************** **********************                               *\n");
    printf("*                               **      SOUTH       ** **      BOTTOM      **                               *\n");
    printf("*                               **  %s%p%s  ** **  %s%p%s  **                               *\n", south_color, south_neighbor_north_neighbor,ANSI_COLOR_RESET, bottom_color, bottom_neighbor_top_neighbor, ANSI_COLOR_RESET);
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
