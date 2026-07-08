#pragma once

#include <string>
#include <vector>

namespace stage_03::practice::const_correct_api_exercise {

class Inventory {
public:
    void add_item(std::string item);

    std::size_t size() const;
    bool contains(const std::string& item) const;
    const std::string& item_at(std::size_t index) const;

private:
    std::vector<std::string> items_;
};

}  // namespace stage_03::practice::const_correct_api_exercise
