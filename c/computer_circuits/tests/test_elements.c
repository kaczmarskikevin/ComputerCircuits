#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <elements/element.h>
#include <elements/power.h>

// Track test passes and failures globally
static int tests_run = 0;
static int tests_failed = 0;

// Helper macro for cleaner test reporting
#define RUN_TEST(test_func) do { \
    tests_run++; \
    if (test_func() == 1) { \
        printf("**** Test %s... PASSED\n", #test_func); \
    } else { \
        printf("**** Test %s... FAILED\n", #test_func); \
        tests_failed++; \
    } \
} while (0)

/*
*  CUSTOM CODE
*/

// Connect all wires to all faces and try to connect the north wire to a face that doesn't exist.
int test_copper_wire(void) {

    element_t* main_wire = malloc(sizeof(element_t));
    element_t* north_wire = malloc(sizeof(element_t));
    element_t* south_wire = malloc(sizeof(element_t));
    element_t* east_wire = malloc(sizeof(element_t));
    element_t* west_wire = malloc(sizeof(element_t));
    element_t* top_wire = malloc(sizeof(element_t));
    element_t* bottom_wire = malloc(sizeof(element_t));

    int result = 1;

    //Success Tests
    result &= printf("STARTING Connecting north face  ... ") && connect_face(main_wire, north_wire,  NORTH_FACE)   && printf("TRUE");printf(" ... ENDING Connecting north face\n\n");
    result &= printf("STARTING Connecting south face  ... ") && connect_face(main_wire, south_wire,  SOUTH_FACE)   && printf("TRUE");printf(" ... ENDING Connecting south face\n\n");
    result &= printf("STARTING Connecting east face   ... ") && connect_face(main_wire, east_wire,  EAST_FACE)     && printf("TRUE");printf(" ... ENDING Connecting east face\n\n");
    result &= printf("STARTING Connecting west face   ... ") && connect_face(main_wire, west_wire,  WEST_FACE)     && printf("TRUE");printf(" ... ENDING Connecting west face\n\n");
    result &= printf("STARTING Connecting top face    ... ") && connect_face(main_wire, top_wire,  TOP_FACE)       && printf("TRUE");printf(" ... ENDING Connecting top face\n\n");
    result &= printf("STARTING Connecting bottom face ... ") && connect_face(main_wire, bottom_wire,  BOTTOM_FACE) && printf("TRUE");printf(" ... ENDING Connecting bottom face\n\n");

    //Failed connection
    result &= printf("Connecting bottom face ... ") && !connect_face(main_wire, bottom_wire,  99) && printf("TRUE");printf("\n");

    inspect_wire(main_wire);

    return result; 
}

int test_n_type_transistor(void) {
    return 1;
}

int test_p_type_transistor(void) {
    return 1;
}

int test_power(void) {

    int result = 1;
    
    //Success Tests
    result &= printf("STARTING Power on                               ... ") && power_on()               && printf("TRUE");printf(" ... ENDING Power on\n\n");
    result &= printf("STARTING Usage is zero                          ... ") && current_usage() == 0LL   && printf("TRUE");printf(" ... ENDING Usage is zero\n\n");
    result &= printf("STARTING Add 0 femtoamps                        ... ") && draw_power(0LL)          && printf("TRUE");printf(" ... ENDING Add 0 femtoamps\n\n");
    result &= printf("STARTING Power draw is 0 femtowatts             ... ") && current_usage() == 0LL   && printf("TRUE");printf(" ... ENDING Power draw is 0 femtowatts\n\n");
    result &= printf("STARTING Add 1 femtoamp                         ... ") && draw_power(1LL)          && printf("TRUE");printf(" ... ENDING Add 1 femtoamp\n\n");
    result &= printf("STARTING Power draw is 120 femtowatts           ... ") && current_usage() == 120LL && printf("TRUE");printf(" ... ENDING Power draw is 120 femtowatts\n\n");
    result &= printf("STARTING Release 0 femtoamps                    ... ") && release_power(0LL)       && printf("TRUE");printf(" ... ENDING Release 0 femtoamps\n\n");
    result &= printf("STARTING Power draw is 120 femtowatts           ... ") && current_usage() == 120LL && printf("TRUE");printf(" ... ENDING Power draw is 120 femtowatts\n\n");
    result &= printf("STARTING Release 1 femtoamp                     ... ") && release_power(1LL)       && printf("TRUE");printf(" ... ENDING Release 1 femtoamp\n\n");
    result &= printf("STARTING Power draw is 0 femtowatts             ... ") && current_usage() == 0LL   && printf("TRUE");printf(" ... ENDING Power draw is 0 femtowatts\n\n");

    // //Failure Tests
    result &= printf("STARTING Release 1 femtoamp where there is none ... ") && !release_power(1LL)           && printf("TRUE");printf(" ... ENDING Release 1 femtoamp where there is none\n\n");
    result &= printf("STARTING Draw too much power                    ... ") && !draw_power(8333333333333335) && printf("TRUE");printf(" ... ENDING Draw too much power\n\n");

    // //Success Tests
    result &= printf("STARTING Power off                              ... ") && power_off() && printf("TRUE");printf(" ... ENDING Power off\n\n");

    // //Failure Tests
    result &= printf("STARTING Release power while PC is off          ... ") && !release_power(1LL) && printf("TRUE");printf(" ... ENDING Release power while PC is off\n\n");
    result &= printf("STARTING Draw power while PC is off ... ") && !draw_power(0LL) && printf("TRUE");printf(" ... ENDING Draw power while PC is off\n\n");
    result &= printf("STARTING Check usage while PC is off ... ") && !current_usage() && printf("TRUE");printf(" ... ENDING Check usage while PC is off\n\n");

    return result;
}

int execute_tests() {
    // Execute test cases
    RUN_TEST(test_copper_wire);
    //RUN_TEST(test_n_type_transistor);
    //RUN_TEST(test_p_type_transistor);
    //RUN_TEST(test_power);

    return 0;
}

int main(void) {
    printf("=== STARTING TESTS ===\n");

    execute_tests();

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