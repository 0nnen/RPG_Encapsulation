#include "Inventory.h"
#include <fstream>
#include <sstream>

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

void Inventory::loadInventoryFromFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Erreur: Impossible d'ouvrir le fichier " << filePath << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;  // Ignorer les lignes vides ou les commentaires

        std::stringstream ss(line);
        std::string name, type, statStr, elementStr;

        std::getline(ss, name, ';');
        std::getline(ss, type, ';');
        std::getline(ss, statStr, ';');
        std::getline(ss, elementStr, ';');

        int stat = std::stoi(statStr);
        Element element = Element::None;
        if (elementStr == "Fire") element = Element::Fire;
        else if (elementStr == "Ice") element = Element::Ice;
        else if (elementStr == "Divine") element = Element::Divine;
        else if (elementStr == "Poison") element = Element::Poison;
        else if (elementStr == "Dark") element = Element::Dark;

        if (type == "Weapon") {
            addItem(std::make_unique<Weapon>(name, stat, false, element));
        }
        else if (type == "Armor") {
            addItem(std::make_unique<Armor>(name, stat, element));
        }
    }

    file.close();
}
