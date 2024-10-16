#pragma once
#include <vector>
#include <string>
#include <memory>
#include "Item.h"

class ParsingLib {
public:
    // R�cup�re les objets � partir du fichier InventoryList.txt
    static std::vector<std::unique_ptr<Item>> parseInventoryFile(const std::string& filePath);
};
