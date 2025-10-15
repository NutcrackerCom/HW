#pragma once

#include <iostream>
#include <string>

#include "tamagotchi.h"

class Jellyfish : public Tamagotchi
{
public:
    Jellyfish()
    {
        std::cout << "ଳ" << std::endl;
    }

    void make_a_sound() override;

    happiness_level play() override;

    ~Jellyfish()
    {
        std::cout << "⋅˚₊‧ ଳ ‧₊˚ ⋅" << std::endl;
    }
};