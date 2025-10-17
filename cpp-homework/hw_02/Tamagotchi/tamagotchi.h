#pragma once

#include <iostream>
#include <string>
#include <map>

#include "tamagotchi_status.h"

class Tamagotchi
{
public:
    Tamagotchi(){}

    hunger_level feed();

    happiness_level virtual play();

    void print_all_status();

    void virtual make_a_sound();

    void virtual sleep([[maybe_unused]] uint hours=0);

protected:
    uint sleep_hours = 0;
    
private:
    bool new_day();
    
    int health = 100;
    int hunger = 100;
    int happiness = 100;
    uint day = 0;
    const std::map<hunger_level, int> hunger_to_health = {{hunger_level::hungry, 10}, {hunger_level::dies_of_hunger, 30}, {hunger_level::overeating, 5}};
    const std::map<happiness_level, int> happiness_to_health = {{happiness_level::depression, 30}, {happiness_level::happy, 20} ,{happiness_level::sad, 10}};
    const std::map<health_level, int> health_to_health = {{health_level::healthy, 10}}; // ??
};
