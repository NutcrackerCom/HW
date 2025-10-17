#pragma once

#include <iostream>
#include <string>

#include "tamagotchi.h"

#define dogs_sleep_hours 8

class Dog : public Tamagotchi
{
public:
    Dog()
    {
        std::cout << "૮･ﻌ･ა" << std::endl;
    }

    void make_a_sound() override;

    happiness_level  play() override;

    void sleep(uint hours=0) override;

    ~Dog()
    {
        std::cout << "૮•ﻌ-ა" << std::endl;
    }
};
