#include "tamagotchi_status.h"

hunger_level hunger_status::get_status(int hunger_value)
{
    if(hunger_value>=140) return hunger_level::overeating;
    else if(hunger_value>=120) return hunger_level::well_fed;
    else if(hunger_value>=100) return hunger_level::fine;
    else if(hunger_value>=80) return hunger_level::peckish;
    else if(hunger_value>=60) return hunger_level::hungry;
    else return hunger_level::dies_of_hunger;
}

std::string hunger_status::get_description(hunger_level level)
{
    switch (level)
    {
    case hunger_level::overeating:
        return "Сильно переел";
    case hunger_level::well_fed:
        return "Сыт с верхом";
    case hunger_level::fine:
        return "Сыт";
    case hunger_level::peckish:
        return "Слегка голоден";
    case hunger_level::hungry:
        return "Голоден";
    case hunger_level::dies_of_hunger:
        return "Смертельно голоден"; 
    default:
        return "";
    }
}

health_level health_status::get_status(int health_value)
{
    if(health_value>=100) return health_level::healthy;
    else if(health_value>=80) return health_level::have_a_cold;
    else return health_level::sick;
}

std::string health_status::get_description(health_level level)
{
    switch (level)
    {
    case health_level::healthy:
        return "Здоров";
    case health_level::have_a_cold:
        return "Приболел";
    case health_level::sick:
        return "Болеет";
    default:
        return "";
    }
}

happiness_level happiness_status::get_status(int happiness_value)
{
    if(happiness_value>=100) return happiness_level::happy;
    else if(happiness_value>=80) return happiness_level::calm;
    else if(happiness_value>=60) return happiness_level::sad;
    else return happiness_level::depression;
}

std::string happiness_status::get_description(happiness_level level)
{
    switch (level)
    {
    case happiness_level::happy:
        return "Счастлив";
    case happiness_level::calm:
        return "Спокойный";
    case happiness_level::sad:
        return "Грустный";
    case happiness_level::depression:
        return "В деперссии";
    default:
        return "";
    }
}