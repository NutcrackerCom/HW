#include "tamagotchi.h"
#include "cat.h"
#include "dog.h"
#include "jellyfish.h"

int main()
{
    Jellyfish tom;
    tom.play();
    tom.print_all_status();

    Cat cat;
    cat.play();
    cat.print_all_status();

    Dog dog;
    dog.play();
    dog.print_all_status();
}