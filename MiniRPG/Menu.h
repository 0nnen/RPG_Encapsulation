#pragma once
#include <iostream>
#include <string>
#include <limits>
#include "Character.h"
#include "Inv.h"
#include "Combat.h"

class Character;

class Menu {
public:
    static void showMainMenu(Character& character1, Character& character2, const std::vector<std::unique_ptr<Item>>& availableItems);
    static void showManageCharactersMenu(Character& character1, Character& character2);
    static void showCharacterMenu(Character& character);
    static void searchItems(InventoryLib& inventory);
    static void waitForEnter();
    static void manageInventory(Character& character);
};
