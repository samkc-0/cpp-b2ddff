#include "exercise.hpp"

#include <cstdlib>
#include <exception>
#include <iostream>
#include <optional>
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
    using stage_03::classes::library_exercise::Library;
    try {
        Library library;
        library.add_book("Dune");
        library.add_book("Dubliners");
        EXPECT_EQUAL(library.size(), 2U);
        EXPECT_TRUE(library.contains("Dune"));
        EXPECT_FALSE(library.contains("Foundation"));
        EXPECT_EQUAL(library.find_by_prefix("Dub"), std::optional<std::string>{"Dubliners"});
        EXPECT_EQUAL(library.find_by_prefix("X"), std::optional<std::string>{});
    } catch (const std::exception& exception) {
        ++failures;
        std::cerr << "Unhandled exception: " << exception.what() << "\n";
    }
    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
