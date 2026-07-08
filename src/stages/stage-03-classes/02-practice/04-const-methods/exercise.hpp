#pragma once

#include <string>

namespace stage_03::practice::const_methods_exercise {

class Label {
public:
    explicit Label(std::string text);

    const std::string& text() const;
    std::size_t length() const;
    bool is_empty() const;
    void clear();

private:
    std::string text_;
};

}  // namespace stage_03::practice::const_methods_exercise
