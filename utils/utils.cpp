#include "utils.h"
#include <random>

using namespace std;

long randomNumber(int min, int max) {
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist6(min,max);

    return dist6(rng);
}
