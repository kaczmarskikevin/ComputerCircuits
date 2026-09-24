#include <project.h>

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

// Test Case for Copper Wire
int test_copper_wire(void) {
    copper_wire_t* main_wire;
    copper_wire_t* north_wire;
    copper_wire_t* south_wire;
    copper_wire_t* east_wire;
    copper_wire_t* west_wire;
    copper_wire_t* top_wire;
    copper_wire_t* bottom_wire;
    return connect_face(main_wire,north_wire,COPPER_NORTH) ||
           connect_face(main_wire,south_wire,COPPER_SOUTH) ||
           connect_face(main_wire,east_wire,COPPER_EAST) ||
           connect_face(main_wire,west_wire,COPPER_WEST) ||
           connect_face(main_wire,top_wire,COPPER_TOP) ||
           connect_face(main_wire,bottom_wire,COPPER_BOTTOM);
}

int main(void) {
    printf("=== STARTING TESTS ===\n");

    // Execute test cases
    RUN_TEST(test_copper_wire);

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