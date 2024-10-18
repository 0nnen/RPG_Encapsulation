#pragma once
#include "Character.h"
#include "Inv.h"

class Menu {
public:
    static void showMainMenu(Character& character1, Character& character2);
    static void showManageCharactersMenu(Character& character1, Character& character2);
    static void showCharacterMenu(Character& character);
    static void searchItems(InventoryLib& inventory);
};
