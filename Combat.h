#pragma once
#include "Character.h"

ClassType getRandomClassType();

class Combat {
public:
    static void engage(Character& character1, Character& character2);
};
