#include "dog.h"

void Dog::say_woof()
{
    std::cout << "────୨ৎ────\n";
    std::cout << "૮⍝•ᴥ•⍝ა\n"; 
    std::cout << "────୨ৎ────\n";
}

happiness_level  Dog::play()
{
    Dog::say_woof();
    return Tamagotchi::play();
}