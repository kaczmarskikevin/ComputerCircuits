#include <project.h>
#include <elements/copper_wire.h>

// Track test passes and failures globally
static int tests_run = 0;
static int tests_failed = 0;

// Helper macro for cleaner test reporting
#define RUN_TEST(test_func) do { \
    printf("Running %s... ", #test_func); \
    tests_run++; \
    if (test_func() == EXIT_SUCCESS) { \
        printf("PASSED\n"); \
    } else { \
        printf("FAILED\n"); \
        tests_failed++; \
    } \
} while (0)

// Connect all wires to all faces.
int test_copper_wire(void) {

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

    int result = 0;

    result |= connect_face(main_wire, north_wire,  COPPER_NORTH);
    result |= connect_face(main_wire, south_wire,  COPPER_SOUTH);
    result |= connect_face(main_wire, east_wire,   COPPER_EAST);
    result |= connect_face(main_wire, west_wire,   COPPER_WEST);
    result |= connect_face(main_wire, top_wire,    COPPER_TOP);
    result |= connect_face(main_wire, bottom_wire, COPPER_BOTTOM);

    return result; 
}

//Connect the north wire to a face that doesn't exist.
int test_copper_wire_error(void) {

    copper_wire_t main_wire_obj = {0}; 
    copper_wire_t north_obj = {0};

    copper_wire_t* main_wire   = &main_wire_obj;
    copper_wire_t* north_wire  = &north_obj;

    int result = 0;

    result |= connect_face(main_wire, north_wire,  99);

    return !result; 
}

int main(void) {
    printf("=== STARTING TESTS ===\n");

    // Execute test cases
    RUN_TEST(test_copper_wire);
    RUN_TEST(test_copper_wire_error);

    // Final summary report
    printf("\n=== TEST SUMMARY ===\n");
    printf("Total Tests Run: %d\n", tests_run);
    printf("Passed: %d\n", tests_run - tests_failed);
    printf("Failed: %d\n", tests_failed);

    if (tests_failed > 0) {
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}