#include "exercise.hpp"

#include <cmath>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>

namespace {
int failures = 0;
void expect_near(double actual, double expected, int line) { if (std::fabs(actual - expected) > 0.000001) { ++failures; std::cerr << "Line " << line << ": assertion failed\n"; } }
template <typename Actual, typename Expected>
void expect_equal(const Actual& actual, const Expected& expected, int line) { if (!(actual == expected)) { ++failures; std::cerr << "Line " << line << ": assertion failed\n"; } }
void expect_true(bool actual, int line) { if (!actual) { ++failures; std::cerr << "Line " << line << ": expected true\n"; } }
#define EXPECT_NEAR(actual, expected) expect_near((actual), (expected), __LINE__)
#define EXPECT_EQUAL(actual, expected) expect_equal((actual), (expected), __LINE__)
#define EXPECT_TRUE(actual) expect_true((actual), __LINE__)
}  // namespace

int main() {
    using stage_03::classes::student_exercise::Student;
    try {
        Student student{"Ada"};
        EXPECT_EQUAL(student.name(), std::string("Ada"));
        EXPECT_NEAR(student.average_grade(), 0.0);
        student.add_grade(80);
        student.add_grade(100);
        EXPECT_NEAR(student.average_grade(), 90.0);
        EXPECT_TRUE(student.has_passing_average());
    } catch (const std::exception& exception) {
        ++failures;
        std::cerr << "Unhandled exception: " << exception.what() << "\n";
    }
    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
