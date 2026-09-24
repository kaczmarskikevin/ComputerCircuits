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
    copper_wire_t* wire1;
    copper_wire_t* wire2;
    return connect_face(wire1,wire2,COPPER_NORTH);
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