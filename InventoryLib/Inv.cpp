#include "pch.h"
#include "Inv.h"
#include <algorithm>
#include <iostream>
#include "Weapon.h"
#include "Armor.h"

void InventoryLib::addItem(std::unique_ptr<Item> item) {
    items.push_back(std::move(item));
}

bool InventoryLib::removeItem(const std::string& itemName) {
    auto it = std::remove_if(items.begin(), items.end(),
        [&itemName](const std::unique_ptr<Item>& item) {
            return item->getName() == itemName;
        });
    if (it != items.end()) {
        items.erase(it, items.end());
        return true;
    }
    return false;
}

std::vector<Item*> InventoryLib::searchByStat(int minStat, int maxStat) const {
    std::vector<Item*> result;

    for (const auto& item : items) {
        if (auto weapon = dynamic_cast<Weapon*>(item.get())) {
            if (weapon->getDamage() >= minStat && weapon->getDamage() <= maxStat) {
                result.push_back(weapon);
            }
        }
        else if (auto armor = dynamic_cast<Armor*>(item.get())) {
            if (armor->getDefense() >= minStat && armor->getDefense() <= maxStat) {
                result.push_back(armor);
            }
        }
    }

    return result;
}

void InventoryLib::sortByType() {
    std::sort(items.begin(), items.end(), [](const std::unique_ptr<Item>& a, const std::unique_ptr<Item>& b) {
        return a->getType() < b->getType();
        });
}

std::vector<Item*> InventoryLib::getItems() const {
    std::vector<Item*> result; // Utilisation de Item*
    for (const auto& item : items) {
        result.push_back(item.get());  // Ajout des pointeurs
    }
    return result;
}


void InventoryLib::displayItems() const {
    std::cout << "Items dans l'inventaire:\n";
    for (const auto& item : items) {
        std::cout << item->getName() << " (" << item->getType() << ")\n";
    }
}

