#pragma once

#include <iostream>
#include <string>
#include <random>

#include "tamagotchi.h"

#define cats_sleep_hours 12
class Cat : public Tamagotchi
{
public:
    Cat()
    {
        std::cout << "(•˕•マ.ᐟ" << std::endl;
    }

    void make_a_sound() override;

    happiness_level play() override;

    void sleep(uint hours=0) override;

    ~Cat()
    {
        std::cout << "ฅ(•˕•マ" << std::endl;
    }
};