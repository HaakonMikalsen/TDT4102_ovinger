#include "utilities.h"
#include <random>
#include "std_lib_facilities.h"

// BEGIN: 5a
int randomWithLimits(int min,int max)
{
    // Create a random device and generator
    random_device rd;
    default_random_engine generator(rd());

    // Define the range for the random number
    uniform_int_distribution<int> distribution(min, max);

    // Return a random number in the specified range
    return distribution(generator);
}
// END: 5a