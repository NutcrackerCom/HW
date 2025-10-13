#pragma once

#include <iostream>
#include <string>

#include "tamagotchi.h"

class Dog : public Tamagotchi
{
public:
    Dog()
    {
        std::cout << "૮･ﻌ･ა" << std::endl;
    }

    void say_woof();

    happiness_level  play() override;

    ~Dog()
    {
        std::cout << "૮•ﻌ-ა" << std::endl;
    }
};
