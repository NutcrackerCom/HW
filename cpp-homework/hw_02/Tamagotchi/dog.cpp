#include "dog.h"

void Dog::make_a_sound()
{
    std::cout << "────୨ৎ────\n";
    std::cout << "૮⍝•ᴥ•⍝ა\n"; 
    std::cout << "────୨ৎ────\n";
}

happiness_level  Dog::play()
{
    Dog::make_a_sound();
    return Tamagotchi::play();
}