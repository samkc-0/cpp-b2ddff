#include "exercise.hpp"

#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>

namespace {
int failures = 0;
template <typename Actual, typename Expected>
void expect_equal(const Actual& actual, const Expected& expected, int line) { if (!(actual == expected)) { ++failures; std::cerr << "Line " << line << ": assertion failed\n"; } }
void expect_true(bool actual, int line) { if (!actual) { ++failures; std::cerr << "Line " << line << ": expected true\n"; } }
void expect_false(bool actual, int line) { if (actual) { ++failures; std::cerr << "Line " << line << ": expected false\n"; } }
#define EXPECT_EQUAL(actual, expected) expect_equal((actual), (expected), __LINE__)
#define EXPECT_TRUE(actual) expect_true((actual), __LINE__)
#define EXPECT_FALSE(actual) expect_false((actual), __LINE__)
}  // namespace

int main() {
    using stage_03::classes::book_exercise::Book;
    try {
        const Book book{"The C++ Programming Language", "Bjarne Stroustrup", 1985};
        EXPECT_EQUAL(book.title(), std::string("The C++ Programming Language"));
        EXPECT_EQUAL(book.author(), std::string("Bjarne Stroustrup"));
        EXPECT_TRUE(book.is_classic(2035));
        EXPECT_FALSE(book.is_classic(2026));
        EXPECT_TRUE((book == Book{"The C++ Programming Language", "Bjarne Stroustrup", 1985}));
    } catch (const std::exception& exception) {
        ++failures;
        std::cerr << "Unhandled exception: " << exception.what() << "\n";
    }
    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
