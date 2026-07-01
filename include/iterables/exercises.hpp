#pragma once

#include <map>
#include <optional>
#include <set>
#include <string>
#include <utility>
#include <vector>

namespace iterables {

// ex01: Return the number of elements in the vector.
inline int count_items(const std::vector<int>& values) {
    return values.size();
}

// ex02: Return the sum of all numbers in the vector.
inline int sum_items(const std::vector<int>& values) {
    int total = 0;
    for (size_t i = 0; i < values.size(); ++i) {
        total += values[i];
    }
    return total;
}

// ex03: Return the first element, or std::nullopt for an empty vector.
inline std::optional<int> first_item(const std::vector<int>& values) {
    if (values.size() == 0)
        return std::nullopt;
    return values[0];
}

// ex04: Return the last element, or std::nullopt for an empty vector.
inline std::optional<int> last_item(const std::vector<int>& values) {
    if (values.size() == 0)
        return std::nullopt;
    return values[values.size() - 1];
}

// ex05: Return a new vector containing only the even numbers, in original order.
inline std::vector<int> evens_only(const std::vector<int>& values) {
    std::vector<int> evens = {};
    for (size_t i = 0; i < values.size(); i++) {
        if (values[i] % 2 == 0)
            evens.push_back(values[i]);
    }
    return evens;

}

// ex06: Return a new vector where every number is multiplied by factor.
inline std::vector<int> multiply_all(const std::vector<int>& values, int factor) {
    std::vector<int> multiplied(values);
    for (size_t i = 0; i < multiplied.size(); i++)
        multiplied[i] *= factor;
    return multiplied;
}

// ex07: Return true if target appears in the vector.
inline bool contains_value(const std::vector<int>& values, int target) {
    for (size_t i = 0; i < values.size(); i++)
        if (values[i] == target) return true;
    return false;
}

// ex08: Return how many times target appears in the vector.
inline int count_occurrences(const std::vector<int>& values, int target) {
    int count = 0;
    for (size_t i = 0; i < values.size(); i++) {
        count += (int)(values[i] == target);
    }
    return count;
}

// ex09: Return the largest value, or std::nullopt for an empty vector.
inline std::optional<int> max_item(const std::vector<int>& values) {
    if (values.size() == 0) return std::nullopt;
    int largest = values[0];
    for (size_t i = 0; i < values.size(); i ++) {
        if (values[i] > largest)
            largest = values[i];
    }
    return largest;
}

// ex10: Return a reversed copy of the vector.
inline std::vector<int> reversed_copy(const std::vector<int>& values) {
    return std::vector<int>(values.rbegin(), values.rend());
}

// ex11: Append all items from right to the end of left and return the result.
inline std::vector<int> concatenate(const std::vector<int>& left, const std::vector<int>& right) {
    std::vector<int> both(left.size() + right.size());
    size_t i = 0;
    for (auto it = left.begin(); it != left.end(); ++it, ++i)
        both[i] = *it;
    for (auto it = right.begin(); it != right.end(); ++it, ++i)
        both[i] = *it;
    return both;
}

// ex12: Return every item except the first n items. If n is too large, return empty.
inline std::vector<int> drop_first(const std::vector<int>& values, std::size_t n) {
    std::vector<int> out = {};
    if (n >= values.size())
        return out;
    if (n == 0)
        return values;
    for (size_t i = n; i < values.size(); ++i)
        out.push_back(values[i]);
    return out;
}

// ex13: Return the first n items. If n is too large, return all items.
inline std::vector<int> take_first(const std::vector<int>& values, std::size_t n) {
    std::vector<int> out = {};
    for (size_t i = 0; i < values.size() && i < n; i++) {
        out.push_back(values[i]);
    }
    return out;
}

// ex14: Return the sum of items at even indexes: 0, 2, 4, ...
inline int sum_even_indexes(const std::vector<int>& values) {
    (void)values;
    return 0;
}

// ex15: Return true if the vector is sorted in non-decreasing order.
inline bool is_non_decreasing(const std::vector<int>& values) {
    (void)values;
    return false;
}

// ex16: Return a copy with adjacent duplicates collapsed.
// Example: {1, 1, 2, 1, 1, 1, 3} -> {1, 2, 1, 3}
inline std::vector<int> collapse_adjacent_duplicates(const std::vector<int>& values) {
    (void)values;
    return {};
}

// ex17: Return the dot product of two vectors, stopping at the shorter length.
// Example: {1, 2, 3} dot {10, 20} -> 1*10 + 2*20 = 50
inline int dot_product_shortest(const std::vector<int>& left, const std::vector<int>& right) {
    (void)left;
    (void)right;
    return 0;
}

// ex18: Return a vector of pairwise sums, stopping at the shorter length.
// Example: {1, 2, 3}, {10, 20} -> {11, 22}
inline std::vector<int> pairwise_sums(const std::vector<int>& left, const std::vector<int>& right) {
    (void)left;
    (void)right;
    return {};
}

// ex19: Return the index of the first target value, or std::nullopt if absent.
inline std::optional<std::size_t> index_of(const std::vector<int>& values, int target) {
    (void)values;
    (void)target;
    return std::nullopt;
}

// ex20: Return indexes where target appears.
inline std::vector<std::size_t> all_indexes_of(const std::vector<int>& values, int target) {
    (void)values;
    (void)target;
    return {};
}

// ex21: Return a vector of running totals.
// Example: {3, 4, -2, 10} -> {3, 7, 5, 15}
inline std::vector<int> running_totals(const std::vector<int>& values) {
    (void)values;
    return {};
}

// ex22: Split values into {negative_numbers, zero_or_positive_numbers}.
inline std::pair<std::vector<int>, std::vector<int>> partition_negative(
    const std::vector<int>& values
) {
    (void)values;
    return {};
}

// ex23: Return a copy with all occurrences of target removed.
inline std::vector<int> remove_value(const std::vector<int>& values, int target) {
    (void)values;
    (void)target;
    return {};
}

// ex24: Return the unique values in the order they first appear.
inline std::vector<int> unique_in_order(const std::vector<int>& values) {
    (void)values;
    return {};
}

// ex25: Return true if every value in required appears at least once in values.
inline bool contains_all(const std::vector<int>& values, const std::vector<int>& required) {
    (void)values;
    (void)required;
    return false;
}

// ex26: Return values that appear in both vectors, with no duplicates, ordered by first appearance in left.
inline std::vector<int> intersection_in_left_order(
    const std::vector<int>& left,
    const std::vector<int>& right
) {
    (void)left;
    (void)right;
    return {};
}

// ex27: Return a frequency map from each string to its count.
inline std::map<std::string, int> word_counts(const std::vector<std::string>& words) {
    (void)words;
    return {};
}

// ex28: Return words whose length is at least min_length, preserving order.
inline std::vector<std::string> words_at_least(
    const std::vector<std::string>& words,
    std::size_t min_length
) {
    (void)words;
    (void)min_length;
    return {};
}

// ex29: Return the characters in text, excluding spaces.
inline std::vector<char> non_space_characters(const std::string& text) {
    (void)text;
    return {};
}

// ex30: Return a sorted vector of keys whose values are true.
inline std::vector<std::string> enabled_feature_names(const std::map<std::string, bool>& features) {
    (void)features;
    return {};
}

}  // namespace iterables
