#pragma once
#include "Item.h"
#include <iostream>

enum class Element {
    None,
    Fire,
    Ice,
    Poison,
    Divine,
    Dark
};

// Surcharge de l'opérateur << pour Element
inline std::ostream& operator<<(std::ostream& os, const Element& element) {
    switch (element) {
    case Element::None: os << "Aucun"; break;
    case Element::Fire: os << "Feu"; break;
    case Element::Ice: os << "Glace"; break;
    case Element::Poison: os << "Poison"; break;
    case Element::Divine: os << "Divin"; break;
    case Element::Dark: os << "Tenebres"; break;
    }
    return os;
}

class Weapon : public Item {
private:
    int damage;
    bool isTwoHanded;
    Element element;

public:
    Weapon(std::string name, int damage, bool isTwoHanded, Element element = Element::None)
        : Item(name), damage(damage), isTwoHanded(isTwoHanded), element(element) {}

    int getDamage() const { return damage; };
    bool getIsTwoHanded() const { return isTwoHanded; };
    Element getElement() const { return element; }
    std::string getName() const { return name; };
    std::string getType() const override { return "Weapon"; }
};