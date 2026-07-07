#include "exercise.hpp"

#include <stdexcept>

namespace stage_01::std_optional::find_first_even_exercise {

// Task: Return the first even integer in values.
// Return std::nullopt when there are no even integers.
std::optional<int> find_first_even(const std::vector<int>& values) {
    const std::vector<int>& v = values;
    auto result = std::find_if(v.begin(), v.end(), [&](int x){ return x%2==0; });
    if (result == v.end())
        return std::nullopt;
    return *result;
}

}  // namespace stage_01::std_optional::find_first_even_exercise
