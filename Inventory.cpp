#include "Inventory.h"
#include "Item.h"
#include "Weapon.h"
#include "Armor.h"
#include <iostream>

void Inventory::addItem(std::unique_ptr<Item> item) {
    items.push_back(std::move(item));
}

Item* Inventory::getItem(int index) {
    if (index >= 0 && index < items.size()) {
        return items[index].get();
    }
    return nullptr;
}

void Inventory::displayInventory() const {
    for (const auto& item : items) {
        std::cout << "Item: " << item->getName() << " (" << item->getType() << ")\n";
    }
}

// Ajoute les objets à l'inventaire
void Inventory::addItemsFromList(const std::vector<std::unique_ptr<Item>>& allItems) {
    for (const auto& item : allItems) {
        // Ajoute une copie de l'objet en vérifiant s'il s'agit d'une arme ou d'une armure
        if (auto weapon = dynamic_cast<Weapon*>(item.get())) {
            addItem(std::make_unique<Weapon>(*weapon));  // Copie l'objet Weapon
        }
        else if (auto armor = dynamic_cast<Armor*>(item.get())) {
            addItem(std::make_unique<Armor>(*armor));  // Copie l'objet Armor
        }
    }
}
