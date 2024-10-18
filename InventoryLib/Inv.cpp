#include "pch.h"
#include "Inv.h"
#include <algorithm>
#include <iostream>
#include "Weapon.h"
#include "Armor.h"
#include "Element.h"

void InventoryLib::addItem(std::unique_ptr<Item> item) {
    items.push_back(std::move(item));
}

Item* InventoryLib::getItem(int index) {
    if (index >= 0 && index < items.size()) {
        return items[index].get();
    }
    return nullptr;
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

void InventoryLib::displayInventoryByType(const std::string& type) const {
    bool headerShown = false;

    for (size_t i = 0; i < items.size(); ++i) {
        const auto& item = items[i];
        if (item->getType() == type) {
            if (!headerShown) {
                std::cout << "\n\t\t=== " << (type == "Weapon" ? "ARMES" : "ARMURES") << " ===\n";
                headerShown = true;
            }
            std::cout << "ID: " << i << " - " << item->getName() << " (" << item->getType() << ")\n";
        }
    }
}
void InventoryLib::displayInventory() const {
    bool weaponsShown = false;
    bool armorsShown = false;
    bool potionsShown = false;

    for (size_t i = 0; i < items.size(); ++i) {
        const auto& item = items[i];
        if (item->getType() == "Weapon" && !weaponsShown) {
            std::cout << "\n\t\t=== ARMES ===\n";
            weaponsShown = true;
        }
        if (item->getType() == "Armor" && !armorsShown) {
            std::cout << "\n\t\t=== ARMURES ===\n";
            armorsShown = true;
        }
        if (item->getType() == "Potion" && !potionsShown) {
            std::cout << "\n=== POTIONS ===\n";
            potionsShown = true;
        }
        std::cout << "ID: " << i << "\t" << item->getName() << " (" << item->getType() << ")\n";
    }
}

void InventoryLib::addItemsFromList(const std::vector<std::unique_ptr<Item>>& allItems) {
    for (const auto& item : allItems) {
        if (auto weapon = dynamic_cast<Weapon*>(item.get())) {
            addItem(std::make_unique<Weapon>(*weapon)); 
        }
        else if (auto armor = dynamic_cast<Armor*>(item.get())) {
            addItem(std::make_unique<Armor>(*armor)); 
        }
    }
}

std::vector<Item*> InventoryLib::searchByStat(int minStat, int maxStat) const {
    std::vector<Item*> result;

    for (const auto& item : items) {
        if (auto weapon = dynamic_cast<Weapon*>(item.get())) {
            if (weapon->getAttack() >= minStat && weapon->getAttack() <= maxStat) { 
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

void InventoryLib::sortByElement() {
    std::sort(items.begin(), items.end(), [](const std::unique_ptr<Item>& a, const std::unique_ptr<Item>& b) {
        return static_cast<int>(a->getElement()) < static_cast<int>(b->getElement());
        });
}



std::vector<Item*> InventoryLib::getItems() const {
    std::vector<Item*> result; 
    for (const auto& item : items) {
        result.push_back(item.get());  
    }
    return result;
}


void InventoryLib::displayItems() const {
    std::cout << "Items dans l'inventaire:\n";
    for (const auto& item : items) {
        std::cout << item->getName() << " (" << item->getType() << ")\n";
    }
}


std::vector<Item*> InventoryLib::searchByCriteria(const std::string& name, const std::string& type,
    int minAttack, int maxAttack,
    int minDefense, int maxDefense,
    const std::string& element) const {
    std::vector<Item*> results;

    for (const auto& item : items) {
        bool matches = true;

        if (!name.empty() && item->getName().find(name) == std::string::npos) {
            matches = false; 
        }
        if (!type.empty() && item->getType() != type) {
            matches = false;
        }

        if (auto weapon = dynamic_cast<Weapon*>(item.get())) {
            if ((minAttack > 0 && weapon->getAttack() < minAttack) ||
                (maxAttack > 0 && weapon->getAttack() > maxAttack)) {
                matches = false;
            }
        }
        else if (auto armor = dynamic_cast<Armor*>(item.get())) {
            if ((minDefense > 0 && armor->getDefense() < minDefense) ||
                (maxDefense > 0 && armor->getDefense() > maxDefense)) {
                matches = false;
            }
        }

        if (!element.empty() && item->getElement() != fromString(element)) {
            matches = false;
        }

        if (matches) {
            results.push_back(item.get());
        }
    }

    return results;
}
