#include "cat.h"

void Cat::say_meow()
{
    std::cout << "────୨ৎ────\n";
    std::cout << "ദ്ദി（•˕•マ.ᐟ\n"; 
    std::cout << "────୨ৎ────\n";
}

happiness_level Cat::play()
{
    Cat::say_meow();
    return Tamagotchi::play();
}