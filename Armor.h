#pragma once
#include "Item.h"
#include "Weapon.h"

class Armor : public Item {
private:
    int defense;  // D�fense physique de l'armure
    Element element;  // �l�ment de r�sistance de l'armure

public:
    Armor(std::string name, int defense, Element element = Element::None);

    int getDefense() const;
    Element getElement() const;
    std::string getType() const override;
};
