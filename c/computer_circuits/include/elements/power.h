typedef struct { 
    long long femtowatt_rating;
    long long femtowatts_used;
    long long femtovolts; 
} power_supply_t;

int draw_power(void);

int release_power(void);