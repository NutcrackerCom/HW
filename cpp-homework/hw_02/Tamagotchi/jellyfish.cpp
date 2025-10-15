#include "jellyfish.h"

void Jellyfish::make_a_sound()
{
    std::cout << "────୨ৎ────\n";
    std::cout << "∘˙○˚.•\n"; 
    std::cout << "────୨ৎ────\n";
}

happiness_level Jellyfish::play()
{
    Jellyfish::make_a_sound();
    return Tamagotchi::play();
}