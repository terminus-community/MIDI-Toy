#include <cstdlib>

void init_random() {
    srand(time(NULL));
}

int rng_random(int min, int max){
    return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}
