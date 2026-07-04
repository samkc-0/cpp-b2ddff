#pragma once

#include <algorithm>
#include <map>
#include <numeric>
#include <optional>
#include <set>
#include <string>
#include <utility>
#include <vector>

namespace iterables {

// Progress note after ex01-ex13:
// You have the basics: size checks, indexing, push_back, copying, reverse
// iterators, and simple iterator loops. The next exercises are grouped as short
// lessons. Read each lesson comment, then solve the exercises directly below it.
// The goal is to choose the right iteration tool instead of always reaching for:
//     for (std::size_t i = 0; i < values.size(); ++i)

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

// Lesson 1: Indexes are not bad; they are just specific.
//
// Use an index loop when the position itself matters: every second element,
// matching output positions, or returning indexes. If you only need each value,
// prefer a range-for loop:
//
//     for (int value : values) { ... }
//
// If you need both value and position, a useful middle ground is range-for plus
// a separate counter:
//
//     std::size_t index = 0;
//     for (int value : values) {
//         ...
//         ++index;
//     }
//

// ex14: Return the sum of items at even indexes: 0, 2, 4, ...
// Practice: use an index loop that steps by 2.
inline int sum_even_indexes(const std::vector<int>& values) {
    int out = 0;
    for (size_t i = 0; i < values.size(); i += 2) {
        out += values[i];
    }
    return out;
}

// ex20: Return indexes where target appears.
// Practice: use a range-for loop with a separate index counter.
inline std::vector<std::size_t> all_indexes_of(const std::vector<int>& values, int target) {
    auto out = std::vector<size_t>();
    size_t i = 0;
    for (int x : values) {
        if (x == target)
            out.push_back(i);
        ++i;
    }
    return out;
}

// Lesson 2: Neighboring values are often easier with iterators or algorithms.
//
// To compare adjacent elements, you can walk two iterators together:
//
//     auto previous = values.begin();
//     auto current = previous + 1;
//
// C++ also has algorithms for common range questions. For sortedness, look up
// std::is_sorted. Algorithms can be clearer because the name says the intent.
//

// ex15: Return true if the vector is sorted in non-decreasing order.
// Practice: prefer std::is_sorted, std::adjacent_find, or neighboring iterators.
inline bool is_non_decreasing(const std::vector<int>& values) {
    if (values.size() < 2) return true;
    for (auto it = values.begin(); it != values.end() - 1; ++it) {
        if (*it > *(it + 1)) return false;
    }
    return true;
}

// ex16: Return a copy with adjacent duplicates collapsed.
// Example: {1, 1, 2, 1, 1, 1, 3} -> {1, 2, 1, 3}
// Practice: range-for over values and compare against out.back() once non-empty.
inline std::vector<int> collapse_adjacent_duplicates(const std::vector<int>& values) {
    std::vector<int> out = {};
    for (auto x : values) {
        if (out.empty() || x != out.back())
            out.push_back(x);
    }
    return out;
}

// Lesson 3: Some problems walk two ranges at the same time.
//
// Indexing two vectors works, but it hides an important iterator pattern. Use two
// iterators and advance them together:
//
//     auto left_it = left.begin();
//     auto right_it = right.begin();
//     while (left_it != left.end() && right_it != right.end()) {
//         ...
//         ++left_it;
//         ++right_it;
//     }
//
// This same idea works for vector, string, list, deque, and many other ranges.
//

// ex17: Return the dot product of two vectors, stopping at the shorter length.
// Example: {1, 2, 3} dot {10, 20} -> 1*10 + 2*20 = 50
// Practice: use two iterators that advance together.
inline int dot_product_shortest(const std::vector<int>& left, const std::vector<int>& right) {
    int prod = 0;
    for (auto l = left.begin(), r = right.begin(); l != left.end() && r != right.end(); ++l, ++r) {
        prod += ((*l) * (*r));
    }
    return prod;
}

// ex18: Return a vector of pairwise sums, stopping at the shorter length.
// Example: {1, 2, 3}, {10, 20} -> {11, 22}
// Practice: use two iterators and reserve capacity for the shorter length.
inline std::vector<int> pairwise_sums(const std::vector<int>& left, const std::vector<int>& right) {
    std::vector<int> sums;
    size_t shortest = std::min(left.size(), right.size());
    sums.reserve(shortest);
    auto l = left.begin();
    auto r = right.begin();
    for (; l != left.end() && r != right.end(); ++l, ++r)
        sums.push_back((*r)+(*l));
    return sums;
}

// Lesson 4: Algorithms return useful iterator positions.
//
// std::find does not return the value. It returns an iterator pointing at the
// value, or end() if the value was not found:
//
//     auto it = std::find(values.begin(), values.end(), target);
//     if (it == values.end()) { ... not found ... }
//
// If you need the numeric index, convert the iterator with std::distance.
//

// ex19: Return the index of the first target value, or std::nullopt if absent.
// Practice: use std::find, then convert the iterator distance back to an index.
inline std::optional<std::size_t> index_of(const std::vector<int>& values, int target) {
    auto found = std::find(values.begin(), values.end(), target);
    if (found != values.end()) return std::distance(values.begin(), found);
    return std::nullopt;
}

// Lesson 5: Range-for loops are ideal when you are transforming or filtering.
//
// A range-for loop says "do this once per element" without exposing indexing
// details. It is the default tool for scanning all values:
//
//     for (int value : values) {
//         out.push_back(value);
//     }
//
// When building output vectors, call reserve when you know a useful capacity.
// reserve changes capacity, not size, so you still push_back values afterward.
//

// ex21: Return a vector of running totals.
// Example: {3, 4, -2, 10} -> {3, 7, 5, 15}
// Practice: keep a running int total across a range-for loop.
inline std::vector<int> running_totals(const std::vector<int>& values) {
    int total = 0;
    std::vector<int> out;
    out.reserve(values.size());
    for (auto x : values) {
        total += x;
        out.push_back(total);
    }
    return out;
}

// ex22: Split values into {negative_numbers, zero_or_positive_numbers}.
// Practice: use range-for and push each value into one of two named vectors.
inline std::pair<std::vector<int>, std::vector<int>> partition_negative(
    const std::vector<int>& values
) {
    std::vector<int> negative_numbers = {};
    std::vector<int> zero_or_positive_numbers = {};

    for (auto x : values) {
        if (x >= 0)
            zero_or_positive_numbers.push_back(x);
        else
            negative_numbers.push_back(x);
    }

    return std::make_pair(
        negative_numbers,
        zero_or_positive_numbers
    );
}

// ex23: Return a copy with all occurrences of target removed.
// Practice: use std::copy_if or a range-for filter.
inline std::vector<int> remove_value(const std::vector<int>& values, int target) {
    std::vector<int> out;
    std::copy_if(
        values.begin(),
        values.end(),
        std::back_inserter(out),
        [&](int x){ return x != target; }
    );
    return out;
}

// Lesson 6: Sets answer membership questions.
//
// A std::set stores unique values and can quickly answer "have I seen this?" or
// "is this required value present?". Common pattern:
//
//     std::set<int> seen;
//     if (seen.insert(value).second) {
//         ... value was not already present ...
//     }
//
// Use a vector for output order, and a set for membership memory.
//

// ex24: Return the unique values in the order they first appear.
// Practice: use a set to remember seen values and a vector for output order.
inline std::vector<int> unique_in_order(const std::vector<int>& values) {
    std::set<int> seen;
    std::vector<int> out;
    out.reserve(values.size());
    for (int x : values) {
        if (seen.insert(x).second)
            out.push_back(x);
    }
    return out;
}

// ex25: Return true if every value in required appears at least once in values.
// Practice: convert values to a set, then check every required item.
inline bool contains_all(const std::vector<int>& values, const std::vector<int>& required) {
    std::set<int> unique(values.begin(), values.end());
    for (auto x : required) {
        if (!unique.contains(x)) return false;
    }
    return true;
}

// ex26: Return values that appear in both vectors, with no duplicates, ordered by first appearance in left.
// Practice: use one set for right-side membership and one set for emitted values.
inline std::vector<int> intersection_in_left_order(
    const std::vector<int>& left,
    const std::vector<int>& right
) {
    std::vector<int> intersection = {};
    std::set<int> R(right.begin(), right.end());
    std::set<int> seen;
    for (auto l : left) {
        if (!seen.contains(l) && R.find(l) != R.end())
            intersection.push_back(l);
        seen.insert(l);
    }
    return intersection;
}

// Lesson 7: Maps store values by key.
//
// A std::map<std::string, int> is useful for counting. operator[] creates a
// missing key with a default value, so this increments existing and new words:
//
//     counts[word] += 1;
//
// std::map iterates in sorted key order. Structured bindings make map loops much
// easier to read:
//
//     for (const auto& [key, value] : my_map) { ... }
//

// ex27: Return a frequency map from each string to its count.
// Practice: use map operator[] to increment each word's count.
inline std::map<std::string, int> word_counts(const std::vector<std::string>& words) {
    std::map<std::string, int> counts;
    for (const std::string& w : words) {
        counts[w] += 1;
    }
    return counts;
}

// ex30: Return a sorted vector of keys whose values are true.
// Practice: range-for over the map with structured bindings.
inline std::vector<std::string> enabled_feature_names(const std::map<std::string, bool>& features) {
    std::vector<std::string> out = {};
    for (const auto& [k, enabled] : features) {
        if (enabled) {
            out.push_back(k);
        }
    }
    return out;
}

// Lesson 8: Strings are iterable ranges of char.
//
// You can range-for over a std::string just like a vector:
//
//     for (char ch : text) { ... }
//
// For a vector of strings, each element is a std::string, so use word.size() to
// test its length. Avoid C string tools like strlen here.
//

// ex28: Return words whose length is at least min_length, preserving order.
// Practice: range-for over strings and test word.size().
inline std::vector<std::string> words_at_least(
    const std::vector<std::string>& words,
    std::size_t min_length
) {
    std::vector<std::string> out;
    for (const std::string& w : words) {
        if (w.length() >= min_length)
            out.push_back(w);
    }
    return out;
}

// ex29: Return the characters in text, excluding spaces.
// Practice: range-for over char values in a std::string.
inline std::vector<char> non_space_characters(const std::string& text) {
    std::vector<char> out;
    for (auto c : text) {
        if (c != ' ') out.push_back(c);
    }
    return out;
}

}  // namespace iterables
