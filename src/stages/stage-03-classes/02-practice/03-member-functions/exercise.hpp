#pragma once

namespace stage_03::practice::member_functions_exercise {

class Thermostat {
public:
    explicit Thermostat(int temperature);

    int temperature() const;
    void warm_up();
    void cool_down();
    void set_temperature(int temperature);

private:
    int temperature_;
};

}  // namespace stage_03::practice::member_functions_exercise
