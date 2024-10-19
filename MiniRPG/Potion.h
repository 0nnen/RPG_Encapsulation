#pragma once
#include "Item.h"
#include "Rarity.h"

class Potion : public Item {
private:
    int healingAmount;

public:
    Potion(std::string name, int healingAmount, int weight, Rarity rarity, std::string description)
        : Item(name, weight, rarity, description), healingAmount(healingAmount) {}

    int getStat() const override { return healingAmount; }
    int getAttack() const override { return 0; }
    int getHealingAmount() const { return healingAmount; }
    Element getElement() const override { return Element::None; }
    std::string getType() const override { return "Potion"; }
};
