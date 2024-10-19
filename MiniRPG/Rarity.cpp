#include "Rarity.h"

std::string rarityToString(Rarity rarity) {
    switch (rarity) {
    case Rarity::Common: return "Commun";
    case Rarity::Uncommon: return "Peu Commun";
    case Rarity::Rare: return "Rare";
    case Rarity::Epic: return "Epic";
    default: return "Unknown";
    }
}
