#pragma once
#include <iostream>
#include <string>

enum class Element {
    None,
    Fire,
    Ice,
    Poison,
    Divine,
    Dark
};

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

inline Element fromString(const std::string& str) {
    if (str == "None") return Element::None;
    if (str == "Fire") return Element::Fire;
    if (str == "Ice") return Element::Ice;
    if (str == "Poison") return Element::Poison;
    if (str == "Divine") return Element::Divine;
    if (str == "Dark") return Element::Dark;
    return Element::None;
}
