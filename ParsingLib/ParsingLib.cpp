#include "ParsingLib.h"


std::vector<std::unique_ptr<Item>> ParsingLib::parseInventoryFile(const std::string& filePath) {
    std::vector<std::unique_ptr<Item>> items;
    std::ifstream file(filePath);

    if (!file.is_open()) {
        std::cerr << "Erreur: Impossible d'ouvrir le fichier " << filePath << std::endl;
        return items;
    }

    std::string line;
    std::getline(file, line); // Lire la premiere ligne pour obtenir le format

    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;  // Ignorer les lignes vides ou les commentaires

        std::stringstream ss(line);
        std::string name, type, statStr, elementStr, weightStr, rarityStr, description;

        std::getline(ss, name, ';');
        std::getline(ss, type, ';');
        std::getline(ss, statStr, ';');
        std::getline(ss, elementStr, ';');
        std::getline(ss, weightStr, ';');
        std::getline(ss, rarityStr, ';');
        std::getline(ss, description, ';');

        int stat = std::stoi(statStr);
        int weight = std::stoi(weightStr);
        Rarity rarity = parseRarity(rarityStr);
        Element element = parseElement(elementStr);

        if (type == "Weapon") {
            items.push_back(std::make_unique<Weapon>(name, stat, weight, element, rarity, description));
        }
        else if (type == "Armor") {
            items.push_back(std::make_unique<Armor>(name, stat, weight, element, rarity, description));
        }
    }

    file.close();
    return items;
}

std::vector<Class> ParsingLib::parseClassFile(const std::string& filePath) {
    std::vector<Class> classes;
    std::ifstream file(filePath);

    if (!file.is_open()) {
        std::cerr << "Erreur: Impossible d'ouvrir le fichier " << filePath << std::endl;
        return classes;
    }

    std::string line;
    std::getline(file, line); // Lire la premiere ligne pour obtenir le format

    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;  // Ignorer les lignes vides ou les commentaires

        std::stringstream ss(line);
        std::string className, skillName, damageStr, staminaCostStr, isElementalStr, isHealingStr, isBuffAttackStr, isBuffDefenseStr;

        std::getline(ss, className, ';');
        std::getline(ss, skillName, ';');
        std::getline(ss, damageStr, ';');
        std::getline(ss, staminaCostStr, ';');
        std::getline(ss, isElementalStr, ';');
        std::getline(ss, isHealingStr, ';');
        std::getline(ss, isBuffAttackStr, ';');
        std::getline(ss, isBuffDefenseStr, ';');

        int damage = std::stoi(damageStr);
        int staminaCost = std::stoi(staminaCostStr);
        bool isElemental = (isElementalStr == "true");
        bool isHealing = (isHealingStr == "true");
        bool isBuffAttack = (isBuffAttackStr == "true");
        bool isBuffDefense = (isBuffDefenseStr == "true");

        Skill skill(skillName, damage, staminaCost, isElemental, isHealing, isBuffAttack, isBuffDefense);

        // Rechercher si la classe existe déjà
        auto it = std::find_if(classes.begin(), classes.end(), [&](const Class& c) { return c.getName() == className; });
        if (it != classes.end()) {
            it->addSkill(skill);
        }
        else {
            Class newClass(className);
            newClass.addSkill(skill);
            classes.push_back(newClass);
        }
    }

    file.close();
    return classes;
}

Element ParsingLib::parseElement(const std::string& elementStr) {
    if (elementStr == "Fire") return Element::Fire;
    else if (elementStr == "Ice") return Element::Ice;
    else if (elementStr == "Divine") return Element::Divine;
    else if (elementStr == "Poison") return Element::Poison;
    else if (elementStr == "Dark") return Element::Dark;
    return Element::None;
}

Rarity ParsingLib::parseRarity(const std::string& rarityStr) {
    if (rarityStr == "Common") return Rarity::Common;
    else if (rarityStr == "Uncommon") return Rarity::Uncommon;
    else if (rarityStr == "Rare") return Rarity::Rare;
    else if (rarityStr == "Epic") return Rarity::Epic;
    return Rarity::Common;
}