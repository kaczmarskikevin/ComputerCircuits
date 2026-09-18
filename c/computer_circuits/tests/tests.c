#include <project.h>

// Track test passes and failures globally
static int tests_run = 0;
static int tests_failed = 0;

// Helper macro for cleaner test reporting
#define RUN_TEST(test_func) do { \
    printf("Running %s... ", #test_func); \
    tests_run++; \
    if (test_func()) { \
        printf("PASSED\n"); \
    } else { \
        printf("FAILED\n"); \
        tests_failed++; \
    } \
} while (0)

// Test Case 1: Standard addition
int test_addition_positive_numbers(void) {
    int result = 5 + 7;
    return (result == 12);
}

// Test Case 2: Handled division error
int test_division_by_zero(void) {
    int result = 10 / 0;
    // Assuming your code returns a sentinel value like -1 on error
    return (result == -1); 
}

// Main entry point executed by your Makefile
int main(void) {
    printf("=== STARTING TESTS ===\n");

    // Execute test cases
    RUN_TEST(test_addition_positive_numbers);
    RUN_TEST(test_division_by_zero);

    // Final summary report
    printf("\n=== TEST SUMMARY ===\n");
    printf("Total Tests Run: %d\n", tests_run);
    printf("Passed: %d\n", tests_run - tests_failed);
    printf("Failed: %d\n", tests_failed);

    // Return non-zero if any tests fail so the Makefile stops execution
    if (tests_failed > 0) {
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}