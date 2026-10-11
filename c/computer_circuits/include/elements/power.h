typedef struct { 
    long long femtowatt_rating;
    long long femtowatts_used;
    long long microvolts; 
} power_supply_t;

int power_on();

int power_off();

long long current_usage();

int draw_power(long long nanoamperes);

int release_power(long long nanoamperes);