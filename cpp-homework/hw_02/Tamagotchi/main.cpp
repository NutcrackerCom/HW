#include "tamagotchi.h"
#include "cat.h"
#include "dog.h"
#include "jellyfish.h"

int main()
{
    Cat cat;
    cat.print_all_status();
    cat.sleep(11);
    cat.print_all_status();
    cat.sleep(11);
    cat.print_all_status();
    cat.sleep(11);
    cat.print_all_status();
    cat.sleep(11);
    cat.print_all_status();
    
}

// todo
/*
Добавить инвертарь с монентами 
Пусть монеты даются за конец дня 

Добавить магазин, где можно будет купить игрушки для пета

Сделать сохранение и загрузку из файла 
*/