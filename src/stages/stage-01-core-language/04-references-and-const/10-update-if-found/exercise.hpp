#pragma once

#include <map>
#include <string>
#include <string_view>

namespace stage_01::references_const::update_if_found_exercise {

bool update_if_found(std::map<std::string, int>& values, std::string_view key, int new_value);

}  // namespace stage_01::references_const::update_if_found_exercise
