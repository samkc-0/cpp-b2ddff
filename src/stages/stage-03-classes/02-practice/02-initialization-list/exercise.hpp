#pragma once

#include <string>

namespace stage_03::practice::initialization_list_exercise {

class UserProfile {
public:
    UserProfile(std::string username, int reputation);

    const std::string& username() const;
    int reputation() const;

private:
    const std::string username_;
    const int reputation_;
};

}  // namespace stage_03::practice::initialization_list_exercise
