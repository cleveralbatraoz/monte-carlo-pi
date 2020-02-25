#include "../include/utils.h"
#include <cmath>

std::uniform_real_distribution<> get_real_distribution()
{
	// produces random floating-point values uniformly distributed on the interval
	return std::uniform_real_distribution<>(0.0, 1.0);
}

std::mt19937_64 get_random_generator()
{
	// non-deterministic random number generator using hardware entropy source
	std::random_device random_device;
	// seeding Mersenne Twister with a non-deterministic value
	return std::mt19937_64(random_device());
}

double generate_random_number()
{
	static auto generator = get_random_generator();
	static auto dist = get_real_distribution();
	return dist(generator);
}

double GetPi(std::function<double()> generator,
             std::size_t number_of_iterations)
{
    if (number_of_iterations == 0) {
        return 0;
    }
    unsigned cnt = 0;
    for (unsigned iteration = 0; iteration < number_of_iterations; iteration++) {
        double x = generator();
        double y = generator();
        cnt += 1 >= hypot(x, y);
    }
    return 4.0 * cnt / number_of_iterations;
}
