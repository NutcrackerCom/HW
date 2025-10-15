#include "cat.h"

void Cat::make_a_sound()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(0, 1);
    if(distrib(gen))
    {
        std::cout << "────୨ৎ────\n";
        std::cout << "ദ്ദി（•˕•マ.ᐟ\n"; 
        std::cout << "────୨ৎ────\n";
    }
    else
    {
        std::cout << "────୨ৎ────\n";
        std::cout << "/ᐠ•᷄˕•᷅マ\n"; 
        std::cout << "────୨ৎ────\n";
    }
}

happiness_level Cat::play()
{
    Cat::make_a_sound();
    return Tamagotchi::play();
}