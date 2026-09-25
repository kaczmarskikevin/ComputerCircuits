#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <tests/elements/copper_wire.h>
#include <tests/elements/power.h>

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

int main(void) {
    printf("=== STARTING TESTS ===\n");

    // Execute test cases

    //copper_wire.c
    RUN_TEST(copper_wire_connections);
    RUN_TEST(copper_wire_connections_error);
    RUN_TEST(copper_wire_power_draw);
    RUN_TEST(copper_wire_power_draw_error);
    RUN_TEST(copper_wire_power_release);
    RUN_TEST(copper_wire_power_release_error);

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