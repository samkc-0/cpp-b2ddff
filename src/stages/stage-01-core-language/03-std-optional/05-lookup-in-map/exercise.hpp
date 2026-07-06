#pragma once

#include <map>
#include <optional>
#include <string>
#include <string_view>

namespace stage_01::std_optional::lookup_in_map_exercise {

std::optional<int> lookup_in_map(const std::map<std::string, int>& values, std::string_view key);

}  // namespace stage_01::std_optional::lookup_in_map_exercise
