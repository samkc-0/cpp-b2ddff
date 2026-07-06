#pragma once

#include <map>
#include <optional>
#include <string>

namespace stage_01::std_optional::find_key_by_value_exercise {

std::optional<std::string> find_key_by_value(const std::map<std::string, int>& values, int target);

}  // namespace stage_01::std_optional::find_key_by_value_exercise
