#pragma once
#include <vector>
#include <iostream>
#include "Item.h"

class Inventory {
private:
    // Utilisation de std::unique_ptr pour g�rer la m�moire automatiquement
    std::vector<std::unique_ptr<Item>> items;

public:
    void addItem(std::unique_ptr<Item> item);

    Item* getItem(int index);

    void displayInventory() const;
};
