#pragma once

#include <iostream>
#include <string>
#include <random>

#include "tamagotchi.h"
class Cat : public Tamagotchi
{
public:
    Cat()
    {
        std::cout << "(•˕•マ.ᐟ" << std::endl;
    }

    void make_a_sound() override;

    happiness_level play() override;

    ~Cat()
    {
        std::cout << "ฅ(•˕•マ" << std::endl;
    }
};