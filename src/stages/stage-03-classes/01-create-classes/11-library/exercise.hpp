#pragma once

#include <optional>
#include <string>
#include <string_view>
#include <vector>

namespace stage_03::classes::library_exercise {

class Library {
public:
    void add_book(std::string title);
    bool contains(std::string_view title) const;
    std::optional<std::string> find_by_prefix(std::string_view prefix) const;
    std::size_t size() const;

private:
    std::vector<std::string> titles_;
};

}  // namespace stage_03::classes::library_exercise
