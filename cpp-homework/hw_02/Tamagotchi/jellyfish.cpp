#include "jellyfish.h"

void Jellyfish::say_bul_bul()
{
    std::cout << "────୨ৎ────\n";
    std::cout << "∘˙○˚.•\n"; 
    std::cout << "────୨ৎ────\n";
}

happiness_level Jellyfish::play()
{
    Jellyfish::say_bul_bul();
    return Tamagotchi::play();
}