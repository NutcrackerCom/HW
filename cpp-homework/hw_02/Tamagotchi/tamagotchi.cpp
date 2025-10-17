#include "tamagotchi.h"

hunger_level Tamagotchi::feed()
{
    // надо добавить разные явства и вынести hunger в наследников
    // давать разный баф от разной еды
    hunger+=20;
    hunger_level status = hunger_status::get_status(hunger);
    if(status==hunger_level::overeating) health-= hunger_to_health.at(status);
    std::cout << hunger_status::get_description(status)<<std::endl;
    return status;
}

happiness_level Tamagotchi::play()
{
    // добавить разные виды игр и бонус от них
    // сделать так что бы кот не играл с косточкой, а пес с мышкой 
    happiness+=happiness_to_health.at(happiness_level::happy); // ?? 
    happiness_level status = happiness_status::get_status(happiness);
    std::cout << happiness_status::get_description(status)<<std::endl;
    return status;
}

bool Tamagotchi::new_day()
{
    // надо ли создавать структуру с дебафами за прошедший день ?

    happiness-=happiness_to_health.at(happiness_level::sad); // ??
    hunger-=hunger_to_health.at(hunger_level::dies_of_hunger); // ??
    happiness_level hpy_status = happiness_status::get_status(happiness);
    hunger_level hgr_status = hunger_status::get_status(hunger);

    if(hpy_status == happiness_level::depression) health-=happiness_to_health.at(hpy_status);
    else if(hpy_status == happiness_level::sad) health-=happiness_to_health.at(hpy_status);
    if(hgr_status == hunger_level::dies_of_hunger) health-=hunger_to_health.at(hgr_status);
    else if(hgr_status == hunger_level::hungry) health-=hunger_to_health.at(hgr_status);
    else if(hgr_status == hunger_level::overeating) health-=hunger_to_health.at(hgr_status);

    if(health <= 0)
    {
        // можно добавить вывод статистики при конце игры
        std::cout << "Ваш питомец умер\n";
        return false;
    }
    else health+=health_to_health.at(health_level::healthy); // ??
    return true;

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

void Tamagotchi::make_a_sound() {};

void Tamagotchi::sleep([[maybe_unused]] uint hours)
{
    new_day();
}