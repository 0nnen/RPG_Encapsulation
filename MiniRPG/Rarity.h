#pragma once
#include <string> 

enum class Rarity {
    Common,
    Uncommon,
    Rare,
    Epic
};

std::string rarityToString(Rarity rarity);