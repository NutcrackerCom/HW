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

void Jellyfish::sleep(uint hours)
{
    sleep_hours+=hours;
    if(sleep_hours>=jellyfish_sleep_hours)
    {
        sleep_hours-=sleep_hours;
        Tamagotchi::sleep();
    }
}