#pragma once

#include <iostream>
#include <string>

#include "tamagotchi.h"
class Cat : public Tamagotchi
{
public:
    Cat()
    {
        std::cout << "(•˕•マ.ᐟ" << std::endl;
    }

    void say_meow();

    happiness_level play() override;

    ~Cat()
    {
        std::cout << "ฅ(•˕•マ" << std::endl;
    }
};