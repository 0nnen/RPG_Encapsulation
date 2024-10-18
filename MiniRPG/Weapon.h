#pragma once 
#include "Item.h"
#include <iostream>
#include "Element.h" 

class Weapon : public Item {
private:
    int damage;
    bool isTwoHanded;
    Element element;

public:
    Weapon(std::string name, int damage, bool isTwoHanded, Element element = Element::None)
        : Item(name), damage(damage), isTwoHanded(isTwoHanded), element(element) {}

    // Renaming this method to getDamage to match Character.cpp
    int getDamage() const { return damage; } // Cela reste pour l'utilisation que vous en faites

    // Redéfinition de getAttack()
    int getAttack() const override { return damage; }  // Ajoutez cette ligne pour implémenter la méthode pure

    int getDefense() const override { return 0; }

    bool getIsTwoHanded() const { return isTwoHanded; }
    Element getElement() const override { return element; }

    std::string getType() const override { return "Weapon"; }
};
