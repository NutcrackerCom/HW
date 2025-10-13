#pragma once

#include <iostream>
#include <string>

enum struct hunger_level
{
    overeating,
    well_fed,
    fine,
    peckish,
    hungry,
    dies_of_hunger
};

enum struct health_level
{
    healthy,
    have_a_cold,
    sick,
};

enum struct happiness_level
{
    happy,
    calm,
    sad,
    depression
};

struct hunger_status
{
    static hunger_level get_status(int hunger_value);

    static std::string get_description(hunger_level level);

};

struct health_status
{
    static health_level get_status(int health_value);

    static std::string get_description(health_level level);
};

struct happiness_status
{
    static happiness_level get_status(int happiness_value);

    static std::string get_description(happiness_level level);
};