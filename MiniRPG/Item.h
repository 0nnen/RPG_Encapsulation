#pragma once
#include <string>
#include "Element.h" 

class Item {
protected:
    std::string name;

public:
    Item(std::string name) : name(name) {}

    virtual std::string getName() const { return name; }
    virtual std::string getType() const = 0;

    virtual int getAttack() const = 0;
    virtual int getDefense() const = 0;
    virtual Element getElement() const = 0;
};
