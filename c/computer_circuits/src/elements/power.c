#include <stdio.h>
#include <stdlib.h>
#include <elements/power.h>

power_supply_t power_supply_obj = { .femtowatt_rating = 1000000000000000000, .femtowatts_used = 0, .femtovolts = 120000000000000000 };

power_supply_t* power_supply = &power_supply_obj;


int draw_power(long long femtoamperes) {
    return EXIT_SUCCESS;
}

int release_power(long long femtoamperes) {

    if( power_supply->femtowatts_used >= 0 ){
        power_supply->femtowatts_used = power_supply->femtowatts_used - ( power_supply->femtovolts * femtoamperes );

        if( power_supply->femtowatts_used < 0 ) {
            printf("Error: Femtowatts used, %lld, cannot be less than 0.", power_supply->femtowatts_used);
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}