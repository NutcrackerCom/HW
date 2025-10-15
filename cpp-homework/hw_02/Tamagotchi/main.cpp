#include "tamagotchi.h"
#include "cat.h"
#include "dog.h"
#include "jellyfish.h"

int main()
{
    Cat cat;
    cat.print_all_status();
    cat.new_day();
    cat.print_all_status();
    cat.new_day();
    cat.print_all_status();
    cat.new_day();
    cat.print_all_status();
    cat.new_day();
    cat.print_all_status();
    cat.new_day();
}