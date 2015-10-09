#include <stdlib.h>
#include "Random.h"

int Random::nextInt(int min, int max) {
    return (rand() % (max - min) + min);
}
