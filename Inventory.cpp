#include "Inventory.h"

void Inventory::addItem(std::unique_ptr<Item> item) {
    items.push_back(std::move(item));  // Transfert de propriété du pointeur
}

Item* Inventory::getItem(int index) {
    if (index >= 0 && index < items.size()) {
        return items[index].get();  // Accès direct à l'item via .get()
    }
    return nullptr;
}

void Inventory::displayInventory() const {
    for (const auto& item : items) {
        std::cout << "Item: " << item->getName() << " (" << item->getType() << ")\n";
    }
}