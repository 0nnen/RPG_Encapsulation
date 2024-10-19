#pragma once
#include <vector>
#include <string>
#include <memory>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Class.h"
#include "Skill.h"
#include "Weapon.h"
#include "Armor.h"
#include "Element.h"

class ParsingLib {
public:
    // R�cup�re les objets � partir du fichier InventoryList.txt
    static std::vector<std::unique_ptr<Item>> parseInventoryFile(const std::string& filePath);

    // R�cup�re les classes et comp�tences � partir du fichier ClassList.txt
    static std::vector<Class> parseClassFile(const std::string& filePath);

private:
    static Element parseElement(const std::string& elementStr);
    static Rarity parseRarity(const std::string& rarityStr);
};
