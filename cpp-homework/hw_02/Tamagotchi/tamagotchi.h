#pragma once

#include <iostream>
#include <string>

#include "tamagotchi_status.h"
class Tamagotchi
{
public:
    Tamagotchi(){}

    hunger_level feed();

    happiness_level virtual play();

    void new_day();

    void print_all_status();

private:
    int health = 100;
    int hunger = 100;
    int happiness = 100;
    uint day = 0;
};
