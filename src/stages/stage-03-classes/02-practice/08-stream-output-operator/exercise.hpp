#pragma once

#include <iosfwd>
#include <string>

namespace stage_03::practice::stream_output_operator_exercise {

class NameTag {
public:
    NameTag(std::string first, std::string last);

    const std::string& first() const;
    const std::string& last() const;

private:
    std::string first_;
    std::string last_;
};

std::ostream& operator<<(std::ostream& stream, const NameTag& tag);

}  // namespace stage_03::practice::stream_output_operator_exercise
