#include "tamagotchi.h"

hunger_level Tamagotchi::feed()
{
    hunger+=20;
    hunger_level status = hunger_status::get_status(hunger);
    if(status==hunger_level::overeating) health-=5;
    std::cout << hunger_status::get_description(status)<<std::endl;
    return status;
}

happiness_level Tamagotchi::play()
{
    happiness+=20;
    happiness_level status = happiness_status::get_status(happiness);
    std::cout << happiness_status::get_description(status)<<std::endl;
    return status;
}

void Tamagotchi::new_day()
{
    happiness-=10;
    hunger-=30;
    happiness_level hpy_status = happiness_status::get_status(happiness);
    hunger_level hgr_status = hunger_status::get_status(hunger);

    if(hpy_status == happiness_level::depression) health-=30;
    else if(hpy_status == happiness_level::sad) health-=10;
    if(hgr_status == hunger_level::dies_of_hunger) health-=30;
    else if(hgr_status == hunger_level::hungry) health-=10;
    else if(hgr_status == hunger_level::overeating) health-=5;

    if(health <= 0) std::cout << "Ваш питомец умер\n";

}

void Tamagotchi::print_all_status()
{
    happiness_level hpy_status = happiness_status::get_status(happiness);
    hunger_level hgr_status = hunger_status::get_status(hunger); 
    health_level hp_status = health_status::get_status(health);
    std::cout << "=========================\n";
    std::cout << "health - " << health_status::get_description(hp_status) << std::endl;
    std::cout << "happiness - " << happiness_status::get_description(hpy_status) << std::endl;
    std::cout << "hunger - " << hunger_status::get_description(hgr_status) << std::endl;
    std::cout << "=========================\n";
}