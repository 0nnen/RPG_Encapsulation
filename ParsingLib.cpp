#include "ParsingLib.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "Weapon.h"
#include "Armor.h"

std::vector<std::unique_ptr<Item>> ParsingLib::parseInventoryFile(const std::string& filePath) {
    std::vector<std::unique_ptr<Item>> items;
    std::ifstream file(filePath);

    if (!file.is_open()) {
        std::cerr << "Erreur: Impossible d'ouvrir le fichier " << filePath << std::endl;
        return items;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;  // Ignorer les lignes vides ou les commentaires

        std::stringstream ss(line);
        std::string name, type, statStr, elementStr, classStr;

        std::getline(ss, name, ';');
        std::getline(ss, type, ';');
        std::getline(ss, statStr, ';');
        std::getline(ss, elementStr, ';');
        std::getline(ss, classStr, ';');  // Ici, on lit l'argument mais on ne l'utilise pas

        int stat = std::stoi(statStr);
        Element element = Element::None;

        if (elementStr == "Fire") element = Element::Fire;
        else if (elementStr == "Ice") element = Element::Ice;
        else if (elementStr == "Divine") element = Element::Divine;
        else if (elementStr == "Poison") element = Element::Poison;
        else if (elementStr == "Dark") element = Element::Dark;

        if (type == "Weapon") {
            // Passe uniquement 4 arguments au constructeur de Weapon
            items.push_back(std::make_unique<Weapon>(name, stat, false, element));  
        } 
        else if (type == "Armor") {
            // Passe uniquement 3 arguments au constructeur de Armor
            items.push_back(std::make_unique<Armor>(name, stat, element));  
        }
    }

    file.close();
    return items;
}
