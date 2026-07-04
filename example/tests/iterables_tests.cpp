#include "iterables/exercises.hpp"

#include <cstdlib>
#include <iostream>
#include <map>
#include <optional>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

namespace {

struct TestCase {
    std::string name;
    void (*run)();
};

template <typename T>
std::string to_string_value(const T& value) {
    std::ostringstream out;
    out << value;
    return out.str();
}

template <typename T>
std::string to_string_value(const std::optional<T>& value) {
    if (!value.has_value()) {
        return "nullopt";
    }
    return "optional(" + to_string_value(*value) + ")";
}

template <typename T>
std::string to_string_value(const std::vector<T>& values) {
    std::ostringstream out;
    out << "{";
    for (std::size_t i = 0; i < values.size(); ++i) {
        if (i > 0) {
            out << ", ";
        }
        out << to_string_value(values[i]);
    }
    out << "}";
    return out.str();
}

template <typename K, typename V>
std::string to_string_value(const std::map<K, V>& values) {
    std::ostringstream out;
    out << "{";
    bool first = true;
    for (const auto& [key, value] : values) {
        if (!first) {
            out << ", ";
        }
        first = false;
        out << to_string_value(key) << ": " << to_string_value(value);
    }
    out << "}";
    return out.str();
}

template <typename A, typename B>
std::string to_string_value(const std::pair<A, B>& value) {
    return "(" + to_string_value(value.first) + ", " + to_string_value(value.second) + ")";
}

void require_true(bool condition, const std::string& message) {
    if (!condition) {
        throw std::runtime_error(message);
    }
}

template <typename Actual, typename Expected>
void require_equal(const Actual& actual, const Expected& expected, const std::string& context) {
    if (!(actual == expected)) {
        throw std::runtime_error(
            context + "\n  expected: " + to_string_value(expected) +
            "\n  actual:   " + to_string_value(actual)
        );
    }
}

void ex01() {
    require_equal(iterables::count_items({}), 0, "empty vector has size 0");
    require_equal(iterables::count_items({4, 8, 15, 16, 23, 42}), 6, "counts all items");
}

void ex02() {
    require_equal(iterables::sum_items({}), 0, "empty vector sums to 0");
    require_equal(iterables::sum_items({4, -1, 10, 2}), 15, "sums positive and negative numbers");
}

void ex03() {
    require_equal(iterables::first_item({}), std::optional<int>{}, "empty vector has no first item");
    require_equal(iterables::first_item({9, 8, 7}), std::optional<int>{9}, "returns first item");
}

void ex04() {
    require_equal(iterables::last_item({}), std::optional<int>{}, "empty vector has no last item");
    require_equal(iterables::last_item({9, 8, 7}), std::optional<int>{7}, "returns last item");
}

void ex05() {
    require_equal(iterables::evens_only({1, 2, 3, 4, 5, 6}), std::vector<int>{2, 4, 6}, "keeps evens");
    require_equal(iterables::evens_only({1, 3, 5}), std::vector<int>{}, "returns empty if no evens");
}

void ex06() {
    require_equal(iterables::multiply_all({1, -2, 3}, 4), std::vector<int>{4, -8, 12}, "multiplies all items");
    require_equal(iterables::multiply_all({}, 99), std::vector<int>{}, "empty input stays empty");
}

void ex07() {
    require_true(iterables::contains_value({3, 1, 4}, 1), "finds a present value");
    require_true(!iterables::contains_value({3, 1, 4}, 2), "rejects an absent value");
}

void ex08() {
    require_equal(iterables::count_occurrences({7, 7, 2, 7, 3}, 7), 3, "counts repeated value");
    require_equal(iterables::count_occurrences({7, 7, 2}, 9), 0, "absent value has count 0");
}

void ex09() {
    require_equal(iterables::max_item({}), std::optional<int>{}, "empty vector has no max");
    require_equal(iterables::max_item({-8, -3, -20}), std::optional<int>{-3}, "finds max with negative values");
}

void ex10() {
    require_equal(iterables::reversed_copy({1, 2, 3, 4}), std::vector<int>{4, 3, 2, 1}, "reverses order");
    require_equal(iterables::reversed_copy({}), std::vector<int>{}, "empty input stays empty");
}

void ex11() {
    require_equal(iterables::concatenate({1, 2}, {3, 4, 5}), std::vector<int>{1, 2, 3, 4, 5}, "appends right to left");
    require_equal(iterables::concatenate({}, {8}), std::vector<int>{8}, "handles empty left");
}

void ex12() {
    require_equal(iterables::drop_first({1, 2, 3, 4}, 2), std::vector<int>{3, 4}, "drops first n");
    require_equal(iterables::drop_first({1, 2}, 5), std::vector<int>{}, "dropping too many returns empty");
}

void ex13() {
    require_equal(iterables::take_first({1, 2, 3, 4}, 2), std::vector<int>{1, 2}, "takes first n");
    require_equal(iterables::take_first({1, 2}, 5), std::vector<int>{1, 2}, "taking too many returns all");
}

void ex14() {
    require_equal(iterables::sum_even_indexes({10, 20, 30, 40, 50}), 90, "sums indexes 0, 2, 4");
    require_equal(iterables::sum_even_indexes({}), 0, "empty vector sums to 0");
}

void ex15() {
    require_true(iterables::is_non_decreasing({1, 2, 2, 4}), "accepts non-decreasing values");
    require_true(!iterables::is_non_decreasing({1, 3, 2, 4}), "rejects a decrease");
    require_true(iterables::is_non_decreasing({}), "empty vector is sorted");
}

void ex16() {
    require_equal(
        iterables::collapse_adjacent_duplicates({1, 1, 2, 1, 1, 1, 3}),
        std::vector<int>{1, 2, 1, 3},
        "collapses only adjacent duplicates"
    );
    require_equal(iterables::collapse_adjacent_duplicates({}), std::vector<int>{}, "empty input stays empty");
}

void ex17() {
    require_equal(iterables::dot_product_shortest({1, 2, 3}, {10, 20}), 50, "uses shortest length");
    require_equal(iterables::dot_product_shortest({}, {10, 20}), 0, "empty side gives 0");
}

void ex18() {
    require_equal(iterables::pairwise_sums({1, 2, 3}, {10, 20}), std::vector<int>{11, 22}, "sums pairs");
    require_equal(iterables::pairwise_sums({1}, {}), std::vector<int>{}, "stops at shorter length");
}

void ex19() {
    require_equal(iterables::index_of({5, 6, 7, 6}, 6), std::optional<std::size_t>{1}, "returns first index");
    require_equal(iterables::index_of({5, 6, 7}, 9), std::optional<std::size_t>{}, "absent target returns nullopt");
}

void ex20() {
    require_equal(iterables::all_indexes_of({5, 6, 7, 6}, 6), std::vector<std::size_t>{1, 3}, "returns all indexes");
    require_equal(iterables::all_indexes_of({5, 6, 7}, 9), std::vector<std::size_t>{}, "absent target returns empty");
}

void ex21() {
    require_equal(iterables::running_totals({3, 4, -2, 10}), std::vector<int>{3, 7, 5, 15}, "builds running totals");
    require_equal(iterables::running_totals({}), std::vector<int>{}, "empty input stays empty");
}

void ex22() {
    require_equal(
        iterables::partition_negative({3, -1, 0, -8, 5}),
        std::pair<std::vector<int>, std::vector<int>>{{-1, -8}, {3, 0, 5}},
        "partitions negatives and non-negatives"
    );
}

void ex23() {
    require_equal(iterables::remove_value({1, 2, 1, 3, 1}, 1), std::vector<int>{2, 3}, "removes all target values");
    require_equal(iterables::remove_value({1, 2}, 9), std::vector<int>{1, 2}, "absent target leaves values alone");
}

void ex24() {
    require_equal(iterables::unique_in_order({3, 1, 3, 2, 1, 4}), std::vector<int>{3, 1, 2, 4}, "keeps first appearances");
    require_equal(iterables::unique_in_order({}), std::vector<int>{}, "empty input stays empty");
}

void ex25() {
    require_true(iterables::contains_all({1, 2, 3, 4}, {2, 4}), "all required values are present");
    require_true(!iterables::contains_all({1, 2, 3}, {2, 9}), "missing required value returns false");
    require_true(iterables::contains_all({1, 2, 3}, {}), "empty requirements are satisfied");
}

void ex26() {
    require_equal(
        iterables::intersection_in_left_order({5, 1, 5, 2, 3, 1}, {1, 3, 9, 5}),
        std::vector<int>{5, 1, 3},
        "returns unique intersection in left order"
    );
}

void ex27() {
    require_equal(
        iterables::word_counts({"red", "blue", "red", "green", "blue", "red"}),
        std::map<std::string, int>{{"blue", 2}, {"green", 1}, {"red", 3}},
        "counts words"
    );
}

void ex28() {
    require_equal(
        iterables::words_at_least({"a", "able", "cat", "window"}, 4),
        std::vector<std::string>{"able", "window"},
        "filters by word length"
    );
}

void ex29() {
    require_equal(
        iterables::non_space_characters("a b  c"),
        std::vector<char>{'a', 'b', 'c'},
        "returns non-space characters"
    );
}

void ex30() {
    require_equal(
        iterables::enabled_feature_names({{"search", true}, {"billing", false}, {"export", true}}),
        std::vector<std::string>{"export", "search"},
        "returns sorted enabled feature names"
    );
}

const std::vector<TestCase>& tests() {
    static const std::vector<TestCase> all{
        {"ex01", ex01}, {"ex02", ex02}, {"ex03", ex03}, {"ex04", ex04}, {"ex05", ex05},
        {"ex06", ex06}, {"ex07", ex07}, {"ex08", ex08}, {"ex09", ex09}, {"ex10", ex10},
        {"ex11", ex11}, {"ex12", ex12}, {"ex13", ex13}, {"ex14", ex14}, {"ex15", ex15},
        {"ex16", ex16}, {"ex17", ex17}, {"ex18", ex18}, {"ex19", ex19}, {"ex20", ex20},
        {"ex21", ex21}, {"ex22", ex22}, {"ex23", ex23}, {"ex24", ex24}, {"ex25", ex25},
        {"ex26", ex26}, {"ex27", ex27}, {"ex28", ex28}, {"ex29", ex29}, {"ex30", ex30},
    };
    return all;
}

bool matches_filter(const std::string& name, const std::string& filter) {
    return filter.empty() || name.rfind(filter, 0) == 0;
}

}  // namespace

int main(int argc, char** argv) {
    const std::string filter = argc > 1 ? argv[1] : "";
    int passed = 0;
    int failed = 0;
    int selected = 0;

    for (const auto& test : tests()) {
        if (!matches_filter(test.name, filter)) {
            continue;
        }

        ++selected;
        try {
            test.run();
            ++passed;
            std::cout << "[PASS] " << test.name << "\n";
        } catch (const std::exception& error) {
            ++failed;
            std::cout << "[FAIL] " << test.name << "\n" << error.what() << "\n";
        }
    }

    if (selected == 0) {
        std::cerr << "No tests matched filter '" << filter << "'. Try ex01, ex14, or no filter.\n";
        return EXIT_FAILURE;
    }

    std::cout << "\n" << passed << " passed, " << failed << " failed, " << selected << " selected\n";
    return failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
