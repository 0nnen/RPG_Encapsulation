#pragma once
#include "Character.h"

class Menu {
public:
    static void showMainMenu(Character& character1, Character& character2);
    static void showManageCharactersMenu(Character& character1, Character& character2);
    static void showCharacterMenu(Character& character);
};
