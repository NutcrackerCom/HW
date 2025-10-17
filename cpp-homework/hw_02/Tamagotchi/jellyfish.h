#pragma once

#include <iostream>
#include <string>

#include "tamagotchi.h"

#define jellyfish_sleep_hours 4

class Jellyfish : public Tamagotchi
{
public:
    Jellyfish()
    {
        std::cout << "ଳ" << std::endl;
    }

    void make_a_sound() override;

    happiness_level play() override;

    void sleep(uint hours=0) override;

    ~Jellyfish()
    {
        std::cout << "⋅˚₊‧ ଳ ‧₊˚ ⋅" << std::endl;
    }
};