#pragma once
#include <cstdlib>
#include <ctime>
#include "Character.h"
#include "ParsingLib.h"
#include "Menu.h"

class Character;

class Combat {
public:
    static void engage(Character& character1, Character& character2);
};
