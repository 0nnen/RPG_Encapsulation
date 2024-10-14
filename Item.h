#pragma once
#include <string>

class Item {
protected:
    std::string name;

public:
    Item(std::string name) : name(name) {}
    virtual ~Item() {}

    virtual std::string getName() const { return name; }
    virtual std::string getType() const = 0;  // Méthode virtuelle pour obtenir le type de l'objet (arme, armure, potion)
};
