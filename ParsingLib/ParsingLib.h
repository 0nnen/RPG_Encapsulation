#pragma once
#include <vector>
#include <string>
#include <memory>
#include "Item.h"
#include "Element.h"
#include "Rarity.h"

class ParsingLib {
public:
    // Récupère les objets à partir du fichier InventoryList.txt
    static std::vector<std::unique_ptr<Item>> parseInventoryFile(const std::string& filePath);

private:
    static Element parseElement(const std::string& elementStr);
    static Rarity parseRarity(const std::string& rarityStr);
};