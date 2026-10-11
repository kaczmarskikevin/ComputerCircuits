#pragma once

#define NORTH 0
#define SOUTH 1
#define EAST 2
#define WEST 3
#define TOP 4
#define BOTTOM 5

typedef struct element {

//    const struct element_interface* const vtable;

    struct element* north_neighbor;
    struct element* south_neighbor;
    struct element* east_neighbor;
    struct element* west_neighbor;
    struct element* top_neighbor;
    struct element* bottom_neighbor;
} element_t;

//struct element_interface {
//    int (*connect_neighbor)(source,neighbor,face);
//    element_t* (*get_neighbor)(source,face);
//};

//int connect_neighbor(struct element_t* obj);
int connect_neighbor(element_t* source, element_t* neighbor, int face);

int inspect_element(element_t* source);
