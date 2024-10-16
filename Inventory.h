#pragma once
#include <vector>
#include <iostream>
#include <memory>
#include "Item.h"
#include "Weapon.h"
#include "Armor.h"

class Inventory {
private:
    std::vector<std::unique_ptr<Item>> items;

public:
    void addItem(std::unique_ptr<Item> item);
    Item* getItem(int index);
    void displayInventory() const;
    void loadInventoryFromFile(const std::string& filePath);
};
