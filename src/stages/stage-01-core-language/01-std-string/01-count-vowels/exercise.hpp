#pragma once

#include <cstddef>
#include <string_view>

namespace stage_01::std_string::count_vowels_exercise {

bool is_vowel(char c);

std::size_t count_vowels(std::string_view text);

}  // namespace stage_01::std_string::count_vowels_exercise
