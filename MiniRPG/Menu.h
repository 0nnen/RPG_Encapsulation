#pragma once
#include "Character.h"
#include "Inv.h"
#include "Combat.h"
#include "Inv.h"
#include <iostream>
#include <string>
#include <limits>

class Menu {
public:
    static void showMainMenu(Character& character1, Character& character2);
    static void showManageCharactersMenu(Character& character1, Character& character2);
    static void showCharacterMenu(Character& character);
    static void searchItems(InventoryLib& inventory);
};
