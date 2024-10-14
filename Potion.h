#pragma once
#include "Item.h"

class Potion : public Item {
private:
    int healingAmount;

public:
    Potion(std::string name, int healingAmount)
        : Item(name), healingAmount(healingAmount) {}

    int getHealingAmount() const { return healingAmount; }
    std::string getType() const override;
};
