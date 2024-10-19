#pragma once
#include <string>
#include "Element.h" 
#include "Rarity.h"

class Item {
protected:
    std::string name;
    int weight;
    Rarity rarity;
    std::string description;

public:
    Item(std::string name, int weight, Rarity rarity, std::string description)
        : name(name), weight(weight), rarity(rarity), description(description) {}

    virtual std::string getName() const { return name; }
    virtual std::string getType() const = 0;
    virtual int getStat() const = 0;
    virtual int getAttack() const = 0;
    virtual int getDefense() const = 0;
    virtual Element getElement() const = 0;

    int getWeight() const { return weight; }
    Rarity getRarity() const { return rarity; }
    std::string getDescription() const { return description; }
};
