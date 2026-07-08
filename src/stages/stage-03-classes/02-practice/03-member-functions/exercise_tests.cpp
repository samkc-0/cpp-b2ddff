#include "exercise.hpp"

#include <cstdlib>
#include <exception>
#include <iostream>

namespace {
int failures = 0;
template <typename A, typename E>
void expect_equal(const A& actual, const E& expected, int line) {
    if (!(actual == expected)) { ++failures; std::cerr << "Line " << line << ": assertion failed\n"; }
}
#define EXPECT_EQUAL(actual, expected) expect_equal((actual), (expected), __LINE__)
}  // namespace

int main() {
    using stage_03::practice::member_functions_exercise::Thermostat;
    try {
        Thermostat thermostat{20};
        thermostat.warm_up();
        EXPECT_EQUAL(thermostat.temperature(), 21);
        thermostat.cool_down();
        thermostat.cool_down();
        EXPECT_EQUAL(thermostat.temperature(), 19);
        thermostat.set_temperature(25);
        EXPECT_EQUAL(thermostat.temperature(), 25);
    } catch (const std::exception& exception) {
        ++failures;
        std::cerr << "Unhandled exception: " << exception.what() << "\n";
    }
    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
