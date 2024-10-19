#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include "Inv.h"
#include "Class.h"
#include "Weapon.h"
#include "Armor.h"
#include "Combat.h"
#include "Skill.h"
#include "StatusEffect.h"

class Character {
private:
    std::string name;
    std::string className;
    int health;
    int maxHealth;
    int defense;
    int defenseBuff;
    int attackBuff;
    int stamina;
    int maxStamina;
    int evadeChance;
    bool synergyDetected;
    Weapon* mainWeapon;
    Armor* armor;
    std::vector<Skill> skills;
    InventoryLib inventory;

public:
    Character(std::string name, const std::string& className);

    // Getters and setters for encapsulation
    InventoryLib& getInventory() { return inventory; }
    int getHealth() const { return health; }
    int getMaxHealth() const { return maxHealth; }
    int getStamina() const { return stamina; }
    int getMaxStamina() const { return maxStamina; }
    int getDefense() const { return defense + defenseBuff; }
    int getDefenseBuff() const { return defenseBuff; }
    int getAttackBuff() const { return attackBuff; }
    int getEvadeChance() const { return evadeChance; }
    std::vector<Skill> getSkills() const { return skills; }
    std::string getName() const { return name; }
    std::string getClassName() const { return className; }
    void setHealth(int health);
    void setStamina(int stamina);

    // Methods to manage equipment and inventory
    void equipWeapon(Weapon* weapon);
    void equipArmor(Armor* armor);
    void addSkill(Skill skill);

    // Combat methods
    void takeDamage(int damage);
    bool isAlive() const;
    void useSkill(Character& opponent, int skillIndex);
    void attack(Character& opponent);
    bool hasElementalSynergy() const;
    Element getWeaponElement() const;

    void increaseDefense(int amount);
    void increaseAttack(int amount);
    void increaseEvadeChance(int amount);

    // Status effect management
    StatusEffect getStatusEffectFromSynergy() const;
    void applyStatusEffect(StatusEffect statusEffect);

    // Display character info
    void displayCharacterInfo() const;

    void initializeSkills(const std::vector<Class>& classes);
};