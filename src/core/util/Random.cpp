#include <stdlib.h>
#include "Random.h"

int Random::nextInt(int min, int max) {
	srand(time(NULL));

	if(min == max)
        return min;
    return (rand() % (max - min) + min);
}
