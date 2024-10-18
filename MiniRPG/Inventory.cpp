//#include "Inventory.h"
//#include "Item.h"
//#include "Weapon.h"
//#include "Armor.h"
//#include <iostream>
//
//void Inventory::addItem(std::unique_ptr<Item> item) {
//    items.push_back(std::move(item));
//}
//
//Item* Inventory::getItem(int index) {
//    if (index >= 0 && index < items.size()) {
//        return items[index].get();
//    }
//    return nullptr;
//}
//
//// Méthode pour afficher uniquement les armes ou armures de l'inventaire
//void Inventory::displayInventoryByType(const std::string& type) const {
//    bool headerShown = false;
//
//    for (size_t i = 0; i < items.size(); ++i) {
//        const auto& item = items[i];
//        if (item->getType() == type) {
//            if (!headerShown) {
//                std::cout << "\n\t\t=== " << (type == "Weapon" ? "ARMES" : "ARMURES") << " ===\n";
//                headerShown = true;
//            }
//            std::cout << "ID: " << i << " - " << item->getName() << " (" << item->getType() << ")\n";
//        }
//    }
//}
//
//void Inventory::displayInventory() const {
//    bool weaponsShown = false;
//    bool armorsShown = false;
//    bool potionsShown = false;
//
//    for (size_t i = 0; i < items.size(); ++i) {
//        const auto& item = items[i];
//        if (item->getType() == "Weapon" && !weaponsShown) {
//            std::cout << "\n\t\t=== ARMES ===\n";
//            weaponsShown = true;
//        }
//        if (item->getType() == "Armor" && !armorsShown) {
//            std::cout << "\n\t\t=== ARMURES ===\n";
//            armorsShown = true;
//        }
//        if (item->getType() == "Potion" && !potionsShown) {
//            std::cout << "\n=== POTIONS ===\n";
//            potionsShown = true;
//        }
//        std::cout << "ID: " << i << "\t" << item->getName() << " (" << item->getType() << ")\n";
//    }
//}
//
//// Ajoute les objets à l'inventaire
//void Inventory::addItemsFromList(const std::vector<std::unique_ptr<Item>>& allItems) {
//    for (const auto& item : allItems) {
//        // Ajoute une copie de l'objet en vérifiant s'il s'agit d'une arme ou d'une armure
//        if (auto weapon = dynamic_cast<Weapon*>(item.get())) {
//            addItem(std::make_unique<Weapon>(*weapon));  // Copie l'objet Weapon
//        }
//        else if (auto armor = dynamic_cast<Armor*>(item.get())) {
//            addItem(std::make_unique<Armor>(*armor));  // Copie l'objet Armor
//        }
//    }
//}
