#include "ParsingLib.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "Weapon.h"
#include "Armor.h"
#include "Character.h"

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
        std::getline(ss, classStr, ';');

        int stat = std::stoi(statStr);
        Element element = Element::None;
        if (elementStr == "Fire") element = Element::Fire;
        else if (elementStr == "Ice") element = Element::Ice;
        else if (elementStr == "Divine") element = Element::Divine;
        else if (elementStr == "Poison") element = Element::Poison;
        else if (elementStr == "Dark") element = Element::Dark;

        // Parse classes
        std::vector<ClassType> usableClasses;
        std::stringstream classStream(classStr);
        std::string classToken;
        while (std::getline(classStream, classToken, ',')) {
            if (classToken == "Warrior") usableClasses.push_back(ClassType::Warrior);
            else if (classToken == "Mage") usableClasses.push_back(ClassType::Mage);
            else if (classToken == "Knight") usableClasses.push_back(ClassType::Knight);
            else if (classToken == "Assassin") usableClasses.push_back(ClassType::Assassin);
            else if (classToken == "Berserker") usableClasses.push_back(ClassType::Berserker);
            else if (classToken == "Paladin") usableClasses.push_back(ClassType::Paladin);
            else if (classToken == "Ranger") usableClasses.push_back(ClassType::Ranger);
            else if (classToken == "Necromancer") usableClasses.push_back(ClassType::Necromancer);
        }

        if (type == "Weapon") {
            items.push_back(std::make_unique<Weapon>(name, stat, false, element, usableClasses));
        }
        else if (type == "Armor") {
            items.push_back(std::make_unique<Armor>(name, stat, element, usableClasses));
        }
    }

    file.close();
    return items;
}
