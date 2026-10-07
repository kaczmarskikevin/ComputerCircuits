#include <stdio.h>
#include <stdlib.h>
#include <elements/power.h>

power_supply_t* power_supply;

int power_on() {

    if( power_supply != NULL ) {
        printf("Error: PC is already on.\n");
        return 0;
    }

    power_supply = malloc(sizeof(power_supply_t));
    power_supply->femtowatt_rating = 1000000000000000000;
    power_supply->femtowatts_used = 0LL;
    power_supply->volts = 120;

    return 1;
}

int power_off() {

    if( power_supply == NULL ) {
        printf("Error: PC is already off.\n");
        return 0;
    }

    free(power_supply);
    power_supply = NULL;

    return 1;
}

long long current_usage() {

    if( power_supply == NULL ) {
        printf("Error: PC is off.\n");
        return 0;
    }

    return power_supply->femtowatts_used;
}

int draw_power(long long femtoamperes) {

    if( power_supply == NULL ) {
        printf("Error: PC is off.\n");
        return 0;
    }

    if( power_supply->femtowatts_used < power_supply->femtowatt_rating ){
        power_supply->femtowatts_used = power_supply->femtowatts_used + ( power_supply->volts * femtoamperes );
        printf("Femtowatts are %lld\n",power_supply->femtowatts_used);

        if(power_supply->femtowatts_used > power_supply->femtowatt_rating) { 
            printf("Error: Femtowatts used, %lld, cannot be more than %lld.\n", power_supply->femtowatts_used, power_supply->femtowatt_rating);
            return 0;
        }
    }
    return 1;
}

/*
* We want to be able to release power, but the power should not become negative.
*/
int release_power(long long femtoamperes) {

    if( power_supply == NULL ) {
        printf("Error: PC is off.\n");
        return 0;
    }

    if( power_supply->femtowatts_used >= 0 ){
        power_supply->femtowatts_used = power_supply->femtowatts_used - ( power_supply->volts * femtoamperes );

        if( power_supply->femtowatts_used < 0 ){
            printf("Error: Femtowatts used, %lld, cannot be less than 0.\n", power_supply->femtowatts_used);
            return 0;
        }
    }
    return 1;
}