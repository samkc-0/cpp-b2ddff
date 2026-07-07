#include "exercise.hpp"

#include <cstdlib>
#include <exception>
#include <iostream>

namespace {
int failures = 0;
template <typename Actual, typename Expected>
void expect_equal(const Actual& actual, const Expected& expected, int line) { if (!(actual == expected)) { ++failures; std::cerr << "Line " << line << ": assertion failed\n"; } }
void expect_true(bool actual, int line) { if (!actual) { ++failures; std::cerr << "Line " << line << ": expected true\n"; } }
#define EXPECT_EQUAL(actual, expected) expect_equal((actual), (expected), __LINE__)
#define EXPECT_TRUE(actual) expect_true((actual), __LINE__)
}  // namespace

int main() {
    using stage_03::classes::matrix_exercise::Matrix2x2;
    try {
        const Matrix2x2 matrix{1, 2, 3, 4};
        EXPECT_EQUAL(matrix.at(0, 1), 2);
        EXPECT_EQUAL(matrix.determinant(), -2);
        EXPECT_TRUE(((Matrix2x2{1, 2, 3, 4} + Matrix2x2{5, 6, 7, 8}) == Matrix2x2{6, 8, 10, 12}));
    } catch (const std::exception& exception) {
        ++failures;
        std::cerr << "Unhandled exception: " << exception.what() << "\n";
    }
    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
